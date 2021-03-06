#include "player.hpp"
#include <SFML/Window/Event.hpp>
#include <platformer/entities/physicalEntity.hpp>

int Player::dx[4] = {0, 1, 0, -1};
int Player::dy[4] = {-1, 0, 1, 0};

Player::Player(Board& b, int x, int y) : board(b){
	pos.x = x;
	pos.y = y;
	points = 0;
	circle.setRadius(20);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Black);
	circle.setOutlineThickness(3);

	tail.setRadius(20);
	tail.setFillColor(sf::Color::Green);
	tail.setOutlineColor(sf::Color::Black);
	tail.setOutlineThickness(3);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	sf::Vector2f center = getCenter();
	states.transform.translate(center.x - circle.getRadius(), center.y - circle.getRadius());
	target.draw(circle, states);
	states.transform.translate(-center.x + circle.getRadius(), -center.y + circle.getRadius());
	for(const sf::Vector2i& p : tailPos){
		center = getCenter(p);
		states.transform.translate(center.x - tail.getRadius(), center.y - tail.getRadius());
		target.draw(tail, states);
		states.transform.translate(-center.x + tail.getRadius(), -center.y + tail.getRadius());
	}
}

sf::Vector2f Player::getCenter(const sf::Vector2i& p) const{
	return sf::Vector2f(p.x * board.getTileSize() + board.getTileSize() / 2, p.y * board.getTileSize() + board.getTileSize() / 2);
}

sf::Vector2f Player::getCenter() const{
	return getCenter(pos);
}

void Player::handleEvent(const sf::Event& event){
	if(event.type == sf::Event::KeyPressed){
		switch(event.key.code){
			case sf::Keyboard::W:
				dir = Up;
				break;
			case sf::Keyboard::A:
				dir = Left;
				break;
			case sf::Keyboard::S:
				dir = Down;
				break;
			case sf::Keyboard::D:
				dir = Right;
				break;
			default:
				break;
		}
	}
}

bool Player::update(const sf::Time& time){
	timeFromLastMove += time;
	while(timeToNextChange <= timeFromLastMove){
		timeFromLastMove -= timeToNextChange;
		
		sf::Vector2i delta(0, 0);
		
		switch(dir){
			case Up:
				delta.y = -1;
				break;
			case Down:
				delta.y = 1;
				break;
			case Left:
				delta.x = -1;
				break;
			case Right:
				delta.x = 1;
				break;
		}
		
		tailPos.push_front(pos);
		while(tailPos.size() > points + 2){
			tailPos.pop_back();
		}
		pos += delta;
		
		if(isOnTail(getPos()) || !board.isCoordinateOk(pos))
			return false;
	}
	return true;
}

const sf::Vector2i& Player::getPos() const{
	return pos;
}

void Player::pointGet(){
	points++;
}

bool Player::isOnTail(const sf::Vector2i& pos) const{
	for(const sf::Vector2i& p : tailPos){
		if(p == pos)
			return true;
	}
	return false;
}
