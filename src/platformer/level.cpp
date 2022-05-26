#include <fstream>
#include <platformer/utils/filepath.hpp>
#include "level.hpp"
#include "framework.hpp"
#include "platformer/entities/player.hpp"

void Level::update(const sf::Time& time){
	b2World->Step(time.asSeconds(), Framework::getPhysicConfig().velocityIterations, Framework::getPhysicConfig().positionIterations);
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

Level::Level(){
	b2World = new class b2World(Framework::getPhysicConfig().gravity);
	player = nullptr;
	world = nullptr;
	b2World->SetContactListener(&contactListener);
}

void Level::activate(){
	if(player != nullptr){
		Framework::getInputHandler().subscribe(player.get());
	}
}

void Level::deactivate(){
	if(player != nullptr){
		Framework::getInputHandler().unsubscribe(player.get());
	}
}

void Level::load(const std::string& filename){
	std::ifstream file(filename);
	json j;
	file >> j;
	file.close();
	from_json(j, *this);
}

void Level::save(const std::string& filename) const{
	json j = *this;
	std::ofstream file(filename);
	file << j << "\n";
	file.close();
}

Level::~Level(){
	delete b2World;
}
