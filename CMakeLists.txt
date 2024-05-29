cmake_minimum_required(VERSION 3.10)

project(OtusCommandParser VERSION 0.0.228)

set(CMAKE_CXX_STANDARD 17)
SET(COMMAND_PATH "command")
SET(CORE_PATH "core")
SET(OBSERVER_PATH "observer")

add_executable(bulk 
main.cpp 
${COMMAND_PATH}/simpleCommand.cpp 
${CORE_PATH}/console_writer.cpp
${CORE_PATH}/file_writer.cpp
${CORE_PATH}/reader.cpp
)

target_include_directories(bulk PRIVATE 
${COMMAND_PATH}
${CORE_PATH}
${OBSERVER_PATH}
)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(tests
tests/test.cpp
${COMMAND_PATH}/simpleCommand.cpp
${CORE_PATH}/console_writer.cpp
${CORE_PATH}/file_writer.cpp
${CORE_PATH}/reader.cpp)

target_include_directories(tests PRIVATE
${COMMAND_PATH}
${CORE_PATH}
${OBSERVER_PATH}
)

target_link_libraries(tests PRIVATE pthread GTest::gtest_main)
enable_testing()
add_test(tests tests)


install(TARGETS bulk RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)
