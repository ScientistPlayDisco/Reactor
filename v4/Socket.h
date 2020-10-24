// Authors: Handling
// Created by 60263 on 2020/10/20.
// This is 
//RAII技术
#ifndef V1__SOCKET_H_
#define V1__SOCKET_H_

namespace wd {
class Socket {
 public:
  Socket();
  explicit Socket(int fd);
  ~Socket();
  int fd() const;
  void shutdownWrite();
 private:
  int _fd;
};

}

#endif //V1__SOCKET_H_
