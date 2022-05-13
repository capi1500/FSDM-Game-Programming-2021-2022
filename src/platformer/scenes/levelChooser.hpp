#pragma once

#include <platformer/scene.hpp>
#include <platformer/gui/longButton.hpp>

class LevelChooser : public Scene{
	private:
		float centerX;
		float centerY;
		std::function<void(const std::string&)> onChosen;
		
		void createButton(const std::string& name, int id);
	public:
		LevelChooser(StateMachine& stateMachine, const std::function<void(const std::string&)>& onChosen);
		void onNotify(const sf::Event& event) override;
};


