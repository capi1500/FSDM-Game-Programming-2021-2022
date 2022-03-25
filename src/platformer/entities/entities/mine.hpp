#pragma once

#include <platformer/entities/physicalEntity.hpp>

class Mine : public PhysicalEntity{
	private:
		sf::Time timer;
		bool facingLeft = false;
	public:
		Mine(b2World& world, const sf::Vector2i& position);
		void update(const sf::Time& time) override;
};


