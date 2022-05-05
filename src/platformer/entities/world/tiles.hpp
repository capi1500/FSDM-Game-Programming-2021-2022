#pragma once

#include <SFML/System/Vector2.hpp>

struct TileConfig{
	const sf::Vector2u texture_coord;
	const bool solid;
};

struct Tiles{
	static const TileConfig grass_flat_standalone;
	static const TileConfig grass_flat_left;
	static const TileConfig grass_flat_middle;
	static const TileConfig grass_flat_right;
	static const TileConfig grass_standalone;
	static const TileConfig grass_left;
	static const TileConfig grass_middle;
	static const TileConfig grass_right;
	static const TileConfig sand_flat_standalone;
	static const TileConfig sand_flat_left;
	static const TileConfig sand_flat_middle;
	static const TileConfig sand_flat_right;
	static const TileConfig sand_standalone;
	static const TileConfig sand_left;
	static const TileConfig sand_middle;
	static const TileConfig sand_right;
	static const TileConfig snow_flat_standalone;
	static const TileConfig snow_flat_left;
	static const TileConfig snow_flat_middle;
	static const TileConfig snow_flat_right;
	static const TileConfig snow_standalone;
	static const TileConfig snow_left;
	static const TileConfig snow_middle;
	static const TileConfig snow_right;
	static const TileConfig dirt_middle_standalone;
	static const TileConfig dirt_middle_left;
	static const TileConfig dirt_middle_middle;
	static const TileConfig dirt_middle_right;
	static const TileConfig dirt_bottom_standalone;
	static const TileConfig dirt_bottom_left;
	static const TileConfig dirt_bottom_middle;
	static const TileConfig dirt_bottom_right;
	static const TileConfig platform_standalone;
	static const TileConfig platform_left;
	static const TileConfig platform_middle;
	static const TileConfig platform_right;

	static const TileConfig dirt_corner_top_left;
	static const TileConfig dirt_corner_bottom_left;
	static const TileConfig dirt_corner_top_right;
	static const TileConfig dirt_corner_bottom_right;

	static const TileConfig box1;
	static const TileConfig box2;
	static const TileConfig box3;

	static const TileConfig hearth_full;
	static const TileConfig hearth_half;
	static const TileConfig hearth_empty;

	static const TileConfig lever_left;
	static const TileConfig lever_mid;
	static const TileConfig lever_right;
	static const TileConfig button;
	static const TileConfig button_pressed;
	static const TileConfig spring_pressed;
	static const TileConfig spring_released;

	static const TileConfig sign_left;
	static const TileConfig sign_right;
	static const TileConfig sign;

	static const TileConfig diamond;
	static const TileConfig coin1;
	static const TileConfig coin2;
	static const TileConfig key;
	static const TileConfig lock;

	static const TileConfig golden_brick;
	static const TileConfig golden_brick_mark;
	static const TileConfig golden_brick_o;

	static const TileConfig brick;
	static const TileConfig brick_mark;
	static const TileConfig brick_o;

	static const TileConfig spikes;

	static const TileConfig dot;
	static const TileConfig cross;
	static const TileConfig percent;

	static const TileConfig flag_bottom;
	static const TileConfig flag_top1;
	static const TileConfig flag_top2;

	static const TileConfig door_bottom1;
	static const TileConfig door_bottom2;
	static const TileConfig door_top;
	
	static const TileConfig plant1;
	static const TileConfig plant2;
	static const TileConfig plant3;
	static const TileConfig plant4;
	static const TileConfig mushroom1;
	static const TileConfig mushroom2;
	static const TileConfig snow_plant;
	static const TileConfig snowman;
	
	static const TileConfig water_surface1;
	static const TileConfig water_surface2;
	static const TileConfig water;
};
