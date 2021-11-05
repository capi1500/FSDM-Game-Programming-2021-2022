#include "player.hpp"
#include <SFML/Window/Event.hpp>

Player::Player(Board& b, int x, int y) : board(b){
	pos.x = x;
	pos.y = y;
	points = 0;
	circle.setRadius(20);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Black);
	circle.setOutlineThickness(3);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	sf::Vector2f center = getCenter();
	states.transform.translate(center.x - circle.getRadius(), center.y - circle.getRadius());
	target.draw(circle, states);
}

sf::Vector2f Player::getCenter() const{
	return sf::Vector2f(pos.x * board.getTileSize() + board.getTileSize() / 2, pos.y * board.getTileSize() + board.getTileSize() / 2);
}

void Player::handleEvent(const sf::Event& event){
	if(event.type == sf::Event::KeyPressed){
		sf::Vector2i delta(0, 0);
		switch(event.key.code){
			case sf::Keyboard::W:
				delta.y = -1;
				break;
			case sf::Keyboard::A:
				delta.x = -1;
				break;
			case sf::Keyboard::S:
				delta.y = 1;
				break;
			case sf::Keyboard::D:
				delta.x = 1;
				break;
		}
		if(board.isCoordinateOk(pos + delta)){
			pos += delta;
		}
	}
}
