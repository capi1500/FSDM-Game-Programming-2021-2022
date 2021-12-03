#pragma once

#include <SFML/Window/Event.hpp>
#include <platformer/utils/emitter.hpp>

class InputHandler : public Emitter<sf::Event>{
	public:
		void handleEvents();
};


