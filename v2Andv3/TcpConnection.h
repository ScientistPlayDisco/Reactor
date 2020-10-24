// Authors: Handling
// Created by 60263 on 2020/10/20.
// This is 

#ifndef V1__TCPCONNECTION_H_
#define V1__TCPCONNECTION_H_
#include "Socket.h"
#include "InetAddress.h"
#include "SocketIO.h"
#include "Noncopyable.h"
#include <functional>
#include <memory>

namespace wd {
class TcpConnection;
using TcpConnectionPtr = std::shared_ptr<TcpConnection>;
using TcpConnectionCallback = std::function<void(const TcpConnectionPtr &conn)>;
class TcpConnection : public Noncopyable,
                      public std::enable_shared_from_this<TcpConnection> {
 public:
  explicit TcpConnection(int fd);
  ~TcpConnection();

  string receive();
  void send(const string &msg);

  string toString() const;
  void shutdown();

  void setConnectionCallback(const TcpConnectionCallback &cb);
  void setMessageCallback(const TcpConnectionCallback &cb);
  void setCloseCallback(const TcpConnectionCallback &cb);

  void handleConnectionCallback();
  void handleMessageCallback();
  void handleCloseCallback();

  bool isConnectionClosed() {
    int nready = -1;
    char buff[128] = {0};
    do {
      nready = ::recv(_sock.fd(), buff, sizeof(buff),MSG_PEEK);
    } while (nready == -1 && errno == EINTR);
    return nready == 0;
  };
 private:
  InetAddress getLocalAddr(int fd);
  InetAddress getPeerAddr(int fd);
 private:
  Socket _sock;
  SocketIO _socketIo;
  InetAddress _localAddr;
  InetAddress _peerAddr;
  bool _isShutdwonWrite;

  TcpConnectionCallback _onConnection;
  TcpConnectionCallback _onMessage;
  TcpConnectionCallback _onClose;
};

}//end of namespace wd

#endif //V1__TCPCONNECTION_H_
