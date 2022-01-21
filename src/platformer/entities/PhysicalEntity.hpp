#pragma once

#include <vector>
#include "box2d/box2d.h"
#include "entity.hpp"

class PhysicalEntity : public Entity{
	private:
		b2World& world;
	protected:
		b2Body* body;
	public:
		void update(const sf::Time& time) override;
		
		void create(const b2BodyDef& bodyDef);
		b2Fixture* addFixture(const b2FixtureDef& fixtureDef);
		
		PhysicalEntity(b2World& world);
};
