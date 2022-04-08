#include <platformer/framework.hpp>
#include "tileChooser.hpp"

void TileChooser::update(const sf::Time& time){}

TileChooser::TileChooser(){
	TextureInfo textureInfo = Framework::getAssetStorage().getTextureInfo("tiles");
	
	sprite.setTexture(Framework::getAssetStorage().getTexture("tiles"));
	
	setOrigin(sprite.getTexture()->getSize().x / 2, sprite.getTexture()->getSize().y / 2);
	scale(2, 2);
	setScaleFactor(2);
	
	setRect(sf::FloatRect(0, 0, sprite.getTexture()->getSize().x, sprite.getTexture()->getSize().y));
	setTileSize(sf::Vector2f(textureInfo.getSize().x + textureInfo.getMargin().x, textureInfo.getSize().y + textureInfo.getMargin().y));
}
