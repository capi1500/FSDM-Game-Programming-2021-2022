#pragma once

#include <platformer/entities/physicalEntity.hpp>

class Collectible : public PhysicalEntity{
	public:
		Collectible(b2World& world, const sf::Vector2i& position, const TextureInfo& textureInfo, const sf::Vector2u& textureCoord, const b2Vec2& hitboxCenter, const b2Vec2& hitboxSize, const EntityProperties& properties);
		virtual void collect(PhysicalEntity& physicalEntity) = 0;
};


