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
