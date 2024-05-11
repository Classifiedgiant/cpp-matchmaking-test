#ifndef CPP_MATCHMAKING_TEST_SRC_LISTENING_SERVER_HTTP_SERVER_H_
#define CPP_MATCHMAKING_TEST_SRC_LISTENING_SERVER_HTTP_SERVER_H_

#include <string>
#include <vector>

#include "Poco/Util/ServerApplication.h"

namespace ListeningServer {

class HttpServer : public Poco::Util::ServerApplication {

  auto main(const std::vector<std::string>& args) -> int;
};

} // namespace ListeningServer

#endif
