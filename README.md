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

Execution Time is the amount of time needed for a process to complete its execution.  Relative Deadline is the amount of time between a task's arrival 
and its deadline.
