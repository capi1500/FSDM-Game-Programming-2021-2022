#pragma once

#include <platformer/scenes/events/sceneEvent.hpp>
#include <SFML/System/Vector2.hpp>

class TilePlacedEvent : public SceneEvent{
	private:
		sf::Vector2i coord;
		sf::Vector2u texturePosition;
	public:
		const sf::Vector2i& getCoord() const;
		const sf::Vector2u& getTexturePosition() const;
		TilePlacedEvent(const sf::Vector2i& coord, const sf::Vector2u& texturePosition);
};


