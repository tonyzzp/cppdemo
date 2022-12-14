project(cppdemo)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)


if(MSVC)
    add_definitions(/utf-8)
    add_definitions(-Wno-deprecated-declarations)
    add_definitions(-Wno-write-strings)
endif()

if(WIN32)
    set(CMAKE_CXX_FLAGS -fexec-charset=gbk)
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

#demo_define
add_executable(
    demo_define
    define/demo_define.cpp
)

#demo_signal
add_executable(
    demo_signal
    signal/demo_signal.cpp
)

#demo_thread
add_executable(
    demo_thread
    thread/demo_thread.cpp
)

target_link_libraries(
    demo_thread
    pthread
)

#demo_stl
add_executable(
    demo_stl
    stl/demo_stl.cpp
)

#demo_fs
add_executable(
    demo_fs
    fs/demo_fs.cpp
)