cmake_minimum_required(VERSION 3.16)

project(viikkoteht2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(viikkoteht2 main.cpp
    game.h game.cpp)

include(GNUInstallDirs)
install(TARGETS viikkoteht2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
