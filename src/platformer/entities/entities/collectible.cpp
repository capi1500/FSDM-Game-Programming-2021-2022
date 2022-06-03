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
