#include "collectible.hpp"

Collectible::Collectible(b2World& world, const sf::Vector2i& position, const TextureInfo& textureInfo, const sf::Vector2u& textureCoord, const b2Vec2& hitboxCenter, const b2Vec2& hitboxSize, const EntityProperties& properties) : PhysicalEntity(world, position, textureInfo, textureCoord, hitboxCenter, hitboxSize, properties){}
