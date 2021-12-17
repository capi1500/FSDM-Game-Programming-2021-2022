#pragma once

#include <unordered_map>
#include <vector>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>

class Soundboard{
	private:
		unsigned id = 0;
		std::vector<sf::Sound> sounds;
		std::unordered_map<std::string, sf::Music> music;
	public:
		void setSize(unsigned size);
		unsigned getSize() const;
		
		sf::Sound& getNext();
		sf::Sound& get();
		const sf::Sound& get() const;
		
		sf::Music& operator [](const std::string& name);
		const sf::Music& operator [](const std::string& name) const;
};


