#pragma once

#include <vector>
#include "box2d/box2d.h"
#include "entity.hpp"

class PhysicalEntity : public Entity{
    private:
        b2World& world;
        std::vector<sf::Drawable*> drawables;
    protected:
        b2Body* body;

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    public:
        void update(const sf::Time &time) override;

        void create(const b2BodyDef& bodyDef);
        b2Fixture* addFixture(const b2FixtureDef& fixtureDef, sf::Drawable* drawable);

        PhysicalEntity(b2World &world);

    virtual ~PhysicalEntity();
};
