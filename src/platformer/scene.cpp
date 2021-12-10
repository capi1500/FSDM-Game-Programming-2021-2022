#include "scene.hpp"
#include "framework.hpp"

Scene::Scene(StateMachine& stateMachine) : State(stateMachine){}

void Scene::update(const sf::Time& time){
	for(auto& e : entities)
		e->update(time);
	level.update(time);
}

void Scene::draw(){
	for(auto& e : entities)
		Framework::getRenderer().draw(*e);
	level.draw();
}

void Scene::activate(){
	State::activate();
	Framework::getInputHandler().subscribe(this);
}

void Scene::deactivate(){
	State::deactivate();
	Framework::getInputHandler().unsubscribe(this);
}
