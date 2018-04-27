cmake_minimum_required(VERSION 3.9)
project(CAS)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_C_STANDARD 90)

add_executable(CAS CAS.cpp)

target_include_directories(CAS PRIVATE "/home/pedro/.wine/drive_c/Program Files/CASIO/fx-9860G SDK/OS/SH/include")
target_include_directories(CAS PRIVATE "/home/pedro/.wine/drive_c/Program Files/CASIO/fx-9860G SDK/OS/FX/include")
target_include_directories(CAS PRIVATE .)

add_executable(Test test/Test.cpp test/Test.cpp)