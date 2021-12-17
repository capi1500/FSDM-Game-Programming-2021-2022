#pragma once

#include <unordered_map>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Text.hpp>

class Tileset{
	private:
		sf::Vector2i textureSize;
		sf::Vector2i offset;
		sf::Texture* texture;
		std::unordered_map<std::string, sf::IntRect> mapped;
	public:
		const sf::Vector2i& getTextureSize() const;
		void setTextureSize(const sf::Vector2i& textureSize);
		const sf::Vector2i& getOffset() const;
		void setOffset(const sf::Vector2i& offset);
		const sf::Texture& getTexture() const;
		sf::Texture& getTexture();
		void setTexture(sf::Texture& texture);
		
		void addMappedTextureRect(const std::string& name, unsigned x, unsigned y);
		void addMappedTextureRect(const std::string& name, const sf::Vector2u& pos);
		void removeMappedTextureRect(const std::string& name);
		
		sf::IntRect getTextureRect(unsigned x, unsigned y);
		sf::IntRect getTextureRect(const sf::Vector2u& pos);
		sf::IntRect getTextureRect(const std::string& name);
};


