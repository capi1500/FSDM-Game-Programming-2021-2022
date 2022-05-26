#pragma once

#include <platformer/scene.hpp>
#include <platformer/gui/longButton.hpp>

class LevelSaver : public Scene{
	private:
		float centerX;
		float centerY;
	public:
		LevelSaver(StateMachine& stateMachine, const Level& level);
		LevelSaver(StateMachine& stateMachine, const std::shared_ptr<Level>& level);
		void onNotify(const sf::Event& event) override;
};


