#pragma once

#include <vector>
#include <platformer/entities/player.hpp>
#include <platformer/entities/world.hpp>
#include <set>
#include <platformer/systems/contactListener.hpp>
#include "platformer/entities/entity.hpp"

class Level{
	private:
		ContactListener contactListener;
		b2World b2World;
		
		World* world;
		Player* player;
		std::set<PhysicalEntity*> entities;
	public:
		void load(const std::string& filename);
		void save(const std::string& filename);
		
		void update(const sf::Time& time);
		void draw();
		
		Level();
		~Level();
		
		void activate();
		void deactivate();
		
		friend class Editor;
};


