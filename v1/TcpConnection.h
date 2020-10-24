// Authors: Handling
// Created by 60263 on 2020/10/20.
// This is 

#ifndef V1__TCPCONNECTION_H_
#define V1__TCPCONNECTION_H_
#include "Socket.h"
#include "InetAddress.h"
#include "SocketIO.h"
#include "Noncopyable.h"

namespace wd {
class TcpConnection : public Noncopyable {
 public:
  TcpConnection(int fd);
  ~TcpConnection();

  string receive();
  void send(const string &msg);

  string toString() const;
  void shutdown();
 private:
  InetAddress getLocalAddr(int fd);
  InetAddress getPeerAddr(int fd);
 private:
  Socket _sock;
  SocketIO _socketIo;
  InetAddress _localAddr;
  InetAddress _peerAddr;
  bool _isShutdwonWrite;
};
}//end of namespace wd

#endif //V1__TCPCONNECTION_H_
