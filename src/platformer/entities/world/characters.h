#pragma once

#include <SFML/System/Vector2.hpp>

// TODO: switch to CharacterConfig, like TileConfig

class Characters{
	public:
		static const sf::Vector2u ghost_green_down;
		static const sf::Vector2u ghost_green_up;
		static const sf::Vector2u ghost_blue_down;
		static const sf::Vector2u ghost_blue_up;
		static const sf::Vector2u ghost_pink_down;
		static const sf::Vector2u ghost_pink_up;
		static const sf::Vector2u ghost_yellow_down;
		static const sf::Vector2u ghost_yellow_up;
		static const sf::Vector2u ghost_beige_down;
		static const sf::Vector2u ghost_beige_up;
		
		static const sf::Vector2u mine;
		static const sf::Vector2u handle_opened;
		static const sf::Vector2u handle_closed;
		static const sf::Vector2u enemy_calm;
		static const sf::Vector2u enemy_angry;
		
		static const sf::Vector2u drill;
		static const sf::Vector2u driil_up;
		static const sf::Vector2u drill_down;
		
		static const sf::Vector2u friend_small;
		static const sf::Vector2u friend_small_up;
		static const sf::Vector2u friend_small_down;
		static const sf::Vector2u friend_big;
		static const sf::Vector2u friend_big_up;
		static const sf::Vector2u friend_big_down;
		
		static const sf::Vector2u bat_wing_up;
		static const sf::Vector2u bat_wing_middle;
		static const sf::Vector2u bat_wing_down;
};