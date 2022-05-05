#pragma once

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "physicalEntity.hpp"
#include "platformer/entities/world/tiles.hpp"
#include <json.hpp>

using json = nlohmann::json;

class World : public PhysicalEntity{
	private:
		sf::Vector2u size;
		std::vector<std::vector<TileConfig>> type; // references struct Tiles
		
		sf::Sprite sprite;
		sf::RenderTexture texture;
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		friend void from_json(const json& j, World& w);
		friend void to_json(json& j, const World& w);

		void build(b2World &world) override;
};



