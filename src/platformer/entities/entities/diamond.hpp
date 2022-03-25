#pragma once

#include "collectible.hpp"

class Diamond : public Collectible{
	public:
		Diamond(b2World& world, const sf::Vector2i& position);
		void collect(PhysicalEntity& physicalEntity) override;
};


