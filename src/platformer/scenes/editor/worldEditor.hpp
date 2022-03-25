#pragma once

#include <platformer/entities/entity.hpp>
#include <vector>
#include <platformer/scenes/events/sceneEvent.hpp>
#include <memory>
#include <platformer/utils/listener.hpp>

class WorldEditor : public Entity, public Listener<std::shared_ptr<SceneEvent>>{
	private:
		sf::RenderTexture texture;
		
		sf::Vector2u size;
		std::vector<std::vector<sf::Vector2u>> type; // references struct Tiles
		TextureInfo textureInfo;
		
		void redraw();
	public:
		sf::Vector2i getCoord(const sf::Vector2i& pixel);
		
		WorldEditor(const sf::Vector2u& size);
		void update(const sf::Time& time) override;
		void onNotify(const std::shared_ptr<SceneEvent>& event) override;
};


