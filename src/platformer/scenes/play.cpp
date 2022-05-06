#include <SFML/Graphics/RectangleShape.hpp>
#include <platformer/framework.hpp>
#include <platformer/entities/physicalEntity.hpp>
#include <platformer/entities/world.hpp>
#include <platformer/entities/world/tiles.hpp>
#include <platformer/entities/player.hpp>
#include <platformer/utils/stateMachine.hpp>
#include "play.hpp"
#include "pause.h"

Play::Play(StateMachine& stateMachine, const std::shared_ptr<Level>& level) : Scene(stateMachine), level(level){
	view = sf::View(sf::Vector2f(300, 0), sf::Vector2f(Framework::getRenderer().getSize()));
}

void Play::onNotify(const sf::Event &event){
	if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		getStateMachine().add(new Pause(getStateMachine()));
}

void Play::update(const sf::Time &time){
    Scene::update(time);
	level->update(time);
}

void Play::draw(){
	Scene::draw();
	level->draw();
}

void Play::activate(){
	Scene::activate();
	level->activate();
	subscribe(&playerMonsterCollision);
	subscribe(&groundCollision);
	subscribe(&collectibleCollision);
}

void Play::deactivate(){
	Scene::deactivate();
	level->deactivate();
	unsubscribe(&playerMonsterCollision);
	unsubscribe(&groundCollision);
	unsubscribe(&collectibleCollision);
}
