#include "tiles.hpp"

const TileConfig Tiles::grass_flat_standalone = {{0, 0}, true};
const TileConfig Tiles::grass_flat_left = {{1, 0}, true};
const TileConfig Tiles::grass_flat_middle = {{2, 0}, true};
const TileConfig Tiles::grass_flat_right = {{3, 0}, true};
const TileConfig Tiles::grass_standalone = {{0, 1}, true};
const TileConfig Tiles::grass_left = {{1, 1}, true};
const TileConfig Tiles::grass_middle = {{2, 1}, true};
const TileConfig Tiles::grass_right = {{3, 1}, true};
const TileConfig Tiles::sand_flat_standalone = {{0, 2}, true};
const TileConfig Tiles::sand_flat_left = {{1, 2}, true};
const TileConfig Tiles::sand_flat_middle = {{2, 2}, true};
const TileConfig Tiles::sand_flat_right = {{3, 2}, true};
const TileConfig Tiles::sand_standalone = {{0, 3}, true};
const TileConfig Tiles::sand_left = {{1, 3}, true};
const TileConfig Tiles::sand_middle = {{2, 3}, true};
const TileConfig Tiles::sand_right = {{3, 3}, true};
const TileConfig Tiles::snow_flat_standalone = {{0, 4}, true};
const TileConfig Tiles::snow_flat_left = {{1, 4}, true};
const TileConfig Tiles::snow_flat_middle = {{2, 4}, true};
const TileConfig Tiles::snow_flat_right = {{3, 4}, true};
const TileConfig Tiles::snow_standalone = {{0, 5}, true};
const TileConfig Tiles::snow_left = {{1, 5}, true};
const TileConfig Tiles::snow_middle = {{2, 5}, true};
const TileConfig Tiles::snow_right = {{3, 5}, true};
const TileConfig Tiles::dirt_middle_standalone = {{0, 6}, true};
const TileConfig Tiles::dirt_middle_left = {{1, 6}, true};
const TileConfig Tiles::dirt_middle_middle = {{2, 6}, true};
const TileConfig Tiles::dirt_middle_right = {{3, 6}, true};
const TileConfig Tiles::dirt_bottom_standalone = {{0, 7}, true};
const TileConfig Tiles::dirt_bottom_left = {{1, 7}, true};
const TileConfig Tiles::dirt_bottom_middle = {{2, 7}, true};
const TileConfig Tiles::dirt_bottom_right = {{3, 7}, true};
const TileConfig Tiles::platform_standalone = {{0, 7}, true};
const TileConfig Tiles::platform_left = {{1, 7}, true};
const TileConfig Tiles::platform_middle = {{2, 7}, true};
const TileConfig Tiles::platform_right = {{3, 7}, true};

const TileConfig Tiles::dirt_corner_top_left = {{4, 0}, true};
const TileConfig Tiles::dirt_corner_bottom_left = {{4, 1}, true};
const TileConfig Tiles::dirt_corner_top_right = {{5, 0}, true};
const TileConfig Tiles::dirt_corner_bottom_right = {{5, 1}, true};

const TileConfig Tiles::box1 = {{6, 0}, true};
const TileConfig Tiles::box2 = {{6, 1}, true};
const TileConfig Tiles::box3 = {{4, 5}, true};

const TileConfig Tiles::hearth_full = {{4, 2}, true};
const TileConfig Tiles::hearth_half = {{5, 2}, true};
const TileConfig Tiles::hearth_empty = {{6, 2}, true};

const TileConfig Tiles::lever_left = {{4, 3}, true};
const TileConfig Tiles::lever_mid = {{5, 3}, true};
const TileConfig Tiles::lever_right = {{6, 3}, true};
const TileConfig Tiles::button = {{8, 7}, true};
const TileConfig Tiles::button_pressed = {{9, 7}, true};
const TileConfig Tiles::spring_pressed = {{7, 5}, true};
const TileConfig Tiles::spring_released = {{8, 5}, true};

const TileConfig Tiles::sign_left = {{4, 4}, true};
const TileConfig Tiles::sign_right = {{5, 4}, true};
const TileConfig Tiles::sign = {{6, 4}, true};

const TileConfig Tiles::diamond = {{7, 3}, true};
const TileConfig Tiles::coin1 = {{11, 7}, true};
const TileConfig Tiles::coin2 = {{12, 7}, true};
const TileConfig Tiles::key = {{7, 1}, true};
const TileConfig Tiles::lock = {{8, 1}, true};

const TileConfig Tiles::golden_brick = {{9, 0}, true};
const TileConfig Tiles::golden_brick_mark = {{10, 0}, true};
const TileConfig Tiles::golden_brick_o = {{11, 0}, true};

const TileConfig Tiles::brick = {{9, 1}, true};
const TileConfig Tiles::brick_mark = {{10, 1}, true};
const TileConfig Tiles::brick_o = {{11, 1}, true};

const TileConfig Tiles::spikes = {{8, 3}, true};

const TileConfig Tiles::dot = {{17, 7}, true};
const TileConfig Tiles::cross = {{18, 7}, true};
const TileConfig Tiles::percent = {{19, 7}, true};

const TileConfig Tiles::flag_bottom = {{11, 6}, true};
const TileConfig Tiles::flag_top1 = {{11, 5}, true};
const TileConfig Tiles::flag_top2 = {{12, 5}, true};

const TileConfig Tiles::door_bottom1 = {{10, 7}, true};
const TileConfig Tiles::door_bottom2 = {{10, 6}, true};
const TileConfig Tiles::door_top = {{10, 5}, true};

const TileConfig Tiles::plant1 = {{4, 6}, true};
const TileConfig Tiles::plant2 = {{5, 6}, true};
const TileConfig Tiles::plant3 = {{6, 6}, true};
const TileConfig Tiles::plant4 = {{7, 6}, true};
const TileConfig Tiles::mushroom1 = {{8, 6}, true};
const TileConfig Tiles::mushroom2 = {{9, 6}, true};
const TileConfig Tiles::snow_plant = {{4, 7}, true};
const TileConfig Tiles::snowman = {{5, 7}, true};

const TileConfig Tiles::water_surface1 = {{13, 1}, true};
const TileConfig Tiles::water_surface2 = {{13, 2}, true};
const TileConfig Tiles::water = {{13, 2}, true};