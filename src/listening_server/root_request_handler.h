#ifndef CPP_MATCHMAKING_TEST_SRC_LISTENING_SERVER_ROOT_REQUEST_HANDLER_H_
#define CPP_MATCHMAKING_TEST_SRC_LISTENING_SERVER_ROOT_REQUEST_HANDLER_H_

#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"

namespace ListeningServer {
class RootRequestHandler : public Poco::Net::HTTPRequestHandler {
public:
  void handleRequest(
    Poco::Net::HTTPServerRequest&  request,
    Poco::Net::HTTPServerResponse& response
  ) override {
    auto& resp = response.send();
    resp << "Lockie start!!";
  }
};
} // namespace ListeningServer

#endif
