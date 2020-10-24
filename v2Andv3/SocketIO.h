// Authors: Handling
// Created by 60263 on 2020/10/20.
// This is 

#ifndef V1__SOCKETIO_H_
#define V1__SOCKETIO_H_

namespace wd {
class SocketIO {
 public:
  explicit
  SocketIO(int fd);

  int readn(char *buff, int len);
  int readline(char *buff, int maxlen);
  int writen(const char *buff, int len);
 private:
  int recvPeek(char *buff, int len);

 private:
  int _fd;
};

}

#endif //V1__SOCKETIO_H_
