#include <span>
#include <string>
#include <vector>

// #include "http_server.h"

#include "oatpp/network/Server.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp/web/server/HttpConnectionHandler.hpp"

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

  // create HTTP connectio handler with router
  auto connection_handler =
    oatpp::web::server::HttpConnectionHandler::createShared(router);

  // tcp connection provider
  auto connection_provider =
    oatpp::network::tcp::server::ConnectionProvider::createShared(
      {"localhost", 80, oatpp::network::Address::IP_4}
    );

  oatpp::network::Server server(connection_provider, connection_handler);

  OATPP_LOGI(
    "MyApp",
    "Server Port %s",
    connection_provider->getProperty("port").getData()
  );

  server.run();
}

auto main() -> int {
  oatpp::base::Environment::init();

  run();

  oatpp::base::Environment::destroy();

  return 0;
}

// auto main(int argc, const char* argv[]) -> int {

//   const auto span_argv = std::span(argv, argc);

//   std::vector<std::string> args(argc);

//   for (const auto& elem : span_argv) {
//     args.emplace_back(elem);
//   }

//   ListeningServer::HttpServer app;
//   return app.run(args);
// }
