#include <SFML/Graphics/RectangleShape.hpp>
#include <platformer/framework.hpp>
#include <platformer/entities/physicalEntity.hpp>
#include <platformer/entities/world.hpp>
#include <platformer/entities/world/tiles.hpp>
#include <platformer/entities/player.hpp>
#include <platformer/utils/stateMachine.hpp>
#include <platformer/utils/emitter.hpp>
#include <platformer/entities/entities/mine.hpp>
#include <platformer/entities/entities/diamond.hpp>
#include "play.hpp"
#include "pause.h"

Play::Play(StateMachine &stateMachine) : Scene(stateMachine), b2World(Framework::getPhysicConfig().gravity) {
	tiles.setTexture(Framework::getAssetStorage().getTexture("tiles"));
	tiles.setTextureSize({18, 18});
	tiles.setOffset({2, 2});
	
	background.setTexture(Framework::getAssetStorage().getTexture("background"));
	background.setTextureSize({24, 24});
	background.setOffset({2, 2});
	
	characters.setTexture(Framework::getAssetStorage().getTexture("characters"));
	characters.setTextureSize({24, 24});
	characters.setOffset({2, 2});
	
	ui.setTexture(Framework::getAssetStorage().getTexture("rpg ui"));
	ui.setTextureSize({18, 18});
	ui.setOffset({2, 2});
	
	sf::Vector2u size = {25, 3};
	WorldBuilder builder(b2World, size);
	
	builder.setTile({10, 0}, Tiles::grass_flat_left, true);
	builder.setTile({15, 0}, Tiles::grass_flat_right, true);
	for(unsigned x = 11; x < 15; x++)
		builder.setTile({x, 0}, Tiles::grass_flat_middle, true);
	
	builder.setTile({5, 1}, Tiles::grass_flat_left, true);
	builder.setTile({20, 1}, Tiles::grass_flat_right, true);
	for(unsigned x = 6; x < 20; x++)
		builder.setTile({x, 1}, Tiles::grass_flat_middle, true);
	
	builder.setTile({0, 2}, Tiles::grass_flat_left, true);
	builder.setTile({size.x - 1, 2}, Tiles::grass_flat_right, true);
	for(unsigned x = 1; x < size.x - 1; x++)
		builder.setTile({x, 2}, Tiles::grass_flat_middle, true);
	
	entities.push_back(builder.create_ptr());
	
	p = new Player(b2World, {0, 1});
	entities.push_back(p);
	entities.push_back(new Mine(b2World, {5, -5}));
	entities.push_back(new Diamond(b2World, {10, -5}));
	
	view = sf::View(sf::Vector2f(300, 0), sf::Vector2f(Framework::getRenderer().getSize()));
	
	b2World.SetContactListener(&contactListener);
}

void Play::onNotify(const sf::Event &event){
	p->onNotify(event);
	if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		getStateMachine().add(new Options(getStateMachine()));
}

void Play::update(const sf::Time &time){
    Scene::update(time);
    b2World.Step(time.asSeconds(), Framework::getPhysicConfig().velocityIterations, Framework::getPhysicConfig().positionIterations);
}

void Play::activate(){
	Scene::activate();
	subscribe(&playerMonsterCollision);
	subscribe(&groundCollision);
}

void Play::deactivate(){
	Scene::deactivate();
	unsubscribe(&playerMonsterCollision);
	unsubscribe(&groundCollision);
}
