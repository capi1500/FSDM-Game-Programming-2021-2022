#include <platformer/scenes/editor.hpp>
#include "tilePlacedEvent.hpp"

const sf::Vector2i& TilePlacedEvent::getCoord() const{
	return coord;
}

const sf::Vector2u& TilePlacedEvent::getTexturePosition() const{
	return texturePosition;
}

TilePlacedEvent::TilePlacedEvent(const sf::Vector2i& coord, const sf::Vector2u& texturePosition) : SceneEvent(Editor::TilePlaced),
                                                                                                                coord(coord),
                                                                                                                texturePosition(texturePosition){}
