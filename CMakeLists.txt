cmake_minimum_required(VERSION 3.28)
project(CPP_SysMon)

set(CMAKE_CXX_STANDARD 20)

set(CURSES_NEED_NCURSES TRUE)
set(CURSES_NEED_WIDE TRUE)
find_package(Curses REQUIRED)

add_executable(CPP_SysMon
        src/main.cpp
        src/Process.cpp
        src/ProcParser.cpp
        include/ProcParser.h
        include/UserHelper.h
        src/ProcessManager.cpp
        include/ProcessManager.h
        src/DisplayManager.cpp
        include/DisplayManager.h)

target_include_directories(CPP_SysMon PRIVATE
        include
        ${CURSES_INCLUDE_DIRS}
)

target_link_libraries(CPP_SysMon PUBLIC ${CURSES_LIBRARIES})

target_compile_definitions(CPP_SysMon PRIVATE _GNU_SOURCE)