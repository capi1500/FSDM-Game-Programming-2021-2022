#pragma once

#include <platformer/gui/button.hpp>
#include "../scene.hpp"

class MainMenu : public Scene{
	public:
		MainMenu(StateMachine& stateMachine);
		void onNotify(const sf::Event& event) override;
};


