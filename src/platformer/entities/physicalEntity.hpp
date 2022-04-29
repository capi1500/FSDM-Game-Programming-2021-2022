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

void to_json(json& j, const b2BodyDef& b2);
void from_json(const json& j, b2BodyDef& b2);
void to_json(json& j, const b2FixtureDef& b2);
void from_json(const json& j, b2FixtureDef& b2);
void to_json(json& j, const b2Shape& b2);
void from_json(const json& j, b2Shape*& b2);
void to_json(json& j, const b2Vec2& b2);
void from_json(const json& j, b2Vec2& b2);
template<class T>
void to_json(json& j, const sf::Vector2<T>& vec);
template<class T>
void from_json(const json& j, sf::Vector2<T>& vec);
