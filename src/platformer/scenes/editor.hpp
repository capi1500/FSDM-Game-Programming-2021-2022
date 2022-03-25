#pragma once

#include <platformer/scene.hpp>

class Editor : public Scene{
	public:
		Editor(StateMachine& stateMachine);
		void onNotify(const sf::Event& event) override;
		void onNotify(const std::shared_ptr<SceneEvent>& event) override;
		enum SceneEventID{
			TilePlaced
		};
};


