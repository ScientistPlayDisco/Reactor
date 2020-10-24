// Authors: Handling
// Created by 60263 on 2020/10/21.
// This is 

#ifndef V3__EVENTLOOP_H_
#define V3__EVENTLOOP_H_
#include "Acceptor.h"
#include "TcpConnection.h"

#include <sys/epoll.h>
#include <vector>
#include <map>
using std::vector;
using std::map;

namespace wd {

using Callback = TcpConnectionCallback;
class Eventloop {
 public:
  explicit Eventloop(Acceptor &);
  void loop();
  void unloop();

  void setConnectionCallback(TcpConnectionCallback &&cb) { _onConnection = std::move(cb); };
  void setMessageCallback(TcpConnectionCallback &&cb) { _onMessage = std::move(cb); };
  void setCloseCallback(TcpConnectionCallback &&cb) { _onClose = std::move(cb); };

 private:
  int _efd;
  Acceptor &_acceptor;
  vector<struct epoll_event> _evtList;
  map<int, TcpConnectionPtr> _conns;
  bool _isLooping;

  static int createEpollfd();
  void waitEpollfd();//循环等待
  void handleNewConnection();//处理新连接
  void handleMessage(int fd);
  void addEpollReadFd(int fd) const;
  void delEpollReadFd(int fd) const;
  //为了转交给TcpConnection对象
  Callback _onMessage;
  Callback _onConnection;
  Callback _onClose;
};

}
#endif //V3__EVENTLOOP_H_
