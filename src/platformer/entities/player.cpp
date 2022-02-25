#include <SFML/Graphics/RenderTarget.hpp>
#include <platformer/framework.hpp>
#include <platformer/entities/world/tiles.hpp>
#include "player.hpp"

void Player::update(const sf::Time& time){
	PhysicalEntity::update(time);
	
	stop();
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		moveLeft();
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		moveRight();
}

Player::Player(b2World& world, const sf::Vector2i& position) : PhysicalEntity(world,
																			  position,
																			  {0, 0},
																			  {0.5, 0.5},
																			  {1, 1},
																			  {
																					true,
																					{5},
																			        true,
																					{5},
																			        true,
																					{5},
																					true
																			   },
																			  5){
	
	properties.jumpFlag = true;
	properties.jump.height = 5;
	properties.doubleJumpFlag = true;
	properties.doubleJump.height = 5;
	properties.movementFlag = true;
	properties.movement.speed = 5;
	
	collisionPrecedence = 5;
	properties.solidFlag = true;
}

void Player::onNotify(const sf::Event& event){
	if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W){
		jump();
	}
}