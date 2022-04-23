#include "level.hpp"
#include "framework.hpp"
#include "platformer/entities/player.hpp"

void Level::update(const sf::Time& time){
	b2World.Step(time.asSeconds(), Framework::getPhysicConfig().velocityIterations, Framework::getPhysicConfig().positionIterations);
	if(world != nullptr)
		world->update(time);
	if(player != nullptr)
		player->update(time);
	for(auto& e : entities)
		e->update(time);
}

void Level::draw(){
	if(world != nullptr)
		Framework::getRenderer().draw(*world);
	if(player != nullptr)
		Framework::getRenderer().draw(*player);
	for(auto& e : entities)
		Framework::getRenderer().draw(*e);
}

void Level::load(const std::string& filename){

}

void Level::save(const std::string& filename){

}

Level::~Level(){
	delete player;
	delete world;
	for(auto& x : entities)
		delete x;
}

Level::Level() : b2World(Framework::getPhysicConfig().gravity){
	player = nullptr;
	world = nullptr;
	b2World.SetContactListener(&contactListener);
}

void Level::activate(){
	if(player != nullptr){
		Framework::getInputHandler().subscribe(player);
	}
}

void Level::deactivate(){
	if(player != nullptr){
		Framework::getInputHandler().unsubscribe(player);
	}
}
