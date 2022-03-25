#include <platformer/scenes/play.hpp>
#include <platformer/entities/entities/collectible.hpp>
#include "collectibleCollision.hpp"

void CollectibleCollision::onNotifyImpl(const std::shared_ptr<SceneEvent>& e){
	const auto& event = castEvent(e);
	
	PhysicalEntity* body;
	Collectible* collectible;
	
	if(event.getEntity1()->getProperties().type & EntityProperties::Player && event.getEntity2()->getProperties().type & EntityProperties::Collectible){
		body = event.getEntity1();
		collectible = dynamic_cast<Collectible*>(event.getEntity2());
	}
	else if(event.getEntity2()->getProperties().type & EntityProperties::Player && event.getEntity1()->getProperties().type & EntityProperties::Collectible){
		body = event.getEntity2();
		collectible = dynamic_cast<Collectible*>(event.getEntity1());
	}
	else{
		return;
	}
	
	if(event.isCollisionBegin()){
		collectible->collect(*body);
	}
}

bool CollectibleCollision::isApplicable(const std::shared_ptr<SceneEvent>& event){
	return event->getEventId() == Play::CollisionEvent;
}

const CollisionEvent& CollectibleCollision::castEvent(const std::shared_ptr<SceneEvent>& event){
	return dynamic_cast<const CollisionEvent&>(*event);
}
