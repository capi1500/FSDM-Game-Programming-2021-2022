#pragma once

#include <bitset>
#include <json.hpp>

using json = nlohmann::json;

struct EntityProperties{
	struct JumpProperty{
		float height = 1;
		bool midAir = false;
	};
	
	bool jumpFlag = false;
	JumpProperty jump;
	bool doubleJumpFlag = false;
	JumpProperty doubleJump;
	
	struct MovementProperty{
		float speed = 1;
	};
	
	bool movementFlag = false;
	MovementProperty movement;
	
	bool solidFlag = false;
	
	enum EntityType{
		Ground = 1,
		NPC = 2,
		Player = 4,
		Collectible = 8
	};
	EntityType type;
	EntityType mask;
};

class EntityTypeBuilder{
	private:
		std::bitset<32> mask;
	public:
		EntityTypeBuilder& ground(bool isGround);
		EntityTypeBuilder& npc(bool isNPC);
		EntityTypeBuilder& player(bool isPlayer);
		EntityTypeBuilder& collectible(bool isCollectible);
		EntityProperties::EntityType build();
};

class EntityPropertiesBuilder{
	private:
		EntityProperties properties;
	public:
		EntityPropertiesBuilder& setJump(const EntityProperties::JumpProperty& jumpProperty);
		EntityPropertiesBuilder& setDoubleJump(const EntityProperties::JumpProperty& jumpProperty);
		EntityPropertiesBuilder& setMovement(const EntityProperties::MovementProperty& movementProperty);
		EntityPropertiesBuilder& setSolid();
		EntityPropertiesBuilder& setEntityType(const EntityProperties::EntityType& entityType);
		EntityPropertiesBuilder& setMask(const EntityProperties::EntityType& entityType);
		EntityProperties build();
};
