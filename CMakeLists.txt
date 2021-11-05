cmake_minimum_required(VERSION 3.17)
project(ProgramowanieGier)

set(CMAKE_CXX_STANDARD 17)

# includes
include_directories(src)

# find SFML 2.5
if(WIN32)
    set(SFML_DIR libraries/win/SFML-2.5.1/lib/cmake/SFML/)
else()
    set(SFML_DIR libraries/unix/SFML-2.5.1/lib/cmake/SFML/)
endif(WIN32)

find_package(SFML 2.5 COMPONENTS graphics window system audio network REQUIRED)

# add execs
add_executable(ProgramowanieGier src/main.cpp src/board.cpp src/board.hpp src/player.cpp src/player.hpp)
add_executable(SFML_basics src/sfml_basic.cpp)
add_executable(Origin_example src/origin_example.cpp)

# compile options
target_compile_options(ProgramowanieGier PRIVATE -Wall)

# link libraries
target_link_libraries(ProgramowanieGier sfml-graphics sfml-window sfml-system sfml-audio sfml-network)
target_link_libraries(SFML_basics sfml-graphics sfml-window sfml-system sfml-audio sfml-network)
target_link_libraries(Origin_example sfml-graphics sfml-window sfml-system sfml-audio sfml-network)