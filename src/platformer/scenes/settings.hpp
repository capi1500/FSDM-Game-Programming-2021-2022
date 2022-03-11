#pragma once

#include <platformer/scene.hpp>
#include <platformer/gui/radioButtonGroup.hpp>

class Settings : public Scene{
	private:
		RadioButtonGroup group;
	public:
		Settings(StateMachine& stateMachine);
		void onNotify(const sf::Event& event) override;
};


