#include <platformer/entities/physicalEntity.hpp>
#include <platformer/entities/world.hpp>
#include <platformer/entities/player.hpp>
#include "loader.hpp"
#include "level.hpp"
#include "framework.hpp"

// Level

void to_json(json& j, const Level& l){

}

void from_json(const json& j, Level& l){
	WorldBuilder wb = j["world"].get<WorldBuilder>();
	l.world = std::make_shared<World>(wb.create(l.b2World));
	
	l.player = std::make_shared<Player>(j["player"].get<Player>());
}

// Entities

void to_json(json& j, const Entity& e){
	j = static_cast<sf::Transformable>(e);
	j["textureInfo"] = e.textureInfo;
	j["textureCoord"] = e.textureCoord;
}

void from_json(const json& j, Entity& e){
	j["textureInfo"].get_to(e.textureInfo);
	j["textureCoord"].get_to(e.textureCoord);
	e.sprite.setTexture(Framework::getAssetStorage().getTexture(e.textureInfo.getName()));
	e.sprite.setTextureRect({
		static_cast<int>(e.textureCoord.x * (e.textureInfo.getSize().x + e.textureInfo.getMargin().x)),
		static_cast<int>(e.textureCoord.y * (e.textureInfo.getSize().y + e.textureInfo.getMargin().y)),
		e.textureInfo.getSize().x,
		e.textureInfo.getSize().y});
}

void to_json(json& j, const PhysicalEntity& p){
	j = dynamic_cast<const Entity&>(p);
	j["box"] = *(p.body);
	j["hitboxCenter"] = p.hitboxCenter;
	j["hitboxSize"] = p.hitboxSize;
	j["position"] = p.position;
	j["properties"] = p.properties;
}

void from_json(const json& j, PhysicalEntity& p){
	j["hitboxCenter"].get_to(p.hitboxCenter);
	j["hitboxSize"].get_to(p.hitboxSize);
	j["position"].get_to<sf::Vector2i>(p.position);
	j["properties"].get_to(p.properties);
}

// World

void to_json(json& j, const World& w){
	
}

void from_json(const json& j, World& w){
	
}

// Player

void to_json(json& j, const Player& p){
	
}

void from_json(const json& j, Player& p){
	
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

void to_json(json& j, const TextureInfo& textureInfo){
	j["name"] = textureInfo.name;
	j["size"] = textureInfo.size;
	j["marigin"] = textureInfo.margin;
}

void from_json(const json& j, TextureInfo& textureInfo){
	j["name"].get_to(textureInfo.name);
	j["size"].get_to(textureInfo.size);
	j["marigin"].get_to(textureInfo.margin);
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
	j["x"].template get_to(vec.y);
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

	const b2Fixture* fixture = b2.GetFixtureList();
	
	std::vector<const b2Fixture*> fixtures;
	fixture = fixture->GetNext();
	do {
		fixtures.push_back(fixture);
		fixture = fixture->GetNext();
	} while(fixture);
	
	j["fixtures"] = fixtures;
	
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

void to_json(json& j, const b2Fixture* b2){
	j["shape"] = *(b2->GetShape());
	j["friction"] = b2->GetFriction();
	j["restitution"] = b2->GetRestitution();
	j["restitutionThreshold"] = b2->GetRestitutionThreshold();
	j["density"] = b2->GetDensity();
	j["isSensor"] = b2->IsSensor();
}

void from_json(const json& j, b2FixtureDef& b2){
	b2.shape = j["shape"].get<b2Shape*>();
	j["friction"].get_to(b2.friction);
	j["restitution"].get_to(b2.restitution);
	j["restitutionThreshold"].get_to(b2.restitutionThreshold);
	j["density"].get_to(b2.density);
	j["isSensor"].get_to(b2.isSensor);
}

void to_json(json& j, const b2Vec2& b2){
	j["x"] = b2.x;
	j["y"] = b2.y;
}

void from_json(const json& j, b2Vec2& b2){
	j["x"].get_to(b2.x);
	j["y"].get_to(b2.y);
}

void to_json(json& j, const b2Shape& b2){
	j["type"] = b2.m_type;
	if(b2.m_type == b2Shape::e_circle)
		j["radius"] = b2.m_radius;
}

void from_json(const json& j, b2Shape*& b2){
	j["type"].get_to(b2->m_type);
	if(j.contains("radius"))
		j["radius"].get_to(b2->m_radius);
}
