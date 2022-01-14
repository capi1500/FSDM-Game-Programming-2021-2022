#pragma once

#include <vector>
#include "platformer/entities/entity.hpp"

class Level{
	private:
		std::vector<Entity*> entities;
	public:
		void update(const sf::Time& time);
		void draw();
};


