#include <iostream>
#include <platformer/gui/longButton.hpp>
#include "pause.h"
#include "../framework.hpp"
#include "play.hpp"
#include "settings.hpp"

Pause::Pause(StateMachine& stateMachine) : Scene(stateMachine){
	float centerX = Framework::getRenderer().getSize().x / 2, centerY = Framework::getRenderer().getSize().y / 2;
	
	LongButton* playButton = new LongButton(
			{centerX, centerY - 92},
			"Resume",
			[this]{
				getStateMachine().pop();
			});
	LongButton* restartButton = new LongButton(
			{centerX, centerY},
			"Restart",
			[this]{
				getStateMachine().pop();
				getStateMachine().replace(new Play(getStateMachine(), new Level())); // TODO: fix level
			});
	LongButton* settingsButton = new LongButton(
			{centerX, centerY + 92},
			"Settings",
			[this]{
				getStateMachine().add(new Settings(getStateMachine()));
			});
	LongButton* returnButton = new LongButton(
			{centerX, centerY + 184},
			"End game",
			[this]{
				getStateMachine().pop();
				getStateMachine().pop();
			});
	LongButton* quitButton = new LongButton(
			{centerX, centerY + 184 + 92},
			"Quit",
			[this]{
				getStateMachine().pop();
				sf::Event event;
				event.type = sf::Event::Closed;
				Framework::getInputHandler().send(event);
			});
	
	entities.push_back(playButton);
	entities.push_back(restartButton);
	entities.push_back(settingsButton);
	entities.push_back(returnButton);
	entities.push_back(quitButton);
}

void Pause::onNotify(const sf::Event& event){
	if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		getStateMachine().pop();
}

void Pause::update(const sf::Time& time){
	Scene::update(time);
}