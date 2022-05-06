#include <platformer/entities/physicalEntity.hpp>
#include <platformer/entities/world.hpp>
#include <platformer/entities/player.hpp>
#include <iostream>
#include "loader.hpp"
#include "level.hpp"
#include "framework.hpp"

// Level

void to_json(json& j, const Level& l){
	j["world"] = *(l.world);
	j["player"] = *(l.player);
	j["entities"] = json::array();
	for(auto& e : l.entities){
		j["entities"].emplace_back(*(e));
	}
}

void from_json(const json& j, Level& l){
	l.world = std::make_shared<World>(j.at("world").get<World>());
	l.player = std::make_shared<Player>(j["player"].get<Player>());
	json entitiesArray = j["entities"];
	for(auto& e : entitiesArray){
		auto pe = std::make_shared<PhysicalEntity>(e.get<PhysicalEntity>());
		pe->build(*l.b2World);
		l.entities.insert(pe); // TODO: Cannot create sth other than PhysicalEntity
	}
	l.world->build(*l.b2World);
	l.player->build(*l.b2World);
}

// Entities

void to_json(json& j, const Entity& e){
	j = dynamic_cast<const sf::Transformable&>(e);
	j["textureCoord"] = e.textureCoord;
    j["visible"] = e.visible;
}

void from_json(const json& j, Entity& e){
    j.get_to(dynamic_cast<sf::Transformable&>(e));
	j["textureCoord"].get_to(e.textureCoord);
	e.sprite.setTexture(Framework::getAssetStorage().getTexture(e.textureInfo.getName()));
	e.sprite.setTextureRect({
		static_cast<int>(e.textureCoord.x * (e.textureInfo.getSize().x + e.textureInfo.getMargin().x)),
		static_cast<int>(e.textureCoord.y * (e.textureInfo.getSize().y + e.textureInfo.getMargin().y)),
		e.textureInfo.getSize().x,
		e.textureInfo.getSize().y});
    j["visible"].get_to(e.visible);
}

void to_json(json& j, const PhysicalEntity& p){
	j = dynamic_cast<const Entity&>(p);
	j["body"] = *(p.body);
	j["properties"] = p.properties;
}

void from_json(const json& j, PhysicalEntity& p){
    j.get_to(dynamic_cast<Entity&>(p));
    j["body"].get_to(p.bodyDef);
	j["properties"].get_to(p.properties);
}

// World

void to_json(json& j, const TileConfig& c){
	j["texture_coord"] = c.texture_coord;
	j["solid"] = c.solid;
}

void from_json(const json& j, TileConfig& c){
	j["texture_coord"].get_to(c.texture_coord);
	j["solid"].get_to(c.solid);
}

void to_json(json& j, const World& w){
	j = dynamic_cast<const PhysicalEntity&>(w);
	j["tiles"] = w.tiles;
}

void from_json(const json& j, World& w){
	j.get_to(dynamic_cast<PhysicalEntity&>(w));
	j["tiles"].get_to(w.tiles);
}

// Player

void to_json(json& j, const Player& p){
	j = dynamic_cast<const PhysicalEntity&>(p);
}

void from_json(const json& j, Player& p){
	j.get_to(dynamic_cast<PhysicalEntity&>(p));
}

// Entity properties

void to_json(json& j, const EntityProperties::JumpProperty& p){
	j = json{ {"height", p.height}, {"midAir", p.midAir} };
}

void from_json(const json& j, EntityProperties::JumpProperty& p){
	j["height"].get_to(p.height);
	j["midAir"].get_to(p.midAir);
}

void to_json(json& j, const EntityProperties::MovementProperty& p){
	j = json{ {"speed", p.speed} };
}

void from_json(const json& j, EntityProperties::MovementProperty& p){
	j["speed"].get_to(p.speed);
}

void to_json(json& j, const EntityProperties& p){
	if(p.jumpFlag)
		j["jump"] = p.jump;
	if(p.doubleJumpFlag)
		j["double_jump"] = p.doubleJump;
	if(p.movementFlag)
		j["movement"] = p.movement;
	j["solid"] = p.solidFlag;
	j["type"] = p.type;
	j["mask"] = p.mask;
}

void from_json(const json& j, EntityProperties& p){
	if(j.contains("jump")){
		p.jumpFlag = true;
		j["jump"].get_to(p.jump);
	}
	if(j.contains("double_jump")){
		p.doubleJumpFlag = true;
		j["double_jump"].get_to(p.doubleJump);
	}
	if(j.contains("movement")){
		p.movementFlag = true;
		j["movement"].get_to(p.movement);
	}
	j["solid"].get_to(p.solidFlag);

	p.type = j["type"].get<EntityTypeBuilder>().build();
	p.mask = j["mask"].get<EntityTypeBuilder>().build();
}

void to_json(json& j, const EntityProperties::EntityType& p){
	int x = p;
	j["ground"] = x % 2 == 1;
	x /= 2;
	j["npc"] = x % 2 == 1;
	x /= 2;
	j["player"] = x % 2 == 1;
	x /= 2;
	j["collectible"] = x % 2 == 1;
}

void from_json(const json& j, EntityTypeBuilder& p){
	p.ground(j["ground"].get<bool>());
	p.npc(j["npc"].get<bool>());
	p.player(j["player"].get<bool>());
	p.collectible(j["collectible"].get<bool>());
}

// SFML
template<typename T>
void sf::to_json(json& j, const sf::Vector2<T>& vec){
	j["x"] = vec.x;
	j["y"] = vec.y;
}

template<typename T>
void sf::from_json(const json& j, sf::Vector2<T>& vec){
	j["x"].template get_to(vec.x);
	j["y"].template get_to(vec.y);
}

void sf::to_json(json& j, const sf::Transformable& t){
	j["origin"] = t.getOrigin();
	j["position"] = t.getPosition();
	j["rotation"] = t.getRotation();
	j["scale"] = t.getScale();
}

void sf::from_json(const json& j, sf::Transformable& t){
	t.setOrigin(j["origin"].get<sf::Vector2f>());
	t.setPosition(j["position"].get<sf::Vector2f>());
	t.setRotation(j["rotation"].get<float>());
	t.setScale(j["scale"].get<sf::Vector2f>());
}
// Box2D

void to_json(json& j, const b2Body& b2){
	j["position"] = b2.GetPosition();
	j["angle"] = b2.GetAngle();
	j["linearVelocity"] = b2.GetLinearVelocity();
	j["angularVelocity"] = b2.GetAngularVelocity();
	j["linearDamping"] = b2.GetLinearDamping();
	j["angularDamping"] = b2.GetAngularDamping();
	j["allowSleep"] = b2.IsSleepingAllowed();
	j["awake"] = b2.IsAwake();
	j["fixedRotation"] = b2.IsFixedRotation();
	j["bullet"] = b2.IsBullet();
	j["type"] = b2.GetType();
	j["enabled"] = b2.IsEnabled();
	j["gravityScale"] = b2.GetGravityScale();
}

void from_json(const json& j, b2BodyDef& b2){
	j["position"].get_to(b2.position);
	j["angle"].get_to(b2.angle);
	j["linearVelocity"].get_to(b2.linearVelocity);
	j["angularVelocity"].get_to(b2.angularVelocity);
	j["linearDamping"].get_to(b2.linearDamping);
	j["angularDamping"].get_to(b2.angularDamping);
	j["allowSleep"].get_to(b2.allowSleep);
	j["awake"].get_to(b2.awake);
	j["fixedRotation"].get_to(b2.fixedRotation);
	j["bullet"].get_to(b2.bullet);
	j["type"].get_to(b2.type);
	j["enabled"].get_to(b2.enabled);
	j["gravityScale"].get_to(b2.gravityScale);
}

void to_json(json& j, const b2Vec2& b2){
	j["x"] = b2.x;
	j["y"] = b2.y;
}

void from_json(const json& j, b2Vec2& b2){
	j["x"].get_to(b2.x);
	j["y"].get_to(b2.y);
}

