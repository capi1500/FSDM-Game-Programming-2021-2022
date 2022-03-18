#include "scene.hpp"
#include "framework.hpp"
#include "scenes/events/sceneEvent.hpp"

Scene::Scene(StateMachine& stateMachine) : State(stateMachine){
	view = Framework::getRenderer().getDefaultView();
}

void Scene::update(const sf::Time& time){
	for(auto& e : entities)
		e->update(time);
	level.update(time);
	Framework::getEventHandler().processEvents();
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
	Framework::getEventHandler().subscribe(this);
	for(auto& e : entities){
		e->activate();
	}
}

void Scene::deactivate(){
	State::deactivate();
	view = Framework::getRenderer().getView();
	Framework::getInputHandler().unsubscribe(this);
	Framework::getEventHandler().unsubscribe(this);
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

void Scene::onNotify(const std::shared_ptr<SceneEvent>& event){
	event->scene = this;
	sendNow(event);
}
