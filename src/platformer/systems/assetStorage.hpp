#pragma once

#include <unordered_map>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Font.hpp>
#include <platformer/entities/world/textureInfo.hpp>

class AssetStorage{
	private:
		std::unordered_map<std::string, sf::Texture> textures;
		std::unordered_map<std::string, sf::SoundBuffer> sounds;
		std::unordered_map<std::string, sf::Font> fonts;
		std::unordered_map<std::string, TextureInfo> textureInfo;
	public:
		void loadTexture(const std::string& path);
		void loadTexture(const std::string& name, const std::string& path);
		const sf::Texture& getTexture(const std::string& name) const;
		sf::Texture& getTexture(const std::string& name);
		
		void loadSound(const std::string& path);
		void loadSound(const std::string& name, const std::string& path);
		const sf::SoundBuffer& getSound(const std::string& name) const;
		
		void loadFont(const std::string& path);
		void loadFont(const std::string& name, const std::string& path);
		const sf::Font& getFont(const std::string& name) const;
		
		void addTextureInfo(const TextureInfo& textureInfo);
		const TextureInfo& getTextureInfo(const std::string& name) const;
};


