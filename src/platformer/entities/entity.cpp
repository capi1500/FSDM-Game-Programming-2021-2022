#include <platformer/framework.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "entity.hpp"

void Entity::activate(){

}

void Entity::deactivate(){

}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	if(visible){
		states.transform.combine(getTransform());
		target.draw(sprite, states);
	}
}

void Entity::hide(){
	visible = false;
}

void Entity::show(){
	visible = true;
}
