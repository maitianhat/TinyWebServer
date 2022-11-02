/**
 * @file webserver.cpp
 * @author gatsby (gatsby.huang@qq.com)
 * @version 1.0
 * @date 2022-11-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "webserver.h"

#include <netinet/in.h>
#include <unistd.h>

WebServer::WebServer(int port) : port_(port), isClosed_(false) {
  if (!InitSocket_()) {
    isClosed_ = true;
  }
}

WebServer::~WebServer() {
  close(listenFd_);
  isClosed_ = true;
}

void WebServer::start() {
  while (!isClosed_) {
  }
}

bool WebServer::InitSocket_() {
  int ret;
  struct sockaddr_in addr;
  if (port_ < 1024 || port_ > 65535) {
    return false;
  }

  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  addr.sin_port = htons(port_);

  listenFd_ = socket(AF_INET, SOCK_STREAM, 0);
  if (listenFd_ < 0) {
    return false;
  }

  // TODO more settings for this listen fd

  ret = bind(listenFd_, (struct sockaddr *)&addr, sizeof(addr));
  if (ret < 0) {
    close(listenFd_);
    return false;
  }

  ret = listen(listenFd_, 1);
  if (ret < 0) {
    close(listenFd_);
    return false;
  }

  return true;
}