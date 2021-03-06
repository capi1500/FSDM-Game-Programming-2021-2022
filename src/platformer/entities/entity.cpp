#include <platformer/framework.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "entity.hpp"

void Entity::activate(){

}

void Entity::deactivate(){

}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	if(visible){
		states.transform.combine(getTransform());
		target.draw(sprite, states);
	}
}

void Entity::hide(){
	visible = false;
}

void Entity::show(){
	visible = true;
}

const TextureInfo& Entity::getTextureInfo() const{
	return textureInfo;
}

void Entity::setTextureInfo(const TextureInfo& textureInfo){
	Entity::textureInfo = textureInfo;
}

void Entity::updateTexture(const sf::Vector2u& textureCoord){
	this->textureCoord = textureCoord;
	sprite.setTexture(Framework::getAssetStorage().getTexture(textureInfo.getName()));
	sprite.setTextureRect({
			                      static_cast<int>(textureCoord.x * (textureInfo.getSize().x + textureInfo.getMargin().x)),
			                      static_cast<int>(textureCoord.y * (textureInfo.getSize().y + textureInfo.getMargin().y)),
			                      textureInfo.getSize().x,
			                      textureInfo.getSize().y});
}
