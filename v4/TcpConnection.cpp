// Authors: Handling
// Created by 60263 on 2020/10/20.
// This is 

#include "TcpConnection.h"
#include <sstream>
namespace wd {

TcpConnection::TcpConnection(int fd, Eventloop *loop)
    :
    _sock(fd),
    _loop(loop),
    _socketIo(fd),
    _localAddr(getLocalAddr(fd)),
    _peerAddr(getPeerAddr(fd)),
    _isShutdwonWrite(false) {}

TcpConnection::~TcpConnection() {
  if (!_isShutdwonWrite) {
    shutdown();
  }
}

string TcpConnection::receive() {
  char buff[65536] = {0};
  _socketIo.readline(buff, sizeof(buff));
  return string(buff);
}
void TcpConnection::send(const string &msg) {
  _socketIo.writen(msg.c_str(), msg.size());
}

string TcpConnection::toString() const {
  std::ostringstream oss;
  oss << _localAddr.ip() << ":" << _localAddr.port() << " --> "
      << _peerAddr.ip() << ":" << _peerAddr.port();
  return oss.str();
}
void TcpConnection::shutdown() {
  if (!_isShutdwonWrite) {
    _isShutdwonWrite = true;
    _sock.shutdownWrite();
  }
}

InetAddress TcpConnection::getLocalAddr(int fd) {
  struct sockaddr_in addr{};
  socklen_t len = sizeof(struct sockaddr);
  if (getsockname(_sock.fd(), (struct sockaddr *) &addr, &len) == -1) {
    perror("getsockname");
  }
  return InetAddress(addr);
}
InetAddress TcpConnection::getPeerAddr(int fd) {
  struct sockaddr_in addr{};
  socklen_t len = sizeof(struct sockaddr);
  if (getpeername(_sock.fd(), (struct sockaddr *) &addr, &len) == -1) {
    perror("getpeername");
  }
  return InetAddress(addr);
}

void TcpConnection::setConnectionCallback(const TcpConnectionCallback &cb) {
  _onConnection = cb;
}

void TcpConnection::setMessageCallback(const TcpConnectionCallback &cb) {
  _onMessage = cb;
}

void TcpConnection::setCloseCallback(const TcpConnectionCallback &cb) {
  _onClose = cb;
}
void TcpConnection::handleConnectionCallback() {
  if (_onConnection) {
    _onConnection(shared_from_this());
  }
}
void TcpConnection::handleMessageCallback() {
  if (_onMessage) {
    _onMessage(shared_from_this());
  }
}
void TcpConnection::handleCloseCallback() {
  if (_onClose) {
    _onClose(shared_from_this());
  }
}
void TcpConnection::sendInLoop(const string &msg) {
  if (_loop)
    _loop->runInLoop(std::bind(&TcpConnection::send, this, msg));
}
bool TcpConnection::isConnectionClosed() {
  int nready = -1;
  char buff[128] = {0};
  do {
    nready = ::recv(_sock.fd(), buff, sizeof(buff), MSG_PEEK);
  } while (nready == -1 && errno == EINTR);
  return nready == 0;
}

}//end of namespace wd