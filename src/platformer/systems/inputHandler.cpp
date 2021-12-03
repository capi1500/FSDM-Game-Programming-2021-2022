#include <platformer/framework.hpp>
#include "inputHandler.hpp"

void InputHandler::handleEvents(){
	sf::Event event;
	while(Framework::getRenderer().pollEvent(event))
		send(event);
	processEvents();
}
