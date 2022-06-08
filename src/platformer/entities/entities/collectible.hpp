#pragma once

#include <platformer/entities/physicalEntity.hpp>

class Collectible : public PhysicalEntity{
	public:
		virtual void collect(PhysicalEntity& physicalEntity) = 0;
		void buildDefault(b2World& world, const sf::Vector2f& position);
		void build(b2World& world) override;
};


