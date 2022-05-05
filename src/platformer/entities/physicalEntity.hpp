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
        b2BodyDef bodyDef;
        std::vector<b2FixtureDef> fixtureDefs;
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

		virtual void contactBegin(PhysicalEntity& entity, b2Contact* contact);
		virtual void contactEnd(PhysicalEntity& entity, b2Contact* contact);
		
		virtual void build(b2World& world);
		
		friend void to_json(json& j, const PhysicalEntity& p);
		friend void from_json(const json& j, PhysicalEntity& p);
};
