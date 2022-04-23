#pragma once

#include <SFML/Graphics/RenderTexture.hpp>
#include <platformer/entities/entity.hpp>
#include <vector>
#include <platformer/scenes/events/sceneEvent.hpp>
#include <memory>
#include <platformer/utils/listener.hpp>
#include <platformer/gui/CoordChooser.hpp>

class WorldEditor : public Entity, public CoordChooser{
	private:
		sf::RenderTexture texture;
		
		sf::Vector2u size;
		std::vector<std::vector<sf::Vector2u>> tiles; // references struct Tiles
		TextureInfo textureInfo;
	public:
		void updateTile(const sf::Vector2u& type, const sf::Vector2i& tile);
		void redraw();
		
		const sf::Vector2u& getSize() const;
		const std::vector<sf::Vector2u>& operator [] (std::size_t i) const;
		std::vector<sf::Vector2u>& operator [] (std::size_t i);
		
		WorldEditor operator + (WorldEditor& other);
		
		WorldEditor(const sf::Vector2u& size);
		void update(const sf::Time& time) override;
};


