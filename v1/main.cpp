
#include "Acceptor.h"
#include "TcpConnection.h"

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
int main() {
  wd::Acceptor acceptor("10.206.0.12", 8888);
  acceptor.ready();

  wd::TcpConnection conn(acceptor.accept());
  cout << conn.toString() << " has connected!" << endl;
  conn.send("welcome to server.");
  printf("> pls client data:\n");
  cout << conn.receive() << endl;
}
