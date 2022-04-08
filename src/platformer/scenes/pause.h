#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include "../scene.hpp"
#include "../utils/stateMachine.hpp"
#include "play.hpp"

class Pause : public Scene{
	public:
		Pause(StateMachine& stateMachine);
		
		void onNotify(const sf::Event& event) override;
		void update(const sf::Time& time) override;
};