// Authors: Handling
// Created by 60263 on 2020/10/23.
// This is 

#ifndef V4_THREADPOOL__TCPCONNECTION_H_
#define V4_THREADPOOL__TCPCONNECTION_H_

#include "Socket.h"
#include "InetAddress.h"
#include "SocketIO.h"
#include "Noncopyable.h"
#include "Eventloop.h"
#include <functional>
#include <memory>

namespace wd {

class TcpConnection;

using TcpConnectionPtr = std::shared_ptr<TcpConnection>;
using TcpConnectionCallback = std::function<void(const TcpConnectionPtr &conn)>;
class TcpConnection : public Noncopyable,
                      public std::enable_shared_from_this<TcpConnection> {
 public:
  TcpConnection(int fd, Eventloop *loop);
  ~TcpConnection();

  string receive();
  void send(const string &msg);
  void sendInLoop(const string &msg);

  string toString() const;
  void shutdown();

  void setConnectionCallback(const TcpConnectionCallback &cb);
  void setMessageCallback(const TcpConnectionCallback &cb);
  void setCloseCallback(const TcpConnectionCallback &cb);

  void handleConnectionCallback();
  void handleMessageCallback();
  void handleCloseCallback();

  bool isConnectionClosed();

 private:
  InetAddress getLocalAddr(int fd);
  InetAddress getPeerAddr(int fd);

  Socket _sock;
  Eventloop *_loop;
  SocketIO _socketIo;
  InetAddress _localAddr;
  InetAddress _peerAddr;
  bool _isShutdwonWrite;

  TcpConnectionCallback _onConnection;
  TcpConnectionCallback _onMessage;
  TcpConnectionCallback _onClose;
};

}//end of namespace wd


#endif //V4_THREADPOOL__TCPCONNECTION_H_
