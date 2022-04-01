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
add_executable(Platformer src/platformer/main.cpp src/platformer/game.cpp src/platformer/game.hpp src/platformer/scene.cpp src/platformer/scene.hpp src/platformer/utils/stateMachine.cpp src/platformer/utils/stateMachine.hpp src/platformer/utils/state.cpp src/platformer/utils/state.hpp src/platformer/framework.cpp src/platformer/framework.hpp src/platformer/systems/soundboard.cpp src/platformer/systems/soundboard.hpp src/platformer/systems/assetStorage.cpp src/platformer/systems/assetStorage.hpp src/platformer/systems/inputHandler.cpp src/platformer/systems/inputHandler.hpp src/platformer/utils/listener.hpp src/platformer/utils/emitter.hpp src/platformer/level.cpp src/platformer/level.hpp src/platformer/entities/entity.cpp src/platformer/entities/entity.hpp src/platformer/scenes/mainMenu.cpp src/platformer/scenes/mainMenu.hpp src/platformer/systems/renderer.cpp src/platformer/systems/renderer.hpp src/platformer/gui/button.cpp src/platformer/gui/button.hpp src/platformer/gui/widget.cpp src/platformer/gui/widget.hpp src/platformer/utils/tileset.cpp src/platformer/utils/tileset.hpp src/platformer/utils/PhysicsConfig.cpp src/platformer/utils/PhysicsConfig.h src/platformer/entities/physicalEntity.cpp src/platformer/entities/physicalEntity.hpp src/platformer/scenes/play.cpp src/platformer/scenes/play.hpp src/platformer/entities/world.cpp src/platformer/entities/world.hpp src/platformer/entities/world/tiles.hpp src/platformer/entities/world/tiles.cpp src/platformer/entities/player.cpp src/platformer/entities/player.hpp src/platformer/systems/contactListener.cpp src/platformer/systems/contactListener.hpp src/platformer/entities/entityProperties.cpp src/platformer/entities/entityProperties.hpp src/platformer/entities/world/characters.cpp src/platformer/scenes/pause.cpp src/platformer/entities/entities/mine.cpp src/platformer/entities/entities/mine.hpp src/platformer/gui/longButton.cpp src/platformer/gui/longButton.hpp src/platformer/scenes/settings.cpp src/platformer/scenes/settings.hpp src/platformer/gui/checkboxButton.cpp src/platformer/gui/checkboxButton.hpp src/platformer/gui/radioButton.cpp src/platformer/gui/radioButton.hpp src/platformer/gui/radioButtonGroup.cpp src/platformer/gui/radioButtonGroup.hpp src/platformer/scenes/events/sceneEvent.hpp src/platformer/scenes/play/playerMonsterCollision.cpp src/platformer/scenes/play/playerMonsterCollision.hpp src/platformer/scenes/play/collisionEvent.cpp src/platformer/scenes/play/collisionEvent.hpp src/platformer/scenes/events/sceneEvent.cpp src/platformer/entities/world/tiles.cpp src/platformer/scenes/events/sceneEventListener.cpp src/platformer/scenes/events/sceneEventListener.hpp src/platformer/entities/entities/diamond.cpp src/platformer/entities/entities/diamond.hpp src/platformer/scenes/play/groundCollision.cpp src/platformer/scenes/play/groundCollision.hpp src/platformer/entities/world/textureInfo.cpp src/platformer/entities/world/textureInfo.hpp src/platformer/scenes/play/collectibleCollision.cpp src/platformer/scenes/play/collectibleCollision.hpp src/platformer/entities/entities/collectible.cpp src/platformer/entities/entities/collectible.hpp src/platformer/scenes/editor.cpp src/platformer/scenes/editor.hpp src/platformer/scenes/editor/worldEditor.cpp src/platformer/scenes/editor/worldEditor.hpp src/platformer/gui/CoordChooser.cpp src/platformer/gui/CoordChooser.hpp src/platformer/scenes/editor/frame.cpp src/platformer/scenes/editor/frame.hpp src/platformer/scenes/editor/tileChooser.cpp src/platformer/scenes/editor/tileChooser.hpp)

# compile options
target_compile_options(ProgramowanieGier PRIVATE -Wall)

# link libraries
target_link_libraries(ProgramowanieGier sfml-graphics sfml-window sfml-system sfml-audio sfml-network)
target_link_libraries(SFML_basics sfml-graphics sfml-window sfml-system sfml-audio sfml-network)
target_link_libraries(SFML_basics ${CMAKE_HOME_DIRECTORY}/${LIB_DIR}/Box2D/bin/libbox2d.${SHRD_EXT})
target_link_libraries(Origin_example sfml-graphics sfml-window sfml-system sfml-audio sfml-network)
target_link_libraries(Platformer sfml-graphics sfml-window sfml-system sfml-audio sfml-network)
target_link_libraries(Platformer ${CMAKE_HOME_DIRECTORY}/${LIB_DIR}/Box2D/bin/libbox2d.${SHRD_EXT})