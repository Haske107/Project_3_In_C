//
// Created by Jeffrey Haskell on 12/5/17.
//

#ifndef PROJECT_3_SCHEDULER_H
#define PROJECT_3_SCHEDULER_H


#include "Worker.h"

class Scheduler {

    // PROGRAM COUNTER
    int Program_Counter;

    // COUNTERS
    int Worker1_Counter;
    int Worker2_Counter;
    int Worker4_Counter;
    int Worker16_Counter;

    // OVERRUN COUNTERS
    int Worker1_Overrun_Counter;
    int Worker2_Overrun_Counter;
    int Worker4_Overrun_Counter;
    int Worker16_Overrun_Counter;

    // TIMED SEMAPHORE
     Semaphore Scheduler_Semaphore;

    // WORKER SEMAPHORES
     Semaphore Worker1_Semaphore;
     Semaphore Worker2_Semaphore;
     Semaphore Worker4_Semaphore;
     Semaphore Worker16_Semaphore;

    // WORKERS
     Worker W1;
     Worker W2;
     Worker W4;
     Worker W16;



};


#endif //PROJECT_3_SCHEDULER_H
