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

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	states.transform.combine(getTransform());
	target.draw(sprite, states);
}

Player::Player(b2World& world, const sf::Vector2i& position) : PhysicalEntity(world){
	sprite.setTexture(Framework::getAssetStorage().getTexture("tiles"));
	sprite.setTextureRect({static_cast<int>(Tiles::snowman.x * 20), static_cast<int>(Tiles::snowman.y * 20), 18, 18});
	
	b2BodyDef bodyDef;
	bodyDef.position = Framework::getPhysicConfig().pixelToMeters(sf::Vector2f(position.x * 18, position.y * 18));
	bodyDef.type = b2_dynamicBody;
	bodyDef.fixedRotation = true;
	create(bodyDef);
	
	b2PolygonShape shape;
	shape.SetAsBox(0.5,0.5,{0.5, 0.5},0);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 1.0;
	fixtureDef.friction = 0;
	addFixture(fixtureDef);
	
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