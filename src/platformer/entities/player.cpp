#include <platformer/framework.hpp>
#include <platformer/entities/world/characters.h>
#include "player.hpp"

void Player::update(const sf::Time& time){
	PhysicalEntity::update(time);
	
	stop();
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		moveLeft();
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		moveRight();
}

Player::Player(){
	setTextureInfo(Framework::getAssetStorage().getTextureInfo("characters"));
	updateTexture(Characters::ghost_green_down);
}

void Player::buildDefault(b2World& world, const sf::Vector2f& position){
	properties = EntityPropertiesBuilder()
			.setJump({5})
			.setDoubleJump({5})
			.setMovement({5})
			.setEntityType(EntityTypeBuilder().player(true).build())
			.setMask(EntityTypeBuilder()
					         .npc(true)
					         .collectible(true)
					         .ground(true)
					         .build())
			.build();
	
	getBodyDef().position = Framework::getPhysicConfig().pixelToMeters(position);
	getBodyDef().type = b2_dynamicBody;
	getBodyDef().fixedRotation = true;
	
	build(world);
}

void Player::build(b2World& world){
	PhysicalEntity::build(world);
	
	b2Vec2 hitboxCenter = {0.5, 0.5};
	b2Vec2 hitboxSize = {1, 1};
	
	b2PolygonShape shape;
	shape.SetAsBox(hitboxSize.x / 2, hitboxSize.y / 2, hitboxCenter,0);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 1.0;
	fixtureDef.friction = 0;
	fixtureDef.filter.categoryBits = properties.type;
	fixtureDef.filter.maskBits = properties.mask;
	addFixture(fixtureDef);
}

void Player::onNotify(const sf::Event& event){
	if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W){
		jump();
	}
}
