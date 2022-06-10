#include <platformer/framework.hpp>
#include "characterChooser.hpp"

CharacterChooser::CharacterChooser(){
	TextureInfo textureInfo = Framework::getAssetStorage().getTextureInfo("characters");
	
	sprite.setTexture(Framework::getAssetStorage().getTexture("characters"));
	
	setOrigin(sprite.getTexture()->getSize().x / 2, sprite.getTexture()->getSize().y / 2);
	scale(2, 2);
	setScaleFactor(2);
	
	setRect(sf::FloatRect(-static_cast<float>(sprite.getTexture()->getSize().x) / 2, -static_cast<float>(sprite.getTexture()->getSize().y) / 2, sprite.getTexture()->getSize().x, sprite.getTexture()->getSize().y));
	setTileSize(sf::Vector2f(textureInfo.getSize().x + textureInfo.getMargin().x, textureInfo.getSize().y + textureInfo.getMargin().y));
}

void CharacterChooser::update(const sf::Time& time){

}
