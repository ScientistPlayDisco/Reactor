// Authors: Handling
// Created by 60263 on 2020/10/17.
// This is 

#ifndef OO_THREADPOOL__TASKQUEUE_H_
#define OO_THREADPOOL__TASKQUEUE_H_
#include "Condition.h"
#include "MutexLock.h"
#include <queue>
#include <memory>
#include "Task.h"
namespace wd {

using ElemType = Task;

class TaskQueue {

 public:
  explicit TaskQueue(size_t queSize);

  bool empty() const;
  bool full() const;
  void push(const ElemType &elem);
  ElemType pop();
  void wakeup();
 private:
  size_t _queSize;
  std::queue<ElemType> _que;
  MutexLock _mutex;
  Condition _notEmpty;
  Condition _notFull;
  bool _flag;
};
}

#endif //OO_THREADPOOL__TASKQUEUE_H_
