// Authors: Handling
// Created by 60263 on 2020/10/16.
// This is 

#ifndef THREADPOOL__CONDITION_H_
#define THREADPOOL__CONDITION_H_

#include "Noncopyable.h"

#include <pthread.h>

namespace wd
{

class MutexLock;

class Condition
    : Noncopyable
{
 public:
  Condition(MutexLock &);
  ~Condition();

  void wait();
  void notify();
  void notifyAll();

 private:
  pthread_cond_t _cond;
  MutexLock & _mutex;
};

}//end of namespace wd

#endif //THREADPOOL__CONDITION_H_
