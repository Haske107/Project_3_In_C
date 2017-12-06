//
// Created by Jeffrey Haskell on 12/5/17.
//

#ifndef PROJECT_3_WORKER_H
#define PROJECT_3_WORKER_H

#include <thread>


class Worker {

    Semaphore semaphore;
    int Iterations;
    int Worker_Counter;
    int matrix[1000][1000];

public:
    Worker(Semaphore semaphore, int Iterations, int Worker_Counter){
        Iterations = Iterations;
        Worker_Counter = Worker_Counter;
        semaphore = semaphore;

    void run() {
        for (int i = 0; i < Iterations; ++i) {
            Semaphore.wait();
            for(int j = 0; j < 160 / Iterations; ++j)    {
                doWork();
                Worker_Counter.incrementAndGet();
                }
            }
        }
    }

    void doWork()    {
        for (int i = 0; i < 1000; ++i) {
            matrix[rand()%999][rand()%999]
            = matrix[rand()%999][rand()%999] * 5.2323223586654321;
        }
    }
};


#endif //PROJECT_3_WORKER_H
