#include "scene.hpp"
#include "framework.hpp"

Scene::Scene(StateMachine& stateMachine) : State(stateMachine){
	view = Framework::getRenderer().getDefaultView();
}

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
	Framework::getRenderer().setView(view);
	Framework::getInputHandler().subscribe(this);
	for(auto& e : entities){
		e->activate();
	}
}

void Scene::deactivate(){
	State::deactivate();
	view = Framework::getRenderer().getView();
	Framework::getInputHandler().unsubscribe(this);
	for(auto& e : entities){
		e->deactivate();
	}
}

Scene::~Scene(){
	for(auto& e : entities){
		delete e;
		e = nullptr;
	}
}
