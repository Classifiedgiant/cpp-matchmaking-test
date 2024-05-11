#include "http_server.h"

#include <iostream>

#include "Poco/Net/HTTPServer.h"

#include "request_handler_factory.h"

auto ListeningServer::HttpServer::main(const std::vector<std::string>& args
) -> int {

  auto server = Poco::Net::HTTPServer(new RequestHandlerFactory());
  server.start();
  std::cout << "Starting the server...\n";

  waitForTerminationRequest();

  std::cout << "...Exiting the server\n";
  server.stop();

  std::cout << "Exiting\n";

  return Application::EXIT_OK;
}
