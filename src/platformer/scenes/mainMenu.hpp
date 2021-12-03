#pragma once

#include "../scene.hpp"

class MainMenu : public Scene{
	public:
		MainMenu(StateMachine& stateMachine);
		void onNotify(const sf::Event& event) override;
};


