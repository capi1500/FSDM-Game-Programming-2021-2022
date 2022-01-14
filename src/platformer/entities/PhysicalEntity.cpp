#include "PhysicalEntity.hpp"
#include "platformer/framework.hpp"

PhysicalEntity::PhysicalEntity(b2World &world) : world(world) {}

void PhysicalEntity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform.combine(getTransform());
    for(auto* d : drawables)
        target.draw(*d, states);
}

void PhysicalEntity::update(const sf::Time &time) {
    setPosition(Framework::getPhysicConfig().metersToPixel(body->GetPosition()));
    setRotation(180 * body->GetAngle() / b2_pi);
}

void PhysicalEntity::create(const b2BodyDef &bodyDef) {
    body = world.CreateBody(&bodyDef);
}

b2Fixture *PhysicalEntity::addFixture(const b2FixtureDef &fixtureDef, sf::Drawable *drawable) {
    drawables.push_back(drawable);
    b2Fixture* f = body->CreateFixture(&fixtureDef);
    return f;
}

PhysicalEntity::~PhysicalEntity() {
    for(auto* d : drawables)
        delete d;
}
