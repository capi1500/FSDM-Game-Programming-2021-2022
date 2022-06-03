#include <platformer/entities/world/tiles.hpp>
#include <platformer/framework.hpp>
#include <iostream>
#include <platformer/scenes/play.hpp>
#include "diamond.hpp"

void Diamond::collect(PhysicalEntity& physicalEntity){
	sprite.setColor(sf::Color::Transparent);
	body->SetEnabled(false);
	Framework::getEventHandler().send(std::make_shared<SceneEvent>(Play::DiamondCollected));
}

Diamond::Diamond(){
	setTextureInfo(Framework::getAssetStorage().getTextureInfo("tiles"));
	updateTexture(sf::Vector2u(Tiles::diamond.texture_coord.x, Tiles::diamond.texture_coord.y));
	type = PhysicalEntity::Diamond;
}
