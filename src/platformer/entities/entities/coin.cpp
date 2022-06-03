#include <platformer/entities/world/tiles.hpp>
#include <platformer/framework.hpp>
#include <platformer/scenes/play.hpp>
#include "coin.hpp"

void Coin::collect(PhysicalEntity& physicalEntity){
	sprite.setColor(sf::Color::Transparent);
	body->SetEnabled(false);
	Framework::getEventHandler().send(std::make_shared<SceneEvent>(Play::CoinCollected));
}

Coin::Coin(){
	setTextureInfo(Framework::getAssetStorage().getTextureInfo("tiles"));
	updateTexture(sf::Vector2u(Tiles::coin1.texture_coord.x, Tiles::coin1.texture_coord.y));
	type = PhysicalEntity::Coin;
}
