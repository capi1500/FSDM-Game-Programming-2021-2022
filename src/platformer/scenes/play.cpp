#include <SFML/Graphics/RectangleShape.hpp>
#include <platformer/framework.hpp>
#include <platformer/entities/PhysicalEntity.hpp>
#include <platformer/entities/world.hpp>
#include "play.hpp"

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
	
	entities.push_back(
			WorldBuilder(b2World, {5, 5})
					.setTile({0, 0}, names.golden_brick, true)
					.setTile({3, 3}, names.grass_left, true)
					.create_ptr()
	);
}

void Play::onNotify(const sf::Event &event) {

}

void Play::update(const sf::Time &time) {
    Scene::update(time);
    b2World.Step(time.asSeconds(), Framework::getPhysicConfig().velocityIterations, Framework::getPhysicConfig().positionIterations);
}
