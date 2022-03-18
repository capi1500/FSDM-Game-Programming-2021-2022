#include <platformer/scenes/play.hpp>
#include "groundCollision.hpp"

const CollisionEvent& GroundCollision::castEvent(const std::shared_ptr<SceneEvent>& event){
	return dynamic_cast<const CollisionEvent&>(*event);
}

void GroundCollision::onNotifyImpl(const std::shared_ptr<SceneEvent>& e){
	const auto& event = castEvent(e);
	
	PhysicalEntity* body;
	PhysicalEntity* ground;
	
	if(event.getEntity1()->getProperties().type & (EntityProperties::Player | EntityProperties::NPC) && event.getEntity2()->getProperties().type & EntityProperties::Ground){
		body = event.getEntity1();
		ground = event.getEntity2();
	}
	else if(event.getEntity2()->getProperties().type & (EntityProperties::Player | EntityProperties::NPC) && event.getEntity1()->getProperties().type & EntityProperties::Ground){
		body = event.getEntity2();
		ground = event.getEntity1();
	}
	else{
		return;
	}
	
	if(event.isCollisionBegin()){
		if(ground->getProperties().solidFlag){
			if(body->getProperties().jumpFlag)
				body->getProperties().jump.midAir = false;
		}
	}
	else{
		if(ground->getProperties().solidFlag){
			if(body->getProperties().jumpFlag)
				body->getProperties().jump.midAir = true;
			if(body->getProperties().doubleJumpFlag)
				body->getProperties().doubleJump.midAir = false;
		}
	}
}

bool GroundCollision::isApplicable(const std::shared_ptr<SceneEvent>& e){
	return e->getEventId() == Play::CollisionEvent;
}
