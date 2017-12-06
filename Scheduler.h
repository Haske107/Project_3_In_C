//
// Created by Jeffrey Haskell on 12/5/17.
//

#ifndef PROJECT_3_SCHEDULER_H
#define PROJECT_3_SCHEDULER_H


#include "Worker.h"
#include "Semaphore.h"

class Scheduler {

    Scheduler(
        int Program_Counter,
        int Worker1_Counter,
        int Worker2_Counter,
        int Worker4_Counter,
        int Worker16_Counter,
        int Worker1_Overrun,
        int Worker2_Overrun,
        int Worker4_Overrun,
        int Worker16_Overrun,
        Semaphore Worker1_Semaphore,
        Semaphore Worker2_Semaphore,
        Semaphore Worker4_Semaphore,
        Semaphore Worker16_Semaphore,
        Worker W1,
        Worker W2,
        Worker W4,
        Worker W16
    )   {
        this->Program_Counter = Program_Counter;
        this->Scheduler_Semaphore = Scheduler_Semaphore;
        this->Worker1_Counter = Worker1_Counter;
        this->Worker2_Counter = Worker2_Counter;
        this->Worker4_Counter = Worker4_Counter;
        this->Worker16_Counter = Worker16_Counter;
        this->Worker1_Overrun = Worker1_Overrun;
        this->Worker2_Overrun = Worker2_Overrun;
        this->Worker4_Overrun = Worker4_Overrun;
        this->Worker16_Overrun = Worker16_Overrun;
        this->Worker1_Semaphore = Worker1_Semaphore;
        this->Worker2_Semaphore = Worker2_Semaphore;
        this->Worker4_Semaphore = Worker4_Semaphore;
        this->Worker16_Semaphore = Worker16_Semaphore;
        this->W1 = W1;
        this->W2 = W2;
        this->W4 = W4;
        this->W16 = W16;

    }

    // PROGRAM COUNTER
    int Program_Counter;

    // COUNTERS
    int Worker1_Counter;
    int Worker2_Counter;
    int Worker4_Counter;
    int Worker16_Counter;

    // OVERRUN COUNTERS
    int Worker1_Overrun;
    int Worker2_Overrun;
    int Worker4_Overrun;
    int Worker16_Overrun;

    // TIMED SEMAPHORE
     Semaphore Scheduler_Semaphore = ;

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

    void runSimulation()    {
        for(int i = 0; i < 160; ++i) {
            runPeriod();
        }
    }

    void runPeriod()    {
        Scheduler_Semaphore.wait();
        Worker_Period(W1,Worker1_Semaphore,Worker1_Overrun, Worker1_Counter);
        if (Program_Counter % 2 == 0 ) Worker_Period(W2,Worker2_Semaphore,Worker2_Overrun, Worker2_Counter);
        if (Program_Counter % 4 == 0 ) Worker_Period(W4,Worker4_Semaphore,Worker4_Overrun, Worker4_Counter);
        if (Program_Counter % 16 == 0 )Worker_Period(W16,Worker16_Semaphore,Worker16_Overrun, Worker16_Counter);
        Program_Counter++;
    }


    void Worker_Period(Worker worker, Semaphore semaphore, int OverrunCounter, int ProgramCounter)   {
        if(!worker.isAlive())   {
           worker.run();
        }
        if (ProgramCounter != 0) {
            OverrunCounter++;
        }
        semaphore.notify();
    }
};


#endif //PROJECT_3_SCHEDULER_H
