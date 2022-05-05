#pragma once

#include <string>
#include <SFML/System/Vector2.hpp>
#include <json.hpp>

using json = nlohmann::json;

class TextureInfo{
	private:
		std::string name;
		sf::Vector2i size;
		sf::Vector2i margin;
	public:
		const std::string& getName() const;
		const sf::Vector2i& getSize() const;
		const sf::Vector2i& getMargin() const;
		
		friend void to_json(json& j, const TextureInfo& textureInfo);
		friend void from_json(const json& j, TextureInfo& textureInfo);
};


