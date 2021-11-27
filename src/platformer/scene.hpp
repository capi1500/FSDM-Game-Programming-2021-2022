#pragma once

#include <SFML/System/Time.hpp>
#include <platformer/utils/state.hpp>

class Scene : public State{
	private:
	public:
		void update(const sf::Time& time);
		void draw();
};


