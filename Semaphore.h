//
// Created by Jeffrey Haskell on 12/5/17.
//

#ifndef PROJECT_3_SEMAPHORE_H
#define PROJECT_3_SEMAPHORE_H
#include <mutex>
#include <condition_variable>
using namespace std;

class Semaphore
{
public:

    Semaphore(int count_ = 0) : count{count_}
    {}

    void notify()
    {
        unique_lock<mutex> lck(mtx);
        ++count;
        cv.notify_one();
    }

    void wait()
    {
        unique_lock<mutex> lck(mtx);
        while(count == 0)
        {
            cv.wait(lck);
        }

        --count;
    }

private:

    mutex mtx;
    condition_variable cv;
    int count;
};
#endif //PROJECT_3_SEMAPHORE_H
