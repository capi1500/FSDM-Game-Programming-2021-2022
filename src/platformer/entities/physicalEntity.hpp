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
		
		EntityProperties properties;
	public:
		void jump();
		void stop();
		void moveLeft();
		void moveRight();
		void setMovingLeft();
		void setMovingRight();
		
		const EntityProperties& getProperties() const;
		EntityProperties& getProperties();
		
		void update(const sf::Time& time) override;
		
		void create(const b2BodyDef& bodyDef);
		b2Fixture* addFixture(const b2FixtureDef& fixtureDef);
		
		virtual void contactBegin(PhysicalEntity& entity, b2Contact* contact);
		virtual void contactEnd(PhysicalEntity& entity, b2Contact* contact);
		
		PhysicalEntity(b2World& world, const sf::Vector2i& position, const TextureInfo& textureInfo, const sf::Vector2u& textureCoord, const b2Vec2& hitboxCenter, const b2Vec2& hitboxSize, const EntityProperties& properties);
		PhysicalEntity(b2World& world);
};
