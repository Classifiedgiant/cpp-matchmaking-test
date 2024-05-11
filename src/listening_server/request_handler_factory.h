#ifndef CPP_MATCHMAKING_TEST_SRC_LISTENING_SERVER_REQUEST_HANDLER_FACTORY_H_
#define CPP_MATCHMAKING_TEST_SRC_LISTENING_SERVER_REQUEST_HANDLER_FACTORY_H_

#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerRequest.h"

#include "root_request_handler.h"

// forward declaration
namespace Poco::Net {
class HTTPRequestHandler;
}

namespace ListeningServer {

class RequestHandlerFactory : public Poco::Net::HTTPRequestHandlerFactory {
public:
  auto createRequestHandler(const Poco::Net::HTTPServerRequest& request
  ) -> Poco::Net::HTTPRequestHandler* override {
    return request.getURI() == "/" ? new RootRequestHandler() : nullptr;
  }
};

} // namespace ListeningServer

#endif
