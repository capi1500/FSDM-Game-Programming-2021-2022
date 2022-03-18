#pragma once

#include <platformer/scenes/events/sceneEventListener.hpp>
#include "collisionEvent.hpp"

class PlayerMonsterCollision : public SceneEventListener{
	protected:
		bool isApplicable(const std::shared_ptr<SceneEvent>& e) override;
		void onNotifyImpl(const std::shared_ptr<SceneEvent>& e) override;
	private:
		static const CollisionEvent& castEvent(const std::shared_ptr<SceneEvent>& event);
};

