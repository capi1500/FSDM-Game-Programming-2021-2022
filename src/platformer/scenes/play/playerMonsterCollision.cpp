#include <platformer/scenes/play.hpp>
#include "playerMonsterCollision.hpp"

const CollisionEvent& PlayerMonsterCollision::castEvent(const std::shared_ptr<SceneEvent>& event){
	return dynamic_cast<const CollisionEvent&>(*event);
}

bool PlayerMonsterCollision::isApplicable(const std::shared_ptr<SceneEvent>& e){
	if(e->getEventId() != Play::CollisionEvent)
		return false;
	const auto& event = castEvent(e);
	
	return true;
}

void PlayerMonsterCollision::onNotifyImpl(const std::shared_ptr<SceneEvent>& e){
	const auto& event = castEvent(e);
	
}
