#include "soundboard.hpp"

sf::Sound& Soundboard::getNext(){
	id++;
	if(id == sounds.size())
		id = 0;
	return sounds[id];
}

sf::Sound& Soundboard::get(){
	return sounds[id];
}

const sf::Sound& Soundboard::get() const{
	return sounds.at(id);
}

sf::Music& Soundboard::operator [](const std::string& name){
	return music[name];
}

const sf::Music& Soundboard::operator [](const std::string& name) const{
	return music.at(name);
}

void Soundboard::setSize(unsigned int size){
	sounds.resize(size);
}

unsigned Soundboard::getSize() const{
	return sounds.size();
}
