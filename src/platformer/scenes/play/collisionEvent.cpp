#include <platformer/scenes/play.hpp>
#include "collisionEvent.hpp"

PhysicalEntity* CollisionEvent::getEntity1() const{
	return entity1;
}

PhysicalEntity* CollisionEvent::getEntity2() const{
	return entity2;
}

b2Contact* CollisionEvent::getContact() const{
	return contact;
}

bool CollisionEvent::isCollisionBegin() const{
	return collisionBegin;
}

CollisionEvent::CollisionEvent(PhysicalEntity* entity1, PhysicalEntity* entity2, b2Contact* contact, bool collisionBegin) : SceneEvent(Play::CollisionEvent),
	                                                                                                                         entity1(entity1),
	                                                                                                                         entity2(entity2),
	                                                                                                                         contact(contact),
	                                                                                                                         collisionBegin(collisionBegin){}
