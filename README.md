CPU scheduling is a vital function of a computer's operating system.  It determines which process or task uses the CPU at a given time.  There are two types of scheduling: preemptive 
and non-preemptive.  With non-preemptive scheduling, a process that is currently using the CPU cannot be interrupted.  The process has to reach completion before it can be removed
from the CPU.  With preemptive scheduling, a process that is currently using the CPU can be interrupted by another process of higher priority.  In this case, the current process is removed, and
the process that has higher priority is assigned to the CPU.  The process that was removed can be resumed after the completion of the interrupting process. 

The c++ program will simulate Real-Time-Scheduling.  This type of scheduling is generally preemptive and is used for time-critical systems.  These are systems in which a task has to complete its execution 
before a deadline.  A real-world example of a time-critical system is the ABS on a car.  During a skid, the ABS must quickly send signals to certain hydraulic valves.  If this is not done within a certain
time frame, an accident may occur.  

Three algorithms will be used to implement Real-Time Scheduling.  These are Rate Monotonic Scheduling (RMS), Deadline Monotonic Scheduling (DMS), and Earliest Deadline
First (EDF) scheduling.  

Five processes will be used.  Here is a table:

| Process No. |  Execution Time |  Relative Deadline |  Period |
|-------------|-----------------|--------------------|---------|
| 0           |  5              |  8                 |  10     |
| 1           |  2              |  28                |  34     |
| 2           |  2              |  30                |  33     |
| 3           |  5              |  13                |  30     |
| 4           |  3              |  12                |  17     |

Execution Time is the time needed for a process to complete its execution during each cycle.  Relative Deadline is the amount of time between a task's arrival at the CPU
and its deadline.  Period is the time between the operating system's requests for the execution of a given process.

Other Terminology:

Service time: The total amount of time that a process is scheduled to run.
Deadline: The sum of the arrival time and the relative deadline.

First, Earliest Deadline First (EDF) scheduling will be used.  With this type of scheduling, the process that has the earliest deadline will be prioritized.
At the start of the program (for each of the three algorithms), all processes arrive at the CPU simultaneously at a CPU time of 0 units.

Results of EDF (printout to the console):

**Process 0 starts at 0 units.**
**Current deadline of process 0 is 8.**

**Process 0 complete at 5 units.**

**Process 4 starts at 5 units.**
**Current deadline of process 4 is 12.**

**Process 4 complete at 8 units.**

**Process 3 starts at 8 units.**
**Current deadline of process 3 is 13.**

**Process 3 complete at 13 units.**

**Process 0 starts at 13 units.**
**Current deadline of process 0 is 18.**

**Process 0 has reached the limit of its run time at time 14.**

**Process 1 starts at 14 units.**
**Current deadline of process 1 is 28.**

**Process 1 complete at 16 units.**

**Process 2 starts at 16 units.**
**Current deadline of process 2 is 30.**

**Process 4 starts at 17 units.**
**Current deadline of process 4 is 29.**

**Process 4 has reached the limit of its run time at time 20.**

**Process 2 complete at 21 units.**

**Process 3 starts at 30 units.**
**Current deadline of process 3 is 43.**

**Process 3 has reached the limit of its run time at time 31.**

**Process 2 starts at 33 units.**
**Current deadline of process 2 is 63.**

**Process 1 starts at 34 units.**
**Current deadline of process 1 is 62.**

**Process 1 complete at 36 units.**

**Process 2 complete at 37 units.**

**Process 2 starts at 66 units.**
**Current deadline of process 2 is 96.**

**Process 2 has reached the limit of its run time at time 68.**

**Process 1 starts at 68 units.**
**Current deadline of process 1 is 96.**

**Process 1 has reached the limit of its run time at time 70.**

**EDF Results:**

**Service time = 6 units per process.**

**CPU time took 70 units.  All deadlines met.**

**Program complete at 70 units.**

With EDF scheduling, all deadlines were met.  

Next, Rate Monotonic Scheduling (RMS) will be used.  With this type of scheduling, shorter periods have higher priority.

RMS results:

**Process 0 starts at 0 units.**
**Current deadline of process 0 is 8.**

**Process 0 complete at 5 units.**

**Process 4 starts at 5 units.**
**Current deadline of process 4 is 12.**

**Process 4 complete at 8 units.**

**Process 3 starts at 8 units.**
**Current deadline of process 3 is 13.**

**Process 0 starts at 10 units.**
**Current deadline of process 0 is 18.**

**Process 0 has reached the limit of its run time at time 11.**

**Process 3 complete at 14 units.**

**Process 2 starts at 14 units.**
**Current deadline of process 2 is 30.**

**Process 2 complete at 16 units.**

**Process 1 starts at 16 units.**
**Current deadline of process 1 is 28.**

**Process 4 starts at 17 units.**
**Current deadline of process 4 is 29.**

**Process 4 has reached the limit of its run time at time 20.**

**Process 1 complete at 21 units.**

**Process 3 starts at 30 units.**
**Current deadline of process 3 is 43.**

**Process 3 has reached the limit of its run time at time 31.**

**Process 2 starts at 33 units.**
**Current deadline of process 2 is 63.**

**Process 2 complete at 35 units.**

**Process 1 starts at 35 units.**
**Current deadline of process 1 is 62.**

**Process 1 complete at 37 units.**

**Process 2 starts at 66 units.**
**Current deadline of process 2 is 96.**

**Process 2 has reached the limit of its run time at time 68.**

**Process 1 starts at 68 units.**
**Current deadline of process 1 is 96.**

**Process 1 has reached the limit of its run time at time 70.**

**RMS Results:**

**Service time = 6 units per process.**

**Schedule feasible from 0 to 13 units.  Process 3 did not meet deadline of 13 units.  Process 3 complete at 14 units.**

**Program complete at 70 units.**

With RMS, all deadlines were not met.  The processes are not schedulable with this algorithm.  

Last, Deadline Monotonic Scheduling (DMS) will be used.  With DMS, tasks with the shortest relative deadlines are 
given the highest priority.

DMS results:

**Process 0 starts at 0 units.**
**Current deadline of process 0 is 8.**

**Process 0 complete at 5 units.**

**Process 4 starts at 5 units.**
**Current deadline of process 4 is 12.**

**Process 4 complete at 8 units.**

**Process 3 starts at 8 units.**
**Current deadline of process 3 is 13.**

**Process 0 starts at 10 units.**
**Current deadline of process 0 is 18.**

**Process 0 has reached the limit of its run time at time 11.**

**Process 3 complete at 14 units.**

**Process 1 starts at 14 units.**
**Current deadline of process 1 is 28.**

**Process 1 complete at 16 units.**

**Process 2 starts at 16 units.**
**Current deadline of process 2 is 30.**

**Process 4 starts at 17 units.**
**Current deadline of process 4 is 29.**

**Process 4 has reached the limit of its run time at time 20.**

**Process 2 complete at 21 units.**

**Process 3 starts at 30 units.**
**Current deadline of process 3 is 43.**

**Process 3 has reached the limit of its run time at time 31.**

**Process 2 starts at 33 units.**
**Current deadline of process 2 is 63.**

**Process 1 starts at 34 units.**
**Current deadline of process 1 is 62.**

**Process 1 complete at 36 units.**

**Process 2 complete at 37 units.**

**Process 2 starts at 66 units.**
**Current deadline of process 2 is 96.**

**Process 2 has reached the limit of its run time at time 68.**

**Process 1 starts at 68 units.**
**Current deadline of process 1 is 96.**

**Process 1 has reached the limit of its run time at time 70.**

**DMS Results:**

**Service time = 6 units per process.**

**Schedule feasible from 0 to 13 units.  Process 3 did not meet deadline of 13 units.  Process 3 complete at 14 units.**

**Program complete at 70 units.**

Also, the processes are not schedulable with DMS.  

