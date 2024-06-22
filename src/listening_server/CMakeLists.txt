set (PROJECT_NAME listener_server)

project(${PROJECT_NAME} LANGUAGES CXX)

find_package(oatpp REQUIRED)
find_package(spdlog REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE . ./request_handlers)
target_link_libraries(${PROJECT_NAME} oatpp::oatpp spdlog::spdlog)
