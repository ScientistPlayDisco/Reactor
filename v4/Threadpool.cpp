// Authors: Handling
// Created by 60263 on 2020/10/17.
// This is 

#include "Threadpool.h"
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;
namespace wd {
Threadpool::Threadpool(size_t threadNum, size_t queSize) : _threadNum(threadNum),
                                                           _queSize(queSize),
                                                           _taskQueue(_queSize),
                                                           _isExit(false){
  _threads.reserve(threadNum);
}
Threadpool::~Threadpool() {
  if(_isExit){
    stop();
  }
}

void Threadpool::start() {
  for (int kI = 0; kI < _threadNum; ++kI) {
    unique_ptr<Thread> up(new Thread(std::bind(&Threadpool::threadFunc,this),std::to_string(kI)));
    _threads.push_back(std::move(up));
  }
  for(auto &pthread:_threads){
    pthread->start();
  }
}


void Threadpool::stop() {
  if(!_isExit){
    while(!_taskQueue.empty()){
      cout<<"!empty"<<endl;
      ::sleep(1);
    }
    _isExit = true;
    _taskQueue.wakeup();
    cout<<"size of _threads "<<_threads.size()<<endl;
    for(auto & pthread: _threads){
      cout<<"void Threadpool::stop()"<<endl;
      pthread->join();
    }
  }
}



void Threadpool::addTask(Task && task)
{
  _taskQueue.push(std::move(task));
}

Task Threadpool::getTask()
{
  return _taskQueue.pop();

}

void Threadpool::threadFunc()//要交给农民工兄弟做的事儿
{
  while(!_isExit) {
    Task task = getTask();
    if(task)
      task();
  }
}
}//end of namespace wd