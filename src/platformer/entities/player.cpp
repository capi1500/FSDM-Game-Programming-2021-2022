#include <SFML/Graphics/RenderTarget.hpp>
#include <platformer/framework.hpp>
#include "player.hpp"

void Player::update(const sf::Time& time){
	PhysicalEntity::update(time);
	
	stop();
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		moveLeft();
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		moveRight();
}
/*
Player::Player() : PhysicalEntity(
		world,
		position,
		Framework::getAssetStorage().getTextureInfo("characters"),
		Characters::ghost_green_down,
		{0.5, 0.5},
		{1, 1},
		EntityPropertiesBuilder()
				.setJump({5})
				.setDoubleJump({5})
				.setMovement({5})
				.setEntityType(EntityTypeBuilder().player(true).build())
				.setMask(EntityTypeBuilder()
						.npc(true)
						.collectible(true)
						.ground(true)
						.build())
				.build()
){
	
	properties.jumpFlag = true;
	properties.jump.height = 5;
	properties.doubleJumpFlag = true;
	properties.doubleJump.height = 5;
	properties.movementFlag = true;
	properties.movement.speed = 5;
	
	properties.solidFlag = true;
	properties.type = EntityProperties::Player;
}*/

void Player::onNotify(const sf::Event& event){
	if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W){
		jump();
	}
}
