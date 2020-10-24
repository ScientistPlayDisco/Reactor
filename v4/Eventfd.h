// Authors: Handling
// Created by 60263 on 2020/10/22.
// This is 

#ifndef V4_THREADPOOL__EVENTFD_H_
#define V4_THREADPOOL__EVENTFD_H_
#include <functional>
namespace wd {
using EventCallback = std::function<void()>;

class Eventfd {
  Eventfd(EventCallback &&cb);
  void start();
  void stop();
  void wakeup() const;

 private:
  void handlRead() const;
  int creatEventfd();

 private:
  int _eventfd;
  EventCallback _cb;
  bool _isStarted;
};
}

#endif //V4_THREADPOOL__EVENTFD_H_
