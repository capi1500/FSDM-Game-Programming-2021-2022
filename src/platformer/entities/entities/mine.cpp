#include <platformer/entities/world/characters.h>
#include <platformer/framework.hpp>
#include "mine.hpp"

Mine::Mine(b2World& world,
		const sf::Vector2i& position) :
		PhysicalEntity(
				world,
				position,
				Framework::getAssetStorage().getTextureInfo("characters"),
				Characters::mine,
				{0.5, 0.5},
				{1, 1},
				EntityPropertiesBuilder()
						.setEntityType(EntityTypeBuilder().npc(true).build())
						.setMovement({3})
						.setMask(EntityTypeBuilder().player(true).ground(true).build())
						.build()
		){}

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