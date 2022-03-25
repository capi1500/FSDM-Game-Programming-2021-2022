#include <platformer/entities/world/tiles.hpp>
#include <platformer/framework.hpp>
#include <iostream>
#include "diamond.hpp"

Diamond::Diamond(b2World& world, const sf::Vector2i& position) :
		Collectible(
				world,
				position,
				Framework::getAssetStorage().getTextureInfo("tiles"),
				Tiles::diamond,
				{0.5, 0.5},
				{1, 1},
				EntityPropertiesBuilder()
								.setEntityType(EntityTypeBuilder()
										.collectible(true)
										.build()
								)
								.setMask(EntityTypeBuilder()
										.player(true)
										.ground(true)
										.build()
								)
								.build()
		){}

void Diamond::collect(PhysicalEntity& physicalEntity){
	std::cout << "Diamond collected\n";
	sprite.setColor(sf::Color::Transparent);
	body->SetEnabled(false);
}
