#include "levelChooser.hpp"
#include <SFML/Window/Event.hpp>
#include <platformer/framework.hpp>
#include <platformer/utils/filepath.hpp>
#include "../utils/stateMachine.hpp"

LevelChooser::LevelChooser(StateMachine& stateMachine, const std::function<void(const std::string&)>& onChosen)
		: Scene(stateMachine), onChosen(onChosen){
	centerX = Framework::getRenderer().getSize().x / 2;
	centerY = Framework::getRenderer().getSize().y / 2;
	
	int x = 0;
	Filepath("..\\saves\\").execute([this, &x](const fs::path& path){
		std::string tmp = path.filename().string();
		createButton(tmp.substr(0, tmp.size() - path.extension().string().size()), x++);
	});
}

void LevelChooser::createButton(const std::string& name, int id){
	entities.push_back(new LongButton(
			{centerX, centerY + 92 * (id - 3)},
			name,
			[this, name]{
				getStateMachine().pop();
				onChosen(name);
			}));
}

void LevelChooser::onNotify(const sf::Event& event){
	if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		getStateMachine().pop();
}
