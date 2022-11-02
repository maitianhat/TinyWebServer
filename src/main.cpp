/**
 * @file main.cpp
 * @author gatsby (gatsby.huang@qq.com)
 * @version 1.0
 * @date 2022-11-02
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "webserver.h"

int main() {
  WebServer server(15213);
  server.start();

  return 0;
}
