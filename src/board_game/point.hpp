#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "board.hpp"
#include "player.hpp"

class Point : public sf::Drawable{
	private:
		static sf::CircleShape* circle;
		
		sf::Vector2i pos;
		Board& board;
		sf::Vector2f getCenter() const;
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		Point(Board& board, const Player& player);
		
		void randomPlace(const Player& player);
		const sf::Vector2i& getPos() const;
		static void init();
		static void clear();
};


