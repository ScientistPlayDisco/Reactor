// Authors: Handling
// Created by 60263 on 2020/10/22.
// This is 

#include "Eventfd.h"
#include <unistd.h>
#include <sys/eventfd.h>
#include <sys/poll.h>
namespace wd {
Eventfd::Eventfd(EventCallback &&cb) : _eventfd(creatEventfd()),
                                       _cb(std::move(cb)),
                                       _isStarted(false) {

}
void Eventfd::start() {
  _isStarted = true;

  struct pollfd PollFd;
  PollFd.fd = _eventfd;
  PollFd.events = POLLIN;

  while (_isStarted) {
    int nready = ::poll(&PollFd, 1, 5000);
    if (nready == -1 && errno == EINTR) {
      continue;
    } else if (nready == -1) {
      perror("poll");
      return;
    } else if (nready == 0) {
      printf("poll timeout\n");
    } else {
      if (PollFd.revents && POLLIN) {
        handlRead();
        if (_cb) {
          _cb();
        }
      }
    }

  }
}

void Eventfd::stop() {
  if (_isStarted) {
    _isStarted = false;
  }
}

void Eventfd::wakeup() const {
  uint64_t one = 1;
  int ret = ::write(_eventfd, &one, sizeof(one));
  if (ret != sizeof(one)) {
    perror("write");
  }
}

void Eventfd::handlRead() const {
  uint64_t howMany = 0;
  int ret = ::read(_eventfd, &howMany, sizeof(howMany));
  if (ret != sizeof(howMany)) {
    perror("read");
  }
}

int Eventfd::creatEventfd() {
  int ret = ::eventfd(0, 0);
  if (ret < 0) {
    perror("eventfd");
  }

  return ret;
}
}//end of namespace wd