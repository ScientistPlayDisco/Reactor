// Authors: Handling
// Created by 60263 on 2020/10/20.
// This is 

#ifndef V1__ACCEPTOR_H_
#define V1__ACCEPTOR_H_
#include "InetAddress.h"
#include "Socket.h"
namespace wd {

class Acceptor {
 public:
  Acceptor(unsigned short port);
  explicit Acceptor(const string &ip, unsigned short port);
  void setReuseAddr(bool on);
  void setReusePort(bool on);
  int fd() const {  return _listenSock.fd();};
  void bind();
  void listen();
  void ready();
  int accept();
 private:
  InetAddress _addr;
  Socket _listenSock;
};
}

#endif //V1__ACCEPTOR_H_
