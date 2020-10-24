// Authors: Handling
// Created by 60263 on 2020/10/21.
// This is 

#include "TcpServer.h"

namespace wd {

TcpServer::TcpServer(const string &ip, unsigned short port)
    : acceptor_(ip, port), loop_(acceptor_) {}
void TcpServer::start() {
  acceptor_.ready();
  loop_.loop();
}
void TcpServer::stop() {
  loop_.unloop();
}

void TcpServer::setConnectionCallback(TcpConnectionCallback &&cb) {
  loop_.setConnectionCallback(std::move(cb));
}
void TcpServer::setMessageCallback(TcpConnectionCallback &&cb) {
  loop_.setMessageCallback(std::move(cb));
}
void TcpServer::setCloseCallback(TcpConnectionCallback &&cb) {
  loop_.setCloseCallback(std::move(cb));
}
}