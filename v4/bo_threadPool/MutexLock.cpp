// Authors: Handling
// Created by 60263 on 2020/10/16.
// This is 

#include "MutexLock.h"
#include <cstdio>

namespace wd
{
MutexLock::MutexLock()
{
  if(pthread_mutex_init(&_mutex, nullptr)) {
    perror("pthread_mutex_init");
  }
}

MutexLock::~MutexLock()
{
  if(pthread_mutex_destroy(&_mutex)) {
    perror("pthread_mutex_destroy");
  }
}

void MutexLock::lock()
{
  if(pthread_mutex_lock(&_mutex)) {
    perror("pthread_mutex_lock");
  }
}

void MutexLock::unlock()
{
  if(pthread_mutex_unlock(&_mutex)) {
    perror("pthread_mutex_unlock");
  }
}

}//end of namespace wd
