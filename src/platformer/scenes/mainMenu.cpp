#include <iostream>
#include <platformer/framework.hpp>
#include <platformer/gui/longButton.hpp>
#include "mainMenu.hpp"
#include "../utils/stateMachine.hpp"
#include "play.hpp"
#include "settings.hpp"
#include "editor.hpp"

MainMenu::MainMenu(StateMachine& stateMachine) : Scene(stateMachine){
	Framework::getAssetStorage().loadTexture("red", "../assets/textures/rgb/red.png");
	Framework::getAssetStorage().loadTexture("green", "../assets/textures/rgb/green.png");
	Framework::getAssetStorage().loadTexture("blue", "../assets/textures/rgb/blue.png");
	Framework::getAssetStorage().loadSound("click", "../assets/sounds/ClickSound.wav");
	Framework::getAssetStorage().loadTexture("ui_pack", "../assets/textures/ui/Spritesheet/greenSheet.png");
	Framework::getSoundboard().setSize(10);
	
	float centerX = Framework::getRenderer().getSize().x / 2, centerY = Framework::getRenderer().getSize().y / 2;
	LongButton* playButton = new LongButton(
			{centerX, centerY - 92},
			"Play",
			[this]{
				Level* l = new Level();
				l->load("../saves/save.json");
				getStateMachine().add(new Play(getStateMachine(), l));
			});
	LongButton* editorButton = new LongButton(
			{centerX, centerY},
			"Editor",
			[this]{
				getStateMachine().add(new Editor(getStateMachine()));
			});
	LongButton* settingsButton = new LongButton(
			{centerX, centerY + 92},
			"Settings",
			[this]{
				getStateMachine().add(new Settings(getStateMachine()));
			});
	LongButton* quitButton = new LongButton(
			{centerX, centerY + 184},
			"Quit",
			[this]{
				sf::Event event;
				event.type = sf::Event::Closed;
				Framework::getInputHandler().send(event);
			});
	
	entities.push_back(playButton);
	entities.push_back(editorButton);
	entities.push_back(settingsButton);
	entities.push_back(quitButton);
}

void MainMenu::onNotify(const sf::Event& event){
	if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space){
		auto& s = Framework::getSoundboard().getNext();
		s.setBuffer(Framework::getAssetStorage().getSound("click"));
		s.play();
	}
}