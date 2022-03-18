#pragma once

#include <platformer/utils/listener.hpp>
#include "sceneEvent.hpp"

class SceneEventListener : public Listener<std::shared_ptr<SceneEvent>>{
	protected:
		virtual void onNotifyImpl(const std::shared_ptr<SceneEvent>& event) = 0;
		virtual bool isApplicable(const std::shared_ptr<SceneEvent>& event) = 0;
	public:
		void onNotify(const std::shared_ptr<SceneEvent>& event) override;
};


