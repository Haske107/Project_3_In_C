//
// Created by Jeffrey Haskell on 12/5/17.
//

#ifndef PROJECT_3_WORKER_H
#define PROJECT_3_WORKER_H

#include <thread>


class Worker {

 void run() {
            for (int i = 0; i < Iterations; ++i) {
                Semaphore.tryAcquire();
                for(int j = 0; j < 160 / Iterations; ++j)    {
                    doWork();
                    Worker_Counter.incrementAndGet();
                }
            }
        }
    }

 void doWork()    {
        for (int i = 0; i < 100; ++i) {
            matrix[new Random().nextInt(100)][new Random().nextInt(100)]
            = matrix[new Random().nextInt(100)][new Random().nextInt(100)] * 5.2323223586654321;
        }
    }
};


#endif //PROJECT_3_WORKER_H
