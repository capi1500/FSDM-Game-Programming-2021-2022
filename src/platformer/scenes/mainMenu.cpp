#include <iostream>
#include <platformer/framework.hpp>
#include "mainMenu.hpp"

MainMenu::MainMenu(StateMachine& stateMachine) : Scene(stateMachine){
	Framework::getAssetStorage().loadTexture("red", "../assets/textures/rgb/red.png");
	Framework::getAssetStorage().loadTexture("green", "../assets/textures/rgb/green.png");
	Framework::getAssetStorage().loadTexture("blue", "../assets/textures/rgb/blue.png");
	
	Button* button = new Button;
	button->setTexture(Framework::getAssetStorage().getTexture("red"));
	button->setOnHoverStart([button]{
		button->setTexture(Framework::getAssetStorage().getTexture("green"));
	});
	button->setOnHoverEnd([button]{
		button->setTexture(Framework::getAssetStorage().getTexture("red"));
	});
	button->setOnButtonPressed([button]{
		std::cout << "Button pressed\n";
		button->setTexture(Framework::getAssetStorage().getTexture("blue"));
	});
	button->setOnButtonReleased([button]{
		std::cout << "Button released\n";
		button->setTexture(Framework::getAssetStorage().getTexture("red"));
	});
	
	entities.push_back(button);
}

void MainMenu::onNotify(const sf::Event& event){

}