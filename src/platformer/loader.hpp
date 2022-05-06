#pragma once

#include <json.hpp>
#include <box2d/box2d.h>

using json = nlohmann::json;

void to_json(json& j, const EntityProperties::JumpProperty& p);
void from_json(const json& j, EntityProperties::JumpProperty& p);
void to_json(json& j, const EntityProperties::MovementProperty& p);
void from_json(const json& j, EntityProperties::MovementProperty& p);
void to_json(json& j, const EntityProperties& p);
void from_json(const json& j, EntityProperties& p);
void to_json(json& j, const EntityProperties::EntityType& p);
void from_json(const json& j, EntityTypeBuilder& p);

void to_json(json& j, const TileConfig& c);
void from_json(const json& j, TileConfig& c);

namespace sf{
	template<typename T>
	void to_json(json& j, const Vector2<T>& vec);
	template<typename T>
	void from_json(const json& j, Vector2<T>& vec);
	void to_json(json& j, const Transformable& t);
	void from_json(const json& j, Transformable& t);
}

void to_json(json& j, const b2Body& b2);
void from_json(const json& j, b2BodyDef& b2);
void to_json(json& j, const b2Fixture& b2);
void from_json(const json& j, b2FixtureDef& b2);
void to_json(json& j, const b2Shape& b2);
void from_json(const json& j, b2Shape*& b2);
void to_json(json& j, const b2Vec2& b2);
void from_json(const json& j, b2Vec2& b2);