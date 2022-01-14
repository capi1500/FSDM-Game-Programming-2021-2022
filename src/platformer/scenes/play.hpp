#pragma once

#include <platformer/scene.hpp>
#include <platformer/utils/tileset.hpp>

struct Tiles{
	const sf::Vector2u grass_flat_standalone = {0, 0};
	const sf::Vector2u grass_flat_left = {1, 0};
	const sf::Vector2u grass_flat_middle = {2, 0};
	const sf::Vector2u grass_flat_right = {3, 0};
	const sf::Vector2u grass_standalone = {0, 1};
	const sf::Vector2u grass_left = {1, 1};
	const sf::Vector2u grass_middle = {2, 1};
	const sf::Vector2u grass_right = {3, 1};
	const sf::Vector2u sand_flat_standalone = {0, 2};
	const sf::Vector2u sand_flat_left = {1, 2};
	const sf::Vector2u sand_flat_middle = {2, 2};
	const sf::Vector2u sand_flat_right = {3, 2};
	const sf::Vector2u sand_standalone = {0, 3};
	const sf::Vector2u sand_left = {1, 3};
	const sf::Vector2u sand_middle = {2, 3};
	const sf::Vector2u sand_right = {3, 3};
	const sf::Vector2u snow_flat_standalone = {0, 4};
	const sf::Vector2u snow_flat_left = {1, 4};
	const sf::Vector2u snow_flat_middle = {2, 4};
	const sf::Vector2u snow_flat_right = {3, 4};
	const sf::Vector2u snow_standalone = {0, 5};
	const sf::Vector2u snow_left = {1, 5};
	const sf::Vector2u snow_middle = {2, 5};
	const sf::Vector2u snow_right = {3, 5};
	const sf::Vector2u dirt_middle_standalone = {0, 6};
	const sf::Vector2u dirt_middle_left = {1, 6};
	const sf::Vector2u dirt_middle_middle = {2, 6};
	const sf::Vector2u dirt_middle_right = {3, 6};
	const sf::Vector2u dirt_bottom_standalone = {0, 7};
	const sf::Vector2u dirt_bottom_left = {1, 7};
	const sf::Vector2u dirt_bottom_middle = {2, 7};
	const sf::Vector2u dirt_bottom_right = {3, 7};
	const sf::Vector2u platform_standalone = {0, 7};
	const sf::Vector2u platform_left = {1, 7};
	const sf::Vector2u platform_middle = {2, 7};
	const sf::Vector2u platform_right = {3, 7};
	
	const sf::Vector2u dirt_corner_top_left = {4, 0};
	const sf::Vector2u dirt_corner_bottom_left = {4, 1};
	const sf::Vector2u dirt_corner_top_right = {5, 0};
	const sf::Vector2u dirt_corner_bottom_right = {5, 1};
	
	const sf::Vector2u box1 = {6, 0};
	const sf::Vector2u box2 = {6, 1};
	const sf::Vector2u box3 = {4, 5};
	
	const sf::Vector2u hearth_full = {4, 2};
	const sf::Vector2u hearth_half = {5, 2};
	const sf::Vector2u hearth_empty = {6, 2};
	
	const sf::Vector2u lever_left = {4, 3};
	const sf::Vector2u lever_mid = {5, 3};
	const sf::Vector2u lever_right = {6, 3};
	const sf::Vector2u button = {8, 7};
	const sf::Vector2u button_pressed = {9, 7};
	const sf::Vector2u spring_pressed = {7, 5};
	const sf::Vector2u spring_released = {8, 5};
	
	const sf::Vector2u sign_left = {4, 4};
	const sf::Vector2u sign_right = {5, 4};
	const sf::Vector2u sign = {6, 4};
	
	const sf::Vector2u diamond = {7, 3};
	const sf::Vector2u coin1 = {11, 7};
	const sf::Vector2u coin2 = {12, 7};
	const sf::Vector2u key = {7, 1};
	const sf::Vector2u lock = {8, 1};
	
	const sf::Vector2u golden_brick = {9, 0};
	const sf::Vector2u golden_brick_mark = {10, 0};
	const sf::Vector2u golden_brick_o = {11, 0};
	
	const sf::Vector2u brick = {9, 1};
	const sf::Vector2u brick_mark = {10, 1};
	const sf::Vector2u brick_o = {11, 1};
	
	const sf::Vector2u spikes = {8, 3};
	
	const sf::Vector2u dot = {17, 7};
	const sf::Vector2u cross = {18, 7};
	const sf::Vector2u percent = {19, 7};
	
	const sf::Vector2u flag_bottom = {11, 6};
	const sf::Vector2u flag_top1 = {11, 5};
	const sf::Vector2u flag_top2 = {12, 5};
	
	const sf::Vector2u door_bottom1 = {10, 7};
	const sf::Vector2u door_bottom2 = {10, 6};
	const sf::Vector2u door_top = {10, 5};
	
	const sf::Vector2u plant1 = {4, 6};
	const sf::Vector2u plant2 = {5, 6};
	const sf::Vector2u plant3 = {6, 6};
	const sf::Vector2u plant4 = {7, 6};
	const sf::Vector2u mushroom1 = {8, 6};
	const sf::Vector2u mushroom2 = {9, 6};
	const sf::Vector2u snow_plant = {4, 7};
	const sf::Vector2u snowman = {5, 7};
	
	const sf::Vector2u water_surface1 = {13, 1};
	const sf::Vector2u water_surface2 = {13, 2};
	const sf::Vector2u water = {13, 2};
};

class Play : public Scene{
	private:
		Tiles names;
		Tileset tiles;
		Tileset background;
		Tileset characters;
		Tileset ui;
	public:
		Play(StateMachine& stateMachine);
};


