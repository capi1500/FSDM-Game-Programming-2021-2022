#include "textureInfo.hpp"

TextureInfo::TextureInfo(const std::string& name, const sf::Vector2i& size, const sf::Vector2i& margin) : name(name),
                                                                                                          size(size),
                                                                                                          margin(margin){}

const std::string& TextureInfo::getName() const{
	return name;
}

const sf::Vector2i& TextureInfo::getSize() const{
	return size;
}

const sf::Vector2i& TextureInfo::getMargin() const{
	return margin;
}
