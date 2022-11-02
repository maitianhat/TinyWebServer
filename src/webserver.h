/**
 * @file webserver.h
 * @author gatsby (gatsby.huang@qq.com)
 * @version 1.0
 * @date 2022-11-02
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __WEBSERVER_H
#define __WEBSERVER_H

class WebServer {
 public:
  WebServer(int port);
  ~WebServer();

  void start();

 private:
  bool InitSocket_();

 private:
  int port_;
  bool isClosed_;

  int listenFd_;
};

#endif