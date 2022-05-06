#include <platformer/entities/world/tiles.hpp>
#include <platformer/framework.hpp>
#include <iostream>
#include "diamond.hpp"

void Diamond::collect(PhysicalEntity& physicalEntity){
	std::cout << "Diamond collected\n";
	sprite.setColor(sf::Color::Transparent);
	body->SetEnabled(false);
}

Diamond::Diamond(){
	setTextureInfo(Framework::getAssetStorage().getTextureInfo("tiles"));
}
