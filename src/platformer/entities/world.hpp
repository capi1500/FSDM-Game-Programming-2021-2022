#pragma once

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "physicalEntity.hpp"
#include <json.hpp>

using json = nlohmann::json;

class World;

class WorldBuilder{
	private:
		sf::Vector2u size;
		std::vector<std::vector<bool>> solid;
		std::vector<std::vector<sf::Vector2u>> type; // references struct Tiles
	public:
		WorldBuilder();
		explicit WorldBuilder(const sf::Vector2u& size);
		
		World create(b2World& world);
		World* create_ptr(b2World& world);
		void setSize(const sf::Vector2u& size);
		WorldBuilder& setTile(const sf::Vector2u& position, const sf::Vector2u& tile, bool solid);
		
		friend class World;
		
		friend void from_json(const json& j, WorldBuilder& w);
};

class World : public PhysicalEntity{
	private:
		sf::Vector2u size;
		std::vector<std::vector<bool>> solid;
		std::vector<std::vector<sf::Vector2u>> type; // references struct Tiles
		
		sf::Sprite sprite;
		sf::RenderTexture texture;
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		World(b2World& b2World, WorldBuilder& worldBuilder);
		
		friend void to_json(json& j, const World& w);
};



