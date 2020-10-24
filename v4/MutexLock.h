// Authors: Handling
// Created by 60263 on 2020/10/16.
// This is 

#ifndef THREADPOOL__MUTEXLOCK_H_
#define THREADPOOL__MUTEXLOCK_H_

#include "Noncopyable.h"

#include <pthread.h>

namespace wd
{

class MutexLock
    : Noncopyable
{
 public:
  MutexLock();
  ~MutexLock();

  void lock();
  void unlock();

  pthread_mutex_t * getMutexLockPtr() {	return &_mutex;	}

 private:
  pthread_mutex_t _mutex{};
};

class MutexLockGuard
{
 public:
  explicit MutexLockGuard(MutexLock & mutex)
      : _mutex(mutex)
  {
    _mutex.lock();
  }

  ~MutexLockGuard()
  {	_mutex.unlock();	}

 private:
  MutexLock & _mutex;
};

}

#endif //THREADPOOL__MUTEXLOCK_H_
