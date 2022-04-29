#pragma once

#include "physicalEntity.hpp"
#include "platformer/utils/listener.hpp"
#include <SFML/Window/Event.hpp>
#include <json.hpp>

using json = nlohmann::json;

class Player : public PhysicalEntity, public Listener<sf::Event>{
	public:
		Player(b2World& world, const sf::Vector2i& position);
		
		void onNotify(const sf::Event& event) override;
		void update(const sf::Time& time) override;
		
		friend void to_json(json& j, const Player& p);
		friend void from_json(const json& j, Player& p);
};


