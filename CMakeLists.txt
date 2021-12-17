cmake_minimum_required(VERSION 3.17)
project(ProgramowanieGier)

set(CMAKE_CXX_STANDARD 17)

# includes
include_directories(src)

set(LIB_DIR libraries)
if(WIN32)
    set(SHRD_EXT dll)
else()
    set(SHRD_EXT so)
endif(WIN32)

# add SFML 2.5
set(SFML_DIR ${LIB_DIR}/SFML-2.5.1/lib/cmake/SFML/)

find_package(SFML 2.5 COMPONENTS graphics window system audio network REQUIRED)

# add Box2D
include_directories(${LIB_DIR}/Box2D/include)

# add execs
add_executable(ProgramowanieGier src/board_game/main.cpp src/board_game/board.cpp src/board_game/board.hpp src/board_game/player.cpp src/board_game/player.hpp src/board_game/point.cpp src/board_game/point.hpp)
add_executable(SFML_basics src/other/sfml_basic.cpp)
add_executable(Origin_example src/other/origin_example.cpp)
add_executable(Pointers_example src/other/pointers.cpp)
add_executable(Platformer src/platformer/main.cpp src/platformer/game.cpp src/platformer/game.hpp src/platformer/scene.cpp src/platformer/scene.hpp src/platformer/utils/stateMachine.cpp src/platformer/utils/stateMachine.hpp src/platformer/utils/state.cpp src/platformer/utils/state.hpp src/platformer/framework.cpp src/platformer/framework.hpp src/platformer/systems/soundboard.cpp src/platformer/systems/soundboard.hpp src/platformer/systems/assetStorage.cpp src/platformer/systems/assetStorage.hpp src/platformer/systems/inputHandler.cpp src/platformer/systems/inputHandler.hpp src/platformer/utils/listener.hpp src/platformer/utils/emitter.hpp src/platformer/level.cpp src/platformer/level.hpp src/platformer/entity.cpp src/platformer/entity.hpp src/platformer/scenes/mainMenu.cpp src/platformer/scenes/mainMenu.hpp src/platformer/systems/renderer.cpp src/platformer/systems/renderer.hpp src/platformer/gui/button.cpp src/platformer/gui/button.hpp src/platformer/gui/image.cpp src/platformer/gui/image.hpp)

# compile options
target_compile_options(ProgramowanieGier PRIVATE -Wall)

# link libraries
target_link_libraries(ProgramowanieGier sfml-graphics sfml-window sfml-system sfml-audio sfml-network)
target_link_libraries(SFML_basics sfml-graphics sfml-window sfml-system sfml-audio sfml-network)
target_link_libraries(Origin_example sfml-graphics sfml-window sfml-system sfml-audio sfml-network)
target_link_libraries(Platformer sfml-graphics sfml-window sfml-system sfml-audio sfml-network)
target_link_libraries(Platformer ${CMAKE_HOME_DIRECTORY}/${LIB_DIR}/Box2D/bin/libbox2d.${SHRD_EXT})