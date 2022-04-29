#include "entityProperties.hpp"

EntityTypeBuilder& EntityTypeBuilder::ground(bool isGround){
	mask[0] = isGround;
	return *this;
}

EntityTypeBuilder& EntityTypeBuilder::npc(bool isNPC){
	mask[1] = isNPC;
	return *this;
}

EntityTypeBuilder& EntityTypeBuilder::player(bool isPlayer){
	mask[2] = isPlayer;
	return *this;
}

EntityTypeBuilder& EntityTypeBuilder::collectible(bool isCollectible){
	mask[3] = isCollectible;
	return *this;
}

EntityProperties::EntityType EntityTypeBuilder::build(){
	return static_cast<EntityProperties::EntityType>(mask.to_ulong());
}

EntityPropertiesBuilder& EntityPropertiesBuilder::setJump(const EntityProperties::JumpProperty& jumpProperty){
	properties.jumpFlag = true;
	properties.jump = jumpProperty;
	return *this;
}

EntityPropertiesBuilder& EntityPropertiesBuilder::setDoubleJump(const EntityProperties::JumpProperty& jumpProperty){
	properties.doubleJumpFlag = true;
	properties.doubleJump = jumpProperty;
	return *this;
}

EntityPropertiesBuilder& EntityPropertiesBuilder::setMovement(const EntityProperties::MovementProperty& movementProperty){
	properties.movementFlag = true;
	properties.movement = movementProperty;
	return *this;
}

EntityPropertiesBuilder& EntityPropertiesBuilder::setSolid(){
	properties.solidFlag = true;
	return *this;
}

EntityPropertiesBuilder& EntityPropertiesBuilder::setEntityType(const EntityProperties::EntityType& entityType){
	properties.type = entityType;
	return *this;
}

EntityPropertiesBuilder& EntityPropertiesBuilder::setMask(const EntityProperties::EntityType& entityType){
	properties.mask = entityType;
	return *this;
}

EntityProperties EntityPropertiesBuilder::build(){
	return properties;
}

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
