// Authors: Handling
// Created by 60263 on 2020/10/17.
// This is 

#ifndef OO_THREADPOOL__THREADPOOL_H_
#define OO_THREADPOOL__THREADPOOL_H_
#include "TaskQueue.h"
#include "Task.h"
#include "Thread.h"

#include <vector>
#include <memory>
using std::vector;
using std::unique_ptr;
namespace wd {

class Threadpool {
  friend class WorkerThread;
 public:
  Threadpool(size_t threadNum, size_t queSize);
  ~Threadpool();

  void start();
  void stop();
  void addTask(Task && task);

 private:
  size_t _threadNum;
  size_t _queSize;
  TaskQueue _taskQueue;
  vector<unique_ptr<Thread>> _threads;
  bool _isExit;

 private:
  Task getTask();
  void threadFunc();//要交给农民工兄弟做的事儿
};

}
#endif //OO_THREADPOOL__THREADPOOL_H_
