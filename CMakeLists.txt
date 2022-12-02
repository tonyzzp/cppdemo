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

#demo_extend
add_executable(
    demo_extend
    extend/demo_extend.cpp
)

#demo_operator
add_executable(
    demo_operator
    operator/demo_operator.cpp
)


#demo_exception
add_executable(
    demo_exception
    exception/demo_exception.cpp
)

#demo_newdelete
add_executable(
    demo_newdelete
    newdelete/demo_newdelete.cpp
)

#demo_namespace
add_executable(
    demo_namespace
    namespace/demo_namespace.cpp
)

#demo_template
add_executable(
    demo_template
    template/demo_template.cpp
)