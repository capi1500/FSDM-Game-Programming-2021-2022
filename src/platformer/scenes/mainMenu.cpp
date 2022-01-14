#include <iostream>
#include <platformer/framework.hpp>
#include "mainMenu.hpp"
#include "../utils/stateMachine.hpp"
#include "play.hpp"

MainMenu::MainMenu(StateMachine& stateMachine) : Scene(stateMachine){
	Framework::getAssetStorage().loadTexture("red", "../assets/textures/rgb/red.png");
	Framework::getAssetStorage().loadTexture("green", "../assets/textures/rgb/green.png");
	Framework::getAssetStorage().loadTexture("blue", "../assets/textures/rgb/blue.png");
	Framework::getAssetStorage().loadSound("click", "../assets/sounds/ClickSound.wav");
	Framework::getSoundboard().setSize(10);
	
	Button* button = new Button;
	button->move(200, 200);
	button->getSprite().setTexture(Framework::getAssetStorage().getTexture("red"));
	button->getText().setFont(Framework::getAssetStorage().getFont("pixeled"));
	button->getText().setCharacterSize(20);
	button->getText().setString("Hello world");
	
	button->setOnHoverStart([button]{
		button->getSprite().setTexture(Framework::getAssetStorage().getTexture("green"));
	});
	button->setOnHoverEnd([button]{
		button->getSprite().setTexture(Framework::getAssetStorage().getTexture("red"));
	});
	button->setOnButtonPressed([button]{
		std::cout << "Button pressed\n";
		button->getSprite().setTexture(Framework::getAssetStorage().getTexture("blue"));
	});
	button->setOnButtonReleased([button, this]{
		std::cout << "Button released\n";
		button->getSprite().setTexture(Framework::getAssetStorage().getTexture("red"));
        getStateMachine().replace(new Play(getStateMachine()));
	});
	
	entities.push_back(button);
}

void MainMenu::onNotify(const sf::Event& event){
	if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space){
		auto& s = Framework::getSoundboard().getNext();
		s.setBuffer(Framework::getAssetStorage().getSound("click"));
		s.play();
	}
}