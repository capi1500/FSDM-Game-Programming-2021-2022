#include <platformer/entities/physicalEntity.hpp>
#include <platformer/framework.hpp>
#include <platformer/scenes/play/collisionEvent.hpp>
#include "contactListener.hpp"

void ContactListener::BeginContact(b2Contact* contact){
	auto* a = reinterpret_cast<PhysicalEntity*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
	auto* b = reinterpret_cast<PhysicalEntity*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);
	Framework::getEventHandler().send(std::make_shared<CollisionEvent>(a, b, contact, true));
}

void ContactListener::EndContact(b2Contact* contact){
	auto* a = reinterpret_cast<PhysicalEntity*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
	auto* b = reinterpret_cast<PhysicalEntity*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);
	Framework::getEventHandler().send(std::make_shared<CollisionEvent>(a, b, contact, false));
}
