#include <platformer/framework.hpp>
#include "tileChooser.hpp"

void TileChooser::update(const sf::Time& time){}

TileChooser::TileChooser(){
	TextureInfo textureInfo = Framework::getAssetStorage().getTextureInfo("tiles");
	
	sprite.setTexture(Framework::getAssetStorage().getTexture("tiles"));
	
	setPosition(0, 400);
	
	setRect(sf::FloatRect(getPosition().x, getPosition().y, sprite.getTexture()->getSize().x, sprite.getTexture()->getSize().y));
	setTileSize(sf::Vector2f(textureInfo.getSize().x + textureInfo.getMargin().x, textureInfo.getSize().y + textureInfo.getMargin().y));
}
