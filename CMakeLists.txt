cmake_minimum_required(VERSION 3.10)
project(HomeWork16 VERSION 0.0.228)
set(CMAKE_CXX_STANDARD 17)

add_executable(bulk)

target_sources(bulk PRIVATE main.cpp console_writer.hpp console_writer.cpp file_writer.hpp file_writer.cpp Observer.hpp reader.hpp reader.cpp SimpleCommand.hpp)

install(TARGETS bulk RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT tori@ktori.me)

include(CPack)