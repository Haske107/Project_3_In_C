#include <iostream>
#include "Worker.h"
#include "Semaphore.h"

using namespace std;


int main() {

    // PROGRAM COUNTER
    int Program_Counter = 0;

    // COUNTERS
    int Worker1_Counter = 0;
    int Worker2_Counter = 0;
    int Worker4_Counter = 0;
    int Worker16_Counter = 0;

    // OVERRUN COUNTERS
    int Worker1_Overrun = 0;
    int Worker2_Overrun = 0;
    int Worker4_Overrun = 0;
    int Worker16_Overrun = 0;

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

    //
  return 0;
}

