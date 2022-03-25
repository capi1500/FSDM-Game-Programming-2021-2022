#pragma once

#include <platformer/scenes/events/sceneEventListener.hpp>
#include <memory>
#include "collisionEvent.hpp"

class CollectibleCollision : public SceneEventListener{
	protected:
		void onNotifyImpl(const std::shared_ptr<SceneEvent>& event) override;
		bool isApplicable(const std::shared_ptr<SceneEvent>& event) override;
	private:
		static const CollisionEvent& castEvent(const std::shared_ptr<SceneEvent>& event);
};


