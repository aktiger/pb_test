cmake_minimum_required(VERSION 3.1)
project(protobuf)
set(CMAKE_CXX_STANDARD 11)

include(FindProtobuf)
find_package(Protobuf REQUIRED COMPONENTS protobuf)
include_directories(${PROTOBUF_INCLUDE_DIR})
include_directories(./src)
add_executable(protobuf src/main.cpp src/msg.pb.cc )
target_link_libraries(protobuf ${PROTOBUF_LIBRARY})
message(WARNING "Protobuf_PROTOC_LIBRARIES is ${Protobuf_PROTOC_LIBRARIES}")
message(WARNING "pb lib path is ${PROTOBUF_LIBRARY}")