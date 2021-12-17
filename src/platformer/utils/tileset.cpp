#include "tileset.hpp"

const sf::Vector2i& Tileset::getTextureSize() const{
	return textureSize;
}

void Tileset::setTextureSize(const sf::Vector2i& textureSize){
	Tileset::textureSize = textureSize;
}

const sf::Vector2i& Tileset::getOffset() const{
	return offset;
}

void Tileset::setOffset(const sf::Vector2i& offset){
	Tileset::offset = offset;
}

sf::Texture& Tileset::getTexture(){
	return *texture;
}

const sf::Texture& Tileset::getTexture() const{
	return *texture;
}

void Tileset::setTexture(sf::Texture& texture){
	Tileset::texture = &texture;
}

sf::IntRect Tileset::getTextureRect(unsigned int x, unsigned int y){
	return sf::IntRect(x * (textureSize.x + offset.x),
					   y * (textureSize.y + offset.y),
					   textureSize.x,
					   textureSize.y);
}

sf::IntRect Tileset::getTextureRect(const sf::Vector2u& pos){
	return getTextureRect(pos.x, pos.y);
}

sf::IntRect Tileset::getTextureRect(const std::string& name){
	return mapped[name];
}

void Tileset::addMappedTextureRect(const std::string& name, unsigned int x, unsigned int y){
	mapped[name] = getTextureRect(x, y);
}

void Tileset::addMappedTextureRect(const std::string& name, const sf::Vector2u& pos){
	addMappedTextureRect(name, pos.x, pos.y);
}

void Tileset::removeMappedTextureRect(const std::string& name){
	mapped.erase(name);
}
