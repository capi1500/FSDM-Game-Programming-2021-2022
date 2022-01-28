#include <SFML/System/Vector2.hpp>
#include "tiles.hpp"

const sf::Vector2u Tiles::grass_flat_standalone = {0, 0};
const sf::Vector2u Tiles::grass_flat_left = {1, 0};
const sf::Vector2u Tiles::grass_flat_middle = {2, 0};
const sf::Vector2u Tiles::grass_flat_right = {3, 0};
const sf::Vector2u Tiles::grass_standalone = {0, 1};
const sf::Vector2u Tiles::grass_left = {1, 1};
const sf::Vector2u Tiles::grass_middle = {2, 1};
const sf::Vector2u Tiles::grass_right = {3, 1};
const sf::Vector2u Tiles::sand_flat_standalone = {0, 2};
const sf::Vector2u Tiles::sand_flat_left = {1, 2};
const sf::Vector2u Tiles::sand_flat_middle = {2, 2};
const sf::Vector2u Tiles::sand_flat_right = {3, 2};
const sf::Vector2u Tiles::sand_standalone = {0, 3};
const sf::Vector2u Tiles::sand_left = {1, 3};
const sf::Vector2u Tiles::sand_middle = {2, 3};
const sf::Vector2u Tiles::sand_right = {3, 3};
const sf::Vector2u Tiles::snow_flat_standalone = {0, 4};
const sf::Vector2u Tiles::snow_flat_left = {1, 4};
const sf::Vector2u Tiles::snow_flat_middle = {2, 4};
const sf::Vector2u Tiles::snow_flat_right = {3, 4};
const sf::Vector2u Tiles::snow_standalone = {0, 5};
const sf::Vector2u Tiles::snow_left = {1, 5};
const sf::Vector2u Tiles::snow_middle = {2, 5};
const sf::Vector2u Tiles::snow_right = {3, 5};
const sf::Vector2u Tiles::dirt_middle_standalone = {0, 6};
const sf::Vector2u Tiles::dirt_middle_left = {1, 6};
const sf::Vector2u Tiles::dirt_middle_middle = {2, 6};
const sf::Vector2u Tiles::dirt_middle_right = {3, 6};
const sf::Vector2u Tiles::dirt_bottom_standalone = {0, 7};
const sf::Vector2u Tiles::dirt_bottom_left = {1, 7};
const sf::Vector2u Tiles::dirt_bottom_middle = {2, 7};
const sf::Vector2u Tiles::dirt_bottom_right = {3, 7};
const sf::Vector2u Tiles::platform_standalone = {0, 7};
const sf::Vector2u Tiles::platform_left = {1, 7};
const sf::Vector2u Tiles::platform_middle = {2, 7};
const sf::Vector2u Tiles::platform_right = {3, 7};

const sf::Vector2u Tiles::dirt_corner_top_left = {4, 0};
const sf::Vector2u Tiles::dirt_corner_bottom_left = {4, 1};
const sf::Vector2u Tiles::dirt_corner_top_right = {5, 0};
const sf::Vector2u Tiles::dirt_corner_bottom_right = {5, 1};

const sf::Vector2u Tiles::box1 = {6, 0};
const sf::Vector2u Tiles::box2 = {6, 1};
const sf::Vector2u Tiles::box3 = {4, 5};

const sf::Vector2u Tiles::hearth_full = {4, 2};
const sf::Vector2u Tiles::hearth_half = {5, 2};
const sf::Vector2u Tiles::hearth_empty = {6, 2};

const sf::Vector2u Tiles::lever_left = {4, 3};
const sf::Vector2u Tiles::lever_mid = {5, 3};
const sf::Vector2u Tiles::lever_right = {6, 3};
const sf::Vector2u Tiles::button = {8, 7};
const sf::Vector2u Tiles::button_pressed = {9, 7};
const sf::Vector2u Tiles::spring_pressed = {7, 5};
const sf::Vector2u Tiles::spring_released = {8, 5};

const sf::Vector2u Tiles::sign_left = {4, 4};
const sf::Vector2u Tiles::sign_right = {5, 4};
const sf::Vector2u Tiles::sign = {6, 4};

const sf::Vector2u Tiles::diamond = {7, 3};
const sf::Vector2u Tiles::coin1 = {11, 7};
const sf::Vector2u Tiles::coin2 = {12, 7};
const sf::Vector2u Tiles::key = {7, 1};
const sf::Vector2u Tiles::lock = {8, 1};

const sf::Vector2u Tiles::golden_brick = {9, 0};
const sf::Vector2u Tiles::golden_brick_mark = {10, 0};
const sf::Vector2u Tiles::golden_brick_o = {11, 0};

const sf::Vector2u Tiles::brick = {9, 1};
const sf::Vector2u Tiles::brick_mark = {10, 1};
const sf::Vector2u Tiles::brick_o = {11, 1};

const sf::Vector2u Tiles::spikes = {8, 3};

const sf::Vector2u Tiles::dot = {17, 7};
const sf::Vector2u Tiles::cross = {18, 7};
const sf::Vector2u Tiles::percent = {19, 7};

const sf::Vector2u Tiles::flag_bottom = {11, 6};
const sf::Vector2u Tiles::flag_top1 = {11, 5};
const sf::Vector2u Tiles::flag_top2 = {12, 5};

const sf::Vector2u Tiles::door_bottom1 = {10, 7};
const sf::Vector2u Tiles::door_bottom2 = {10, 6};
const sf::Vector2u Tiles::door_top = {10, 5};

const sf::Vector2u Tiles::plant1 = {4, 6};
const sf::Vector2u Tiles::plant2 = {5, 6};
const sf::Vector2u Tiles::plant3 = {6, 6};
const sf::Vector2u Tiles::plant4 = {7, 6};
const sf::Vector2u Tiles::mushroom1 = {8, 6};
const sf::Vector2u Tiles::mushroom2 = {9, 6};
const sf::Vector2u Tiles::snow_plant = {4, 7};
const sf::Vector2u Tiles::snowman = {5, 7};

const sf::Vector2u Tiles::water_surface1 = {13, 1};
const sf::Vector2u Tiles::water_surface2 = {13, 2};
const sf::Vector2u Tiles::water = {13, 2};