#pragma once

#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include "box2d/box2d.h"
#include "entity.hpp"
#include "entityProperties.hpp"

class PhysicalEntity : public Entity{
	private:
		b2World& world;
	protected:
		b2Body* body;
		sf::Sprite sprite;
		int collisionPrecedence = 0;
		
		EntityProperties properties;
		
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		void jump();
		void stop();
		void moveLeft();
		void moveRight();
		
		const EntityProperties& getProperties() const;
		
		void update(const sf::Time& time) override;
		
		void create(const b2BodyDef& bodyDef);
		b2Fixture* addFixture(const b2FixtureDef& fixtureDef);
		
		virtual void contactBegin(PhysicalEntity& entity, b2Contact* contact);
		virtual void contactEnd(PhysicalEntity& entity, b2Contact* contact);
		
		int getCollisionPrecedence() const;
		
		PhysicalEntity(b2World& world,
					   const sf::Vector2i& position,
					   const sf::Vector2u& textureCoord,
					   const b2Vec2& hitboxCenter,
					   const b2Vec2& hitboxSize,
					   const EntityProperties& properties,
					   int collisionPrecedence = 0);
		
		PhysicalEntity(b2World& world,
				const EntityProperties& properties,
				int collisionPrecedence = 0);
};
