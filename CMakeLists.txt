cmake_minimum_required(VERSION 3.28)
project(CPP_SysMon)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(CPP_SysMon
        src/main.cpp
        src/Process.cpp
        src/ProcParser.cpp
        include/ProcParser.h
        include/UserHelper.h
        src/ProcessManager.cpp
        include/ProcessManager.h)
