// Authors: Handling
// Created by 60263 on 2020/10/17.
// This is 
// size_t _queSize;
//  std::queue<int> _que;
//  MutexLock _mutex;
//  Condition _notEmpty;
//  Condition _notFull;
#include "TaskQueue.h"

void wakeup();
namespace wd {
TaskQueue::TaskQueue(size_t queSize) : _queSize(queSize),
                                       _que(), _mutex(), _notEmpty(_mutex), _notFull(_mutex),_flag(true) {

}
bool TaskQueue::empty() const {
  return _que.empty();
}

bool TaskQueue::full() const {
  return _que.size() == _queSize;
}

void TaskQueue::push(const ElemType &elem) {
  MutexLockGuard autoLock(_mutex);
  while (full()) {
    _notFull.wait();
  }

  _que.push(elem);

  _notEmpty.notify();
}

ElemType TaskQueue::pop() {
  MutexLockGuard autoLock(_mutex);
  while (_flag && empty()) {
    _notEmpty.wait();
  }
  if(_flag) {
    ElemType elem = _que.front();
    _que.pop();

    _notFull.notify();

    return elem;
  }else
    return nullptr;
}


void TaskQueue::wakeup(){
  _flag = false;
  _notEmpty.notifyAll();
}
}//end of namespace wd

