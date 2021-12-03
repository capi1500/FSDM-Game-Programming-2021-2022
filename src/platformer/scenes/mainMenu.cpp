#include <iostream>
#include "mainMenu.hpp"

MainMenu::MainMenu(StateMachine& stateMachine) : Scene(stateMachine){}

void MainMenu::onNotify(const sf::Event& event){
	if(event.type == sf::Event::MouseButtonPressed){
		std::cout << "Mouse button pressed\n";
	}
}
