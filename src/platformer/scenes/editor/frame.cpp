#include <SFML/Graphics/RenderTarget.hpp>
#include "frame.hpp"

void Frame::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	if(visible){
		states.transform.combine(getTransform());
		target.draw(shape, states);
	}
}

void Frame::setBaseSize(const sf::Vector2f& size){
	base_size = size;
}

void Frame::setSize(const sf::Vector2f& size){
	shape.setSize(size);
	shape.setPosition(-size.x / 2 + base_size.x / 2, -size.y / 2 + base_size.y / 2);
}

void Frame::setPosition(const sf::Vector2f& position){
	Transformable::setPosition(position);
}

Frame::Frame(){
	shape.setOutlineColor(sf::Color::White);
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineThickness(2);
}

void Frame::update(const sf::Time& time){

}
