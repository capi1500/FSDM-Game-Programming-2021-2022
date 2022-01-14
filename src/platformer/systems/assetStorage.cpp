#include "assetStorage.hpp"

void AssetStorage::loadTexture(const std::string& path){
	loadTexture(path, path);
}

void AssetStorage::loadTexture(const std::string& name, const std::string& path){
	textures[name].loadFromFile(path);
}

const sf::Texture& AssetStorage::getTexture(const std::string& name) const{
	return textures.at(name);
}

sf::Texture& AssetStorage::getTexture(const std::string& name){
	return textures[name];
}

void AssetStorage::loadSound(const std::string& path){
	loadSound(path, path);
}

void AssetStorage::loadSound(const std::string& name, const std::string& path){
	sounds[name].loadFromFile(path);
}

const sf::SoundBuffer& AssetStorage::getSound(const std::string& name) const{
	return sounds.at(name);
}

void AssetStorage::loadFont(const std::string& path){
	loadFont(path, path);
}

void AssetStorage::loadFont(const std::string& name, const std::string& path){
	fonts[name].loadFromFile(path);
}

const sf::Font& AssetStorage::getFont(const std::string& name) const{
	return fonts.at(name);
}
