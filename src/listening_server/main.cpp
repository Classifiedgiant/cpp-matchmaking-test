#include <iostream>
#include <span>
#include <string>

#include "oatpp/network/Server.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp/web/server/HttpConnectionHandler.hpp"

#include "spdlog/spdlog.h"

class Handler : public oatpp::web::server::HttpRequestHandler {
public:
  auto handle(const std::shared_ptr<IncomingRequest>& request
  ) -> std::shared_ptr<OutgoingResponse> override {
    return ResponseFactory::createResponse(Status::CODE_200, "Hello World");
  }
};

void run() {
  // create router for request routing
  auto router = oatpp::web::server::HttpRouter::createShared();
  router->route("GET", "/hello", std::make_shared<Handler>());

  // create HTTP connection handler with router
  auto connection_handler =
    oatpp::web::server::HttpConnectionHandler::createShared(router);

  // tcp connection provider
  const uint8_t port = 80;
  auto          connection_provider =
    oatpp::network::tcp::server::ConnectionProvider::createShared(
      {"localhost", port, oatpp::network::Address::IP_4}
    );

  oatpp::network::Server server(connection_provider, connection_handler);

  std::cout << "Logging was here\n";
  spdlog::info("Server starting on port {}", 80);

  server.run();
}

auto main() -> int {
  oatpp::base::Environment::init();

  run();

  oatpp::base::Environment::destroy();

  return 0;
}
