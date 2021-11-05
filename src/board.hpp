#pragma once

#include <vector>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Board : public sf::Drawable{
	private:
		sf::Vector2i size;
		sf::RectangleShape tile;
		sf::RectangleShape tileRed;
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		bool isCoordinateOk(sf::Vector2i y) const;
		float getTileSize() const;
		
		Board(int sizeX, int sizeY);
};
