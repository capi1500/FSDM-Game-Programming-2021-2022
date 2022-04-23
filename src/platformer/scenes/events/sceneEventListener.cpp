#include <memory>
#include <iostream>
#include "sceneEventListener.hpp"

void SceneEventListener::onNotify(const std::shared_ptr<SceneEvent>& event){
	if(isApplicable(event))
		onNotifyImpl(event);
}