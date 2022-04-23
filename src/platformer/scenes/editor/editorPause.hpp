#pragma once

#include <platformer/scene.hpp>
#include <platformer/utils/stateMachine.hpp>

class EditorPause : public Scene{
	public:
		EditorPause(StateMachine& stateMachine, Editor& editor);
		
		void onNotify(const sf::Event& event) override;
		void update(const sf::Time& time) override;
};
