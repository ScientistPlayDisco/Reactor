// Authors: Handling
// Created by 60263 on 2020/10/21.
// This is 

#ifndef V3__TCPSERVER_H_
#define V3__TCPSERVER_H_
#include "Acceptor.h"
#include "Eventloop.h"
#include "TcpConnection.h"

namespace wd {
class TcpServer {
 public:
  TcpServer(const string& ip, unsigned short port);
  void start();
  void stop();

  void setConnectionCallback(TcpConnectionCallback && cb);
  void setMessageCallback(TcpConnectionCallback && cb);
  void setCloseCallback(TcpConnectionCallback && cb);
 private:
  Acceptor acceptor_;
  Eventloop loop_;
};
}

#endif //V3__TCPSERVER_H_
