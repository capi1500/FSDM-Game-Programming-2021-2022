#pragma once

#include <SFML/Graphics/RenderTexture.hpp>
#include <platformer/entities/entity.hpp>
#include <vector>
#include <platformer/scenes/events/sceneEvent.hpp>
#include <memory>
#include <platformer/utils/listener.hpp>
#include <platformer/gui/CoordChooser.hpp>
#include <platformer/entities/world/tiles.hpp>

class WorldEditor : public Entity, public CoordChooser{
	private:
		sf::RenderTexture texture;
		
		sf::Vector2u size;
		std::vector<std::vector<TileConfig>> tiles; // references struct Tiles
		TextureInfo textureInfo;
	public:
		void updateTile(const TileConfig& type, const sf::Vector2i& tile);
		void redraw();
		
		void set(const std::vector<std::vector<TileConfig>>& tiles);
		const sf::Vector2u& getSize() const;
		const std::vector<TileConfig>& operator [] (std::size_t i) const;
		std::vector<TileConfig>& operator [] (std::size_t i);
		
		explicit WorldEditor(const sf::Vector2u& size);
		void update(const sf::Time& time) override;
};


