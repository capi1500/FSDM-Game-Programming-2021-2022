#include <platformer/scenes/mainMenu.hpp>
#include "game.hpp"
#include "framework.hpp"

void Game::run(){
	active = true;
	Framework::getRenderer().create(sf::VideoMode(900, 600), "Platformer");
	Framework::getRenderer().setFramerateLimit(60);
	
	Framework::getInputHandler().subscribe(this);
	
	scenes.add(new MainMenu(scenes));
	
	sf::Time time;
	while(active){
		time = clock.restart();
		
		auto& scene = dynamic_cast<Scene&>(scenes.getState());
		Framework::getInputHandler().handleEvents();
		scene.update(time);
		
		rendering[Framework::getRenderer().isOpen()](scene); // Może true != 1, ale powinno być ok
	}
	
	Framework::getInputHandler().unsubscribe(this);
	
	Framework::getRenderer().close();
}

Game::Game(){
	rendering[1] = [](Scene& scene){
		Framework::getRenderer().clear();
		scene.draw();
		Framework::getRenderer().display();
	};
}

void Game::onNotify(const sf::Event& event){
	if(event.type == sf::Event::Closed)
		active = false;
};
