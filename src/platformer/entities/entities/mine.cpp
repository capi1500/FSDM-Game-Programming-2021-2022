#include <platformer/entities/world/characters.h>
#include <platformer/framework.hpp>
#include "mine.hpp"

void Mine::update(const sf::Time& time){
	PhysicalEntity::update(time);
	timer += time;
	if(timer >= sf::seconds(1)){
		facingLeft = !facingLeft;
		timer -= sf::seconds(1);
	}
	if(facingLeft)
		setMovingLeft();
	else
		setMovingRight();
}

Mine::Mine(){
	setTextureInfo(Framework::getAssetStorage().getTextureInfo("characters"));
	type = PhysicalEntity::Mine;
	updateTexture(Characters::mine);
}

void Mine::build(b2World& world){
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

void Mine::buildDefault(b2World& world, const sf::Vector2f& position){
	properties = EntityPropertiesBuilder()
			.setMovement({4})
			.setEntityType(EntityTypeBuilder().npc(true).build())
			.setMask(EntityTypeBuilder()
									.player(true)
									.ground(true)
									.npc(true)
									.build())
			.build();
	
	getBodyDef().position = Framework::getPhysicConfig().pixelToMeters(position);
	getBodyDef().type = b2_dynamicBody;
	getBodyDef().fixedRotation = true;
	
	build(world);
}
