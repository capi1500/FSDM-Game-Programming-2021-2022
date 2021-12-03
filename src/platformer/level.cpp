#include "level.hpp"
#include "framework.hpp"

void Level::update(const sf::Time& time){
	for(auto& e : entities)
		e->update(time);
}

void Level::draw(){
	for(auto& e : entities)
		Framework::getRenderer().draw(*e);
}
