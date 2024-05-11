#include <span>
#include <string>
#include <vector>

#include "http_server.h"

auto main(int argc, const char* argv[]) -> int {

  const auto span_argv = std::span(argv, argc);

  std::vector<std::string> args(argc);

  for (const auto& elem : span_argv) {
    args.emplace_back(elem);
  }

  ListeningServer::HttpServer app;
  return app.run(args);
}
