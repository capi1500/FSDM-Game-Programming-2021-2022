#include <iostream>
#include "board.hpp"

Board::Board(int sizeX, int sizeY) : size(sizeX, sizeY){
	tile.setSize(sf::Vector2f(60, 60));
	tile.setFillColor(sf::Color::White);
	tile.setOutlineColor(sf::Color::Black);
	tile.setOutlineThickness(3);
	tileRed.setSize(sf::Vector2f(60, 60));
	tileRed.setFillColor(sf::Color(127, 127, 127));
	tileRed.setOutlineColor(sf::Color::Black);
	tileRed.setOutlineThickness(3);
}

/**
 * @brief Coordinate is ok if: 0 <= x < sizeX, 0 <= y < sizeY
 * @param x - coord X
 * @param y - coord Y
 * @return 0 <= x < sizeX and 0 <= y < sizeY
 */
bool Board::isCoordinateOk(sf::Vector2i coord) const{
	return (0 <= coord.x && coord.x < size.x) && (0 <= coord.y && coord.y < size.y);
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	for(int x = 0; x < size.x; x++){
		for(int y = 0; y < size.y; y++){
			target.draw(((x + y) % 2 == 0) ? tile : tileRed, states);
			states.transform.translate(0, tile.getSize().y);
		}
		states.transform.translate(tile.getSize().x, -size.y * tile.getSize().y);
	}
}

float Board::getTileSize() const{
	return tile.getSize().x;
}

const sf::Vector2i& Board::getSize() const{
	return size;
}
