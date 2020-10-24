// Authors: Handling
// Created by 60263 on 2020/10/17.
// This is 

#include "Threadpool.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;

class Mytask {
 public:
  void process() {
    ::srand(::clock());
    int number = ::rand() % 100;
    cout << "worker thread " << pthread_self()
         << ": number " << number << endl;

    ::sleep(1);
  }
};

void test0() {
  cout << "main thread: " << pthread_self() << endl;

  wd::Threadpool threadpool(4, 10);
  // cout<<"start"<<endl;
  threadpool.start();
  //unique_ptr<wd::Task> ptask(new Mytask());
  int cnt = 20;
  while (cnt-- > 0) {
    cout << cnt << " ";
    threadpool.addTask(std::bind(&Mytask::process, Mytask()));
  }

  threadpool.stop();

}

int main() {
  test0();
  return 0;
}
