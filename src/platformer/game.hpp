#pragma once

#include <functional>

#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include "scene.hpp"
#include <platformer/utils/stateMachine.hpp>
#include <platformer/utils/listener.hpp>

class Game : public Listener<sf::Event>{
	private:
		StateMachine scenes;
		
		std::function<void(Scene&)> rendering[2];
		
		sf::Clock clock;
		bool active;
	public:
		Game();
		void run();
		
		void onNotify(const sf::Event& event) override;
};


