#include <iostream>
#include <platformer/gui/longButton.hpp>
#include "pause.h"
#include "../framework.hpp"
#include "play.hpp"
#include "settings.hpp"
#include "levelChooser.hpp"
#include "levelSaver.hpp"

Pause::Pause(StateMachine& stateMachine, Play& play) : Scene(stateMachine){
	float centerX = Framework::getRenderer().getSize().x / 2, centerY = Framework::getRenderer().getSize().y / 2;
	
	LongButton* playButton = new LongButton(
			{centerX, centerY - 184},
			"Resume",
			[this]{
				getStateMachine().pop();
			});
	LongButton* restartButton = new LongButton(
			{centerX, centerY - 92},
			"Restart",
			[this, &play]{
				getStateMachine().pop();
				getStateMachine().replace(new Play(getStateMachine(), play.getLevelBackup()));
			});
	LongButton* loadButton = new LongButton(
			{centerX, centerY},
			"Load",
			[this, &play]{
				getStateMachine().replace(new LevelChooser(getStateMachine(), [&play](const std::string& path){
					if(play.getLevelBackup() != path)
						Framework::getEventHandler().send(std::make_shared<SceneEvent>(Play::LevelStarted));
					play.getStateMachine().replace(new Play(play.getStateMachine(), path));
				}));
			});
	LongButton* saveButton = new LongButton(
			{centerX, centerY + 92},
			"Save",
			[this, &play]{
				getStateMachine().add(new LevelSaver(getStateMachine(), play.getLevel()));
			});
	LongButton* settingsButton = new LongButton(
			{centerX, centerY + 184},
			"Settings",
			[this]{
				getStateMachine().add(new Settings(getStateMachine()));
			});
	LongButton* returnButton = new LongButton(
			{centerX, centerY + 184 + 92},
			"End game",
			[this]{
				getStateMachine().pop();
				getStateMachine().pop();
			});
	LongButton* quitButton = new LongButton(
			{centerX, centerY + 184 + 184},
			"Quit",
			[this]{
				getStateMachine().pop();
				sf::Event event;
				event.type = sf::Event::Closed;
				Framework::getInputHandler().send(event);
			});
	
	entities.push_back(playButton);
	entities.push_back(restartButton);
	entities.push_back(loadButton);
	entities.push_back(saveButton);
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