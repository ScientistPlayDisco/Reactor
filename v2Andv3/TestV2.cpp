// Authors: Handling
// Created by 60263 on 2020/10/21.
// This is 

#include "Acceptor.h"
#include "Eventloop.h"
#include "TcpConnection.h"
#include "TcpServer.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void onConection(const wd::TcpConnectionPtr & conn)
{
  cout << ">> " << conn->toString() << " has connected!" << endl;
  conn->send("welcome to server!");
}

void onMessage(const wd::TcpConnectionPtr & conn)
{
  string msg = conn->receive();
  cout << ">>> receive:" << msg << endl;
  //回显操作
  conn->send(msg);
}

void onClose(const wd::TcpConnectionPtr & conn)
{
  cout << "> " << conn->toString() << " has closed!" << endl;
}
void testv2(){
  wd::Acceptor acceptor("10.206.0.12", 7777);
  acceptor.ready();

  wd::Eventloop loop(acceptor);

  loop.setConnectionCallback(onConection);
  loop.setMessageCallback(onMessage);
  loop.setCloseCallback(onClose);

  loop.loop();
}

void testv3(){
  wd::TcpServer server("10.206.0.12", 7777);

  server.setConnectionCallback(onConection);
  server.setMessageCallback(onMessage);
  server.setCloseCallback(onClose);
  server.start();
}
int main()
{
  testv3();

  return 0;
}

