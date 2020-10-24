// Authors: Handling
// Created by 60263 on 2020/10/20.
// This is 

#include "InetAddress.h"

#include <string.h>

namespace wd {

InetAddress::InetAddress(unsigned short port) {
  ::memset(&_addr, 0, sizeof(struct sockaddr_in));
  _addr.sin_family = AF_INET;
  _addr.sin_port = htons(port);
  _addr.sin_addr.s_addr = INADDR_ANY;
}//绑定本机Ip
InetAddress::InetAddress(const string &ip, unsigned short port) {
  ::memset(&_addr, 0, sizeof(struct sockaddr_in));
  _addr.sin_family = AF_INET;  //小端模式      大端模式
  _addr.sin_port = htons(port);//主机字节序转成网络字节序列
  _addr.sin_addr.s_addr = inet_addr(ip.c_str());
}//自定义IP
InetAddress::InetAddress(const struct sockaddr_in &addr) : _addr(addr) {

}//通过sockaddr_in结构体

string InetAddress::ip() const {
  return string(::inet_ntoa(_addr.sin_addr));
}
unsigned short InetAddress::port() const {
  return ntohs(_addr.sin_port);
}

}
