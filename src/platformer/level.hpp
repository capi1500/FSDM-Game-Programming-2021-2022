#pragma once

#include <vector>
#include <platformer/entities/player.hpp>
#include <platformer/entities/world.hpp>
#include <set>
#include <platformer/systems/contactListener.hpp>
#include "platformer/entities/entity.hpp"
#include <json.hpp>

using json = nlohmann::json;

class Level{
	private:
		ContactListener contactListener;
		b2World b2World;
		
		std::shared_ptr<World> world;
		std::shared_ptr<Player> player;
		std::set<std::shared_ptr<PhysicalEntity>> entities;
	public:
		void load(const std::string& filename);
		void save(const std::string& filename);
		
		void update(const sf::Time& time);
		void draw();
		
		Level();
		
		void activate();
		void deactivate();
		
		friend class Editor;
		friend void to_json(json& j, const Level& l);
		friend void from_json(const json& j, Level& l);
};

