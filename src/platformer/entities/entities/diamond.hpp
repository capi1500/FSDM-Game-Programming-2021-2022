#pragma once

#include <platformer/entities/physicalEntity.hpp>

class Diamond : public PhysicalEntity{
	public:
		Diamond(b2World& world, const sf::Vector2i& position);
};


