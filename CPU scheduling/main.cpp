#include <stdio.h>
#include <queue>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

/*For each process, the first entry is the execution time, second is the relative deadline, and 3rd is the period.
A process id is assigned to each process during program execution.

Processes{{5, 8, 10}, {2, 28, 34}, {2, 30, 33}, {5, 13, 30}, {3, 12, 17}}*/

struct Process {

    int processId;
    int deadline;
    int relativeDeadline;
    int period;
    int currentRunTime;
    int processingTime;

    Process(int processId, int processingTime, int relativeDeadline, int period, int deadline, int currentRunTime)
    {
        this->processId = processId;
        this->processingTime = processingTime;
        this->relativeDeadline = relativeDeadline;
        this->period = period;
        this->deadline = deadline;
        this->currentRunTime = currentRunTime; 
    }
};

//This program uses a priority queue and these are the comparators for each of the three methods.

struct ComparatorRMS {
    bool operator()(const Process& a, const Process& b) const {
        return a.period > b.period;
    }
};

struct ComparatorDMS {
    bool operator()(const Process& a, const Process& b) const {
        return a.relativeDeadline > b.relativeDeadline;
    }
};

struct ComparatorEDF {
    bool operator()(const Process& a, const Process& b) const {
        return a.deadline > b.deadline;
    }
};

int main()
{
    vector<vector<int>> processes;

    //Open the CSV file
    ifstream file("processes.csv");

    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 1;
    }

    string line, dummyLine;

    getline(file, dummyLine);  //Skip the header line)

    while (getline(file, line))
    {
        vector<int> process;
        stringstream ss(line);
        string value;

        while (getline(ss, value, ','))
            process.push_back(stoi(value));
           
        processes.push_back(process);
    }

    /*The priority queue is being used as a min heap for each of the 3 methods.
    This ensures that the time/interval in which each process is being executed
    is in accord with whichever of the 3 methods is currently being used*/

    priority_queue<Process, vector<Process>, ComparatorEDF> minHeap;
    int currTime = 0, serviceTime = 6, n = processes.size(), totalExecutionTime = 0;
    vector<int> serviceTimes(n, 0), deadlineMet = { true, -1, -1, -1 };
    
    while (totalExecutionTime < serviceTime * n)
    {
        /*Push processes into priority queue periodically.Stop pushing a process into the queue
        if the total time that the process has run is equal to service time.*/

        for (int id = 0; id < n; id++)
            if (currTime % processes[id][2] == 0 && serviceTimes[id] < serviceTime)
                minHeap.push(Process(id, processes[id][0], processes[id][1], processes[id][2],
                    currTime + processes[id][1], 0));

        currTime++;

        if (!minHeap.empty())
        {
            //Place the process that is at the top of the queue into main memory.

            Process process = minHeap.top();
            minHeap.pop();

            //Start of current Process

            if (process.currentRunTime == 0)
            {
                cout << "**Process " << process.processId << " starts at " << currTime - 1 << " units.**" << endl;
                cout << "**Current deadline of process " << process.processId << " is " << process.deadline << ".**" << endl << endl;
            }

            //Combined run time of all processes, exit program when all processes are done running.

            totalExecutionTime++;

            /*If the process has reached the limit of its total run time, move on to the next process
              and do not place it back into the queue.*/

            if (++serviceTimes[process.processId] == serviceTime)
            {
                cout << "**Process " << process.processId << " has reached the limit of its run time at time " <<
                    currTime << ".**" << endl << endl;
                continue;
            }

            /*Update current run time of the process that is currently occupying the frame.  Here the process
              is pushed back into the heap but logically it is not (if it is of the highest prority it will end up
              back on the frame immediately). Structuring it this way just makes the code simpler.*/

            if (++process.currentRunTime < process.processingTime)
                minHeap.push(process);

            //If a process done running in the short run.

            if (process.currentRunTime == process.processingTime)
            {
                if (currTime > process.deadline && deadlineMet[0] == true)
                {
                    //For print statement at end of program

                    deadlineMet[0] = false;
                    deadlineMet[1] = currTime;
                    deadlineMet[2] = process.processId;
                    deadlineMet[3] = process.deadline;
                }

                cout << "**Process " << process.processId << " complete at " << currTime << " units.**" << endl << endl;
            }
        }
    }

    cout << "**EDF Results:**" << endl << endl;
    cout << "**Service time = " << serviceTime << " units per process.**" << endl << endl;

    if (!deadlineMet[0])
    {
        cout << "**Schedule feasible from 0 to " << deadlineMet[3] << " units.  " <<
            "Process " << deadlineMet[2] << " did not meet deadline of " << deadlineMet[3] << " units.  ";
        cout << "Process " << deadlineMet[2] << " complete at " << deadlineMet[1] << " units.**" << endl << endl;
    }
    else
        cout << "**CPU time took " << currTime << " units.  All deadlines met.**" << endl << endl;

    cout << "**Program complete at " << currTime << " units.**";

    file.close();

    return 0;
}










