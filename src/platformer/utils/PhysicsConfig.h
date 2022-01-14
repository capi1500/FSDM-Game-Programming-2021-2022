#pragma once

#include <box2d/box2d.h>
#include <SFML/System/Vector2.hpp>

struct PhysicsConfig{
    const b2Vec2 gravity;
    const float scale;
    const int velocityIterations;
    const int positionIterations;

    PhysicsConfig(const b2Vec2 &gravity, const float scale, const int velocityIterations, const int positionIterations);

    sf::Vector2f metersToPixel(const b2Vec2 vec);
    b2Vec2 pixelToMeters(const sf::Vector2f& vec);
};
