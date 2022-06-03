#include <SFML/Graphics/RectangleShape.hpp>
#include <platformer/framework.hpp>
#include <platformer/entities/physicalEntity.hpp>
#include <platformer/entities/world.hpp>
#include <platformer/entities/world/tiles.hpp>
#include <platformer/entities/player.hpp>
#include <platformer/utils/stateMachine.hpp>
#include <iostream>
#include "play.hpp"
#include "pause.h"

Play::Play(StateMachine& stateMachine, const std::string& level) : Scene(stateMachine){
	this->level.load("../saves/" + level + ".json");
	levelBackup = level;
	
	auto s = Framework::getRenderer().getSize();
	gui_view = sf::View(sf::Vector2f(300, 0), sf::Vector2f(s.x, s.y));
	gui_view.zoom(0.25);
}

void Play::onNotify(const sf::Event &event){
	if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		getStateMachine().add(new Pause(getStateMachine(), *this));
}

void Play::update(const sf::Time &time){
    Scene::update(time);
	level.update(time);
}

void Play::draw(sf::RenderStates renderStates){
	view.setCenter(level.getPlayer()->getPosition().x, level.getPlayer()->getPosition().y);
	Framework::getRenderer().setView(view);

	Scene::draw();
	level.draw(renderStates);
	
	sf::View gui_view = Framework::getRenderer().getDefaultView();
	Framework::getRenderer().setView(gui_view);
	renderStates.transform.scale(4, 4);
	Framework::getRenderer().draw(gui, renderStates);
}

void Play::activate(){
	Scene::activate();
	level.activate();
	subscribe(&playerMonsterCollision);
	subscribe(&groundCollision);
	subscribe(&collectibleCollision);
	view = gui_view;
}

void Play::deactivate(){
	Scene::deactivate();
	level.deactivate();
	unsubscribe(&playerMonsterCollision);
	unsubscribe(&groundCollision);
	unsubscribe(&collectibleCollision);
}

const Level& Play::getLevel() const{
	return level;
}

const std::string& Play::getLevelBackup() const{
	return levelBackup;
}
