// Authors: Handling
// Created by 60263 on 2020/10/21.
// This is 

#include "Eventloop.h"
#include <cassert>
namespace wd {
Eventloop::Eventloop(Acceptor &acceptor) : _efd(createEpollfd()),
                                           _acceptor(acceptor),
                                           _evtList(1024),
                                           _isLooping(false) {
  //_evtList.reserve(1024);
  addEpollReadFd(_acceptor.fd());
}
int Eventloop::createEpollfd() {
  int ret = epoll_create1(0);
  if (ret == -1) {
    perror("epoll_create1");
  }
  return ret;
}
void Eventloop::loop() {
  _isLooping = true;
  while (_isLooping) {
    waitEpollfd();
  }
}

void Eventloop::unloop() {
  if (_isLooping) {
    _isLooping = false;
  }
}

void Eventloop::waitEpollfd() {

  int nready = 0;
  do {
    nready = epoll_wait(_efd, &_evtList[0], _evtList.size(), 5000);
  } while (nready == -1 && errno == EINTR);

  if (nready == -1) {
    perror("epoll_wait");
    return;
  } else if (nready == 0) {
    printf("epoll_wait timeout!\n");
  } else {
    if (nready == _evtList.size()) {
      _evtList.resize(2 * nready);
    }

    for (int kI = 0; kI < nready; ++kI) {
      int fd = _evtList[kI].data.fd;

      if (fd == _acceptor.fd()) {
        if (_evtList[kI].events & EPOLLIN) {
          handleNewConnection();
        }
      } else {//针对已经建立的连接
        if (_evtList[kI].events & EPOLLIN) {
          handleMessage(fd);
        }
      }
    }

  }
}

void Eventloop::addEpollReadFd(int fd) const {
  struct epoll_event value{};
  value.data.fd = fd;
  value.events = EPOLLIN;
  int ret = epoll_ctl(_efd, EPOLL_CTL_ADD, fd, &value);
  if (ret == -1) {
    perror("epoll_ctl");
  }
}

void Eventloop::delEpollReadFd(int fd) const {
  struct epoll_event value{};
  value.data.fd = fd;
  int ret = epoll_ctl(_efd, EPOLL_CTL_DEL, fd, &value);
  if (ret == -1) {
    perror("epoll_ctl");
  }
}

void Eventloop::handleNewConnection() {
  int peerfd = _acceptor.accept();

  addEpollReadFd(peerfd);

  TcpConnectionPtr conn(new TcpConnection(peerfd));//创建新连接利用智能指针托管

  //回调事件的注册
  conn->setConnectionCallback(_onConnection);
  conn->setCloseCallback(_onClose);
  conn->setMessageCallback(_onMessage);

  _conns.insert(std::make_pair(peerfd, conn));
  //..do somthing
  //——onConnection
  conn->handleConnectionCallback();
}
void Eventloop::handleMessage(int fd) {
  auto iter = _conns.find(fd);
  assert(iter != _conns.end());
  auto isClosed = iter->second->isConnectionClosed();
  //判断该链接是否断开
  if (isClosed) {

    iter->second->handleCloseCallback();
    delEpollReadFd(fd);
    _conns.erase(iter);

    //..do somthing
    //--onMessage
  } else {

    //do...somthing
    //--onClose
    iter->second->handleMessageCallback();
  }
}
}