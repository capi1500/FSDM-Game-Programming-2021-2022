#include "levelSaver.hpp"
#include <SFML/Window/Event.hpp>
#include <platformer/framework.hpp>
#include <platformer/gui/inputButton.hpp>
#include <iostream>
#include "../utils/stateMachine.hpp"

LevelSaver::LevelSaver(StateMachine& stateMachine, const Level& level)
		: Scene(stateMachine){
	centerX = Framework::getRenderer().getSize().x / 2;
	centerY = Framework::getRenderer().getSize().y / 2;
	

	auto* in = new InputButton({centerX, centerY - 92}, "path to save");
	entities.push_back(in);
	entities.push_back(new LongButton(
			{centerX, centerY + 92},
			"Save",
			[this, &level, in]{
				getStateMachine().pop();
				std::string name;
				if(in->getText().isEmpty())
					name = in->getDefaultText();
				else
					name = in->getText().toAnsiString();
				std::cout << "Saving to: '..\\saves\\" + name + ".json'\n";
				level.save("..\\saves\\" + name + ".json");
			}));
}

LevelSaver::LevelSaver(StateMachine& stateMachine, const std::shared_ptr<Level>& level)
		: Scene(stateMachine){
	centerX = Framework::getRenderer().getSize().x / 2;
	centerY = Framework::getRenderer().getSize().y / 2;
	
	
	auto* in = new InputButton({centerX, centerY - 92}, "path to save");
	entities.push_back(in);
	entities.push_back(new LongButton(
			{centerX, centerY + 92},
			"Save",
			[this, level, in]{
				getStateMachine().pop();
				std::string name;
				if(in->getText().isEmpty())
					name = in->getDefaultText();
				else
					name = in->getText().toAnsiString();
				std::cout << "Saving to: '..\\saves\\" + name + ".json'\n";
				level->save("..\\saves\\" + name + ".json");
			}));
}

void LevelSaver::onNotify(const sf::Event& event){
	if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		getStateMachine().pop();
}
