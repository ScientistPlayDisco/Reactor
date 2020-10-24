// Authors: Handling
// Created by 60263 on 2020/10/20.
// This is 

#ifndef V1__INETADDRESS_H_
#define V1__INETADDRESS_H_
#include <arpa/inet.h>
#include <string>
using std::string;

namespace wd {
class InetAddress {
 public:
  explicit InetAddress(unsigned short port);//绑定本机Ip
  InetAddress(const string & ip,unsigned short port);//自定义IP
  InetAddress(const struct sockaddr_in & addr);//通过sockaddr_in结构体

  string ip() const;
  unsigned short port() const;
  struct sockaddr_in * getInetAddressPtr(){ return & _addr;}
 private:
  struct sockaddr_in _addr;
};


} //end of namespace wd

#endif //V1__INETADDRESS_H_
