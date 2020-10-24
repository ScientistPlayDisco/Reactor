// Authors: Handling
// Created by 60263 on 2020/10/21.
// This is
#ifndef V3__EVENTLOOP_H_
#define V3__EVENTLOOP_H_
#include "MutexLock.h"
#include <sys/epoll.h>
#include <vector>
#include <map>
#include <functional>
#include <memory>
using std::vector;
using std::map;
namespace wd {

class TcpConnection;
using TcpConnectionPtr = std::shared_ptr<TcpConnection>;
using TcpConnectionCallback = std::function<void(const TcpConnectionPtr &)>;
using Functor = std::function<void()>;

class Acceptor;
class Eventloop {
 public:
  explicit Eventloop(Acceptor &);
  void loop();
  void runInLoop(Functor &&cb);
  void unloop();

  void setConnectionCallback(TcpConnectionCallback &&cb) { _onConnection = std::move(cb); };
  void setMessageCallback(TcpConnectionCallback &&cb) { _onMessage = std::move(cb); };
  void setCloseCallback(TcpConnectionCallback &&cb) { _onClose = std::move(cb); };

 private:
  static int createEpollfd();
  void addEpollReadFd(int fd) const;
  void delEpollReadFd(int fd) const;

  void waitEpollfd();//循环等待
  void handleNewConnection();//处理新连接
  void handleMessage(int fd);

  int createEventfd();
  void handleRead() const;
  void wakeup() const;
  void doPendingFunctors();

 private:
  int _efd;
  int _eventfd;
  Acceptor &_acceptor;
  vector<struct epoll_event> _evtList;
  map<int, TcpConnectionPtr> _conns;
  bool _isLooping;

  std::vector<Functor> _pendingFunctors;
  MutexLock _mutex;

  //为了转交给TcpConnection对象
  TcpConnectionCallback _onMessage;
  TcpConnectionCallback _onConnection;
  TcpConnectionCallback _onClose;
};

}
#endif //V3__EVENTLOOP_H_
