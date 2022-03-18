#pragma once

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
};
