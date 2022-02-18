#include <platformer/entities/physicalEntity.hpp>
#include "contactListener.hpp"

void ContactListener::BeginContact(b2Contact* contact){
	PhysicalEntity* a = reinterpret_cast<PhysicalEntity*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
	PhysicalEntity* b = reinterpret_cast<PhysicalEntity*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);
	if(a->getCollisionPrecedence() > b->getCollisionPrecedence())
		a->contactBegin(*b, contact);
	else if (a->getCollisionPrecedence() < b->getCollisionPrecedence())
		b->contactBegin(*a, contact);
	else{
		a->contactBegin(*b, contact);
		b->contactBegin(*a, contact);
	}
}

void ContactListener::EndContact(b2Contact* contact){
	PhysicalEntity* a = reinterpret_cast<PhysicalEntity*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
	PhysicalEntity* b = reinterpret_cast<PhysicalEntity*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);
	if(a->getCollisionPrecedence() > b->getCollisionPrecedence())
		a->contactEnd(*b, contact);
	else if (a->getCollisionPrecedence() < b->getCollisionPrecedence())
		b->contactEnd(*a, contact);
	else{
		a->contactEnd(*b, contact);
		b->contactEnd(*a, contact);
	}
}
