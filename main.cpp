#include <iostream>
#include "Worker.h"
#include "Semaphore.h"
#include "Scheduler.h"
#include <pthread.h>
#include <future>
#include <chrono>

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
    int Worker1_Overrun_Counter = 0;
    int Worker2_Overrun_Counter = 0;
    int Worker4_Overrun_Counter = 0;
    int Worker16_Overrun_Counter = 0;

    // WORKER SEMAPHORES
    Semaphore worker1_sem = new Semaphore();
    // CREATE NEW WORKER THREADS
    pthread_t worker1, worker2, worker3, worker4;
    int i1, i2, i3, i4;
    pthread worker1 = thread(Worker(worker1_sem,160,Worker1_Counter));

    // SET PRIORITIES

    // TIMED SEMAPHORE

    //
  return 0;
}

