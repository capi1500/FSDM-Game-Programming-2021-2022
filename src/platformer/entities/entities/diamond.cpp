#include <platformer/entities/world/tiles.hpp>
#include "diamond.hpp"

Diamond::Diamond(b2World& world, const sf::Vector2i& position) :
		PhysicalEntity(
				world,
				position,
				Tiles::diamond,
				{0.5, 0.5},
				{0.5, 0.5},
				{},
				1){
	
}
