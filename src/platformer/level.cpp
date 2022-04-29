#include <fstream>
#include <iostream>
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

Level::Level() : b2World(Framework::getPhysicConfig().gravity){
	player = nullptr;
	world = nullptr;
	b2World.SetContactListener(&contactListener);
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
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	
	json j = buffer.str();
	std::cout << j << "\n";
	(*this) = j.get<Level>();
}

void Level::save(const std::string& filename){
	json j = *this;
	std::cout << j << "\n";
	
	std::ofstream file(filename);
	file << j << "\n";
	file.close();
}

void to_json(json& j, const Level& l){

}

void from_json(const json& j, Level& l){
	WorldBuilder wb = j.at("world").get<WorldBuilder>();
	l.world = std::make_shared<World>(wb.create(l.b2World));
	
	l.player = std::make_shared<Player>(j.at("player").get<Player>());
}
