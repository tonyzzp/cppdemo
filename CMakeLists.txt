project(cppdemo)
cmake_minimum_required(VERSION 3.16)

# add_definitions(-Wno-write-strings)

if(MSVC)
    add_definitions(/utf-8)
endif()

include_directories(
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

# demo_simple
add_executable(
    demo_simple
    simple/demo_simple.cpp
)

# demo_time
add_executable(
    demo_time
    time/demo_time.cpp
)

# demo_io
add_executable(
    demo_io
    io/demo_io.cpp
)


# demo_class
add_executable(
    demo_class
    class/demo_class.cpp
)

#demo_friend
add_executable(
    demo_friend
    friend/demo_friend.cpp
)