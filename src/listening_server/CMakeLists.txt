set (PROJECT_NAME listener_server)

project(${PROJECT_NAME} LANGUAGES CXX)

find_package(Poco REQUIRED)

add_executable(${PROJECT_NAME} main.cpp http_server.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE .)
target_link_libraries(${PROJECT_NAME} Poco::Poco)