#pragma once

#include <vector>
#include "entity.hpp"

class Level{
	private:
		std::vector<Entity*> entities;
	public:
		void update(const sf::Time& time);
		void draw();
};


