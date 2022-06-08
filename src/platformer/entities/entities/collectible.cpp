#include <platformer/framework.hpp>
#include "collectible.hpp"

void Collectible::buildDefault(b2World& world, const sf::Vector2f& position){
	properties = EntityPropertiesBuilder()
			.setEntityType(EntityTypeBuilder().collectible(true).build())
			.setMask(EntityTypeBuilder().player(true).build())
			.build();
	
	getBodyDef().position = Framework::getPhysicConfig().pixelToMeters(position);
	getBodyDef().type = b2_dynamicBody;
	getBodyDef().fixedRotation = true;
	getBodyDef().gravityScale = 0;
	
	build(world);
}

void Collectible::build(b2World& world){
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
