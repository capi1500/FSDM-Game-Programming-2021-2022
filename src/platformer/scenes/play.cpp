#include <platformer/framework.hpp>
#include "play.hpp"

Play::Play(StateMachine& stateMachine) : Scene(stateMachine){
	tiles.setTexture(Framework::getAssetStorage().getTexture("tiles"));
	tiles.setTextureSize({18, 18});
	tiles.setOffset({2, 2});
	
	background.setTexture(Framework::getAssetStorage().getTexture("background"));
	background.setTextureSize({24, 24});
	background.setOffset({2, 2});
	
	characters.setTexture(Framework::getAssetStorage().getTexture("characters"));
	characters.setTextureSize({24, 24});
	characters.setOffset({2, 2});
	
	ui.setTexture(Framework::getAssetStorage().getTexture("rpg ui"));
	ui.setTextureSize({18, 18});
	ui.setOffset({2, 2});
}
