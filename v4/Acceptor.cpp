// Authors: Handling
// Created by 60263 on 2020/10/20.
// This is 

#include "Acceptor.h"
#include <sys/types.h>
#include <sys/socket.h>

namespace wd {
Acceptor::Acceptor(unsigned short port)
    : _addr(port), _listenSock() {}

Acceptor::Acceptor(const string &ip, unsigned short port)
    : _addr(ip, port), _listenSock() {}
void Acceptor::setReuseAddr(bool on) {
  int one = on;
  if (setsockopt(_listenSock.fd(),
                 SOL_SOCKET,
                 SO_REUSEADDR,
                 &one,
                 sizeof(one)) < 0) {
    perror("setsockopt");
  }
}
void Acceptor::setReusePort(bool on) {
  int one = on;
  if (setsockopt(_listenSock.fd(),
                 SOL_SOCKET,
                 SO_REUSEPORT,
                 &one,
                 sizeof(one)) < 0) {
    perror("setsockopt");
  }
}
void Acceptor::bind() {
  int ret = ::bind(_listenSock.fd(),
                   (struct sockaddr *) _addr.getInetAddressPtr(),
                   sizeof(struct sockaddr));
  if (-1 == ret) {
    perror("bind");
  }
}
void Acceptor::listen() {
  int ret = ::listen(_listenSock.fd(), 10);
  if (-1 == ret) {
    perror("listen");
  }
}
int Acceptor::accept() {
  int peerfd = ::accept(_listenSock.fd(), NULL, NULL);
  if (peerfd == -1) {
    perror("accept");
  }
  return peerfd;
}
void Acceptor::ready() {
  setReuseAddr(true);
  setReusePort(true);
  bind();
  listen();
}

}