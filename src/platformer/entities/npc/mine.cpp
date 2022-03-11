#include <platformer/entities/world/characters.h>
#include "mine.hpp"

Mine::Mine(b2World& world,
		const sf::Vector2i& position) :
		PhysicalEntity(
				world,
				position,
				Characters::mine,
				{0.5, 0.5},
				{1, 1},
				{},
				1) {}

void Mine::update(const sf::Time& time){
	PhysicalEntity::update(time);
	body->SetLinearVelocity({0, body->GetLinearVelocity().y});
}