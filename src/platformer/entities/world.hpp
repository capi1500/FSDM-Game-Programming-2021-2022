#pragma once

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "physicalEntity.hpp"
#include "platformer/entities/world/tiles.hpp"
#include <json.hpp>

using json = nlohmann::json;

class World : public PhysicalEntity{
	private:
		std::vector<std::vector<TileConfig>> tiles; // references struct Tiles
		
		std::shared_ptr<sf::Sprite> sprite;
		std::shared_ptr<sf::RenderTexture> texture;
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		World();
		void build(b2World &world) override;
		
		std::vector<std::vector<TileConfig>>& getTiles();
		const std::vector<std::vector<TileConfig>>& getTiles() const;
		void setTiles(const std::vector<std::vector<TileConfig>>& tiles);
		
		friend void from_json(const json& j, World& w);
		friend void to_json(json& j, const World& w);
};



