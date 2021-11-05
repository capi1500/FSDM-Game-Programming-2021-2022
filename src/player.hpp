#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include "board.hpp"

class Player : public sf::Drawable{
	private:
		sf::Vector2i pos;
		int points;
		sf::CircleShape circle;
		Board& board;
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		void handleEvent(const sf::Event& event);
		
		sf::Vector2f getCenter() const;
		
		Player(Board& b, int x, int y);
};
