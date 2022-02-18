#pragma once

#include <vector>
#include "box2d/box2d.h"
#include "entity.hpp"
#include "entityProperties.hpp"

class PhysicalEntity : public Entity{
	private:
		b2World& world;
		
	protected:
		b2Body* body;
		int collisionPrecedence = 0;
		
		EntityProperties properties;
		
		void jump();
		void stop();
		void moveLeft();
		void moveRight();
	public:
		const EntityProperties& getProperties() const;
		
		void update(const sf::Time& time) override;
		
		void create(const b2BodyDef& bodyDef);
		b2Fixture* addFixture(const b2FixtureDef& fixtureDef);
		
		virtual void contactBegin(PhysicalEntity& entity, b2Contact* contact);
		virtual void contactEnd(PhysicalEntity& entity, b2Contact* contact);
		
		int getCollisionPrecedence() const;
		
		PhysicalEntity(b2World& world);
};
