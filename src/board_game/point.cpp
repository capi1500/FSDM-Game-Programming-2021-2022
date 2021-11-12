#include "point.hpp"

sf::CircleShape* Point::circle;

void Point::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	sf::Vector2f center = getCenter();
	states.transform.translate(center.x - circle->getRadius(),
							   center.y - circle->getRadius());
	target.draw(*circle, states);
}

sf::Vector2f Point::getCenter() const{
	return sf::Vector2f(pos.x * board.getTileSize() + board.getTileSize() / 2,
						pos.y * board.getTileSize() + board.getTileSize() / 2);
}

Point::Point(Board& board, const Player& player) : board(board){
	randomPlace(player);
}

void Point::randomPlace(const Player& player){
	do{
		pos.x = rand() % (board.getSize().x);
		pos.y = rand() % (board.getSize().y);
	} while(pos == player.getPos() || player.isOnTail(pos));
}

void Point::init(){
	circle = new sf::CircleShape();
	circle->setRadius(20);
	circle->setFillColor(sf::Color::Red);
	circle->setOutlineColor(sf::Color::Black);
	circle->setOutlineThickness(3);
}

void Point::clear(){
	delete circle;
}

const sf::Vector2i& Point::getPos() const{
	return pos;
}
