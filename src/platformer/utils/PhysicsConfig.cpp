#include "PhysicsConfig.h"

PhysicsConfig::PhysicsConfig(const b2Vec2 &gravity, const float scale, const int velocityIterations,
                             const int positionIterations) : gravity(gravity), scale(scale),
                                                             velocityIterations(velocityIterations),
                                                             positionIterations(positionIterations) {}

sf::Vector2f PhysicsConfig::metersToPixel(const b2Vec2 vec) {
    return {vec.x * scale, vec.y * scale};
}

b2Vec2 PhysicsConfig::pixelToMeters(const sf::Vector2f &vec) {
    return {vec.x / scale, vec.y / scale};
}
