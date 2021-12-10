#include "framework.hpp"

AssetStorage Framework::assetStorage;
InputHandler Framework::inputHandler;
Soundboard Framework::soundboard;
std::shared_ptr<Renderer> Framework::renderer = nullptr;

AssetStorage& Framework::getAssetStorage(){
	return assetStorage;
}

InputHandler& Framework::getInputHandler(){
	return inputHandler;
}

Soundboard& Framework::getSoundboard(){
	return soundboard;
}

Renderer& Framework::getRenderer(){
	if(renderer == nullptr)
		renderer = std::make_shared<Renderer>();
	return *renderer;
}
