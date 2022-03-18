#pragma once

#include <platformer/scenes/events/sceneEvent.hpp>
#include <platformer/entities/physicalEntity.hpp>

class CollisionEvent : public SceneEvent{
	private:
		PhysicalEntity* entity1;
		PhysicalEntity* entity2;
		b2Contact* contact;
		bool collisionBegin;
	public:
		PhysicalEntity* getEntity1() const;
		PhysicalEntity* getEntity2() const;
		b2Contact* getContact() const;
		bool isCollisionBegin() const;
		CollisionEvent(PhysicalEntity* entity1, PhysicalEntity* entity2, b2Contact* contact, bool collisionBegin);
};


