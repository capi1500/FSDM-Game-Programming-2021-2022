#include <platformer/scenes/mainMenu.hpp>
#include "game.hpp"
#include "framework.hpp"

void Game::run(){
	active = true;
	Framework::getRenderer().create(sf::VideoMode(900, 600), "Platformer");
	Framework::getRenderer().setFramerateLimit(60);
	
	Framework::getInputHandler().subscribe(this);
	
	Framework::getAssetStorage().loadTexture("tiles", "../assets/textures/pixelplatformer/Tilemap/tiles.png");
	Framework::getAssetStorage().loadTexture("characters", "../assets/textures/pixelplatformer/Tilemap/characters.png");
	Framework::getAssetStorage().loadTexture("background", "../assets/textures/pixelplatformer/Background/tilemap.png");
	Framework::getAssetStorage().loadTexture("blue ui", "../assets/textures/ui/Spritesheet/blueSheet.png");
	Framework::getAssetStorage().loadTexture("green ui", "../assets/textures/ui/Spritesheet/greenSheet.png");
	Framework::getAssetStorage().loadTexture("grey ui", "../assets/textures/ui/Spritesheet/greySheet.png");
	Framework::getAssetStorage().loadTexture("red ui", "../assets/textures/ui/Spritesheet/redSheet.png");
	Framework::getAssetStorage().loadTexture("yellow ui", "../assets/textures/ui/Spritesheet/yellowSheet.png");
	Framework::getAssetStorage().loadTexture("rpg ui", "../assets/textures/ui/Spritesheet/uipack_rpg_sheet.png");
	
	Framework::getAssetStorage().loadFont("pixeled", "../assets/fonts/Pixeled.ttf");
	Framework::getAssetStorage().loadFont("kenvector", "../assets/fonts/kenvector_future.ttf");
	Framework::getAssetStorage().loadFont("kenvector thin", "../assets/fonts/kenvector_future_thin.ttf");
	
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
