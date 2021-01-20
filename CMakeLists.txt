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


