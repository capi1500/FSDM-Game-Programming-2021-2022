#pragma once

#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include "box2d/box2d.h"
#include "entity.hpp"
#include "entityProperties.hpp"
#include <json.hpp>

using json = nlohmann::json;

class PhysicalEntity : public Entity{
	private:
		std::reference_wrapper<b2World> world;
		
		b2Vec2 hitboxCenter;
		b2Vec2 hitboxSize;
		sf::Vector2i position;
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
		
		void build(b2World& world);
		
		friend void to_json(json& j, const PhysicalEntity& p);
		friend void from_json(const json& j, PhysicalEntity& p);
};
