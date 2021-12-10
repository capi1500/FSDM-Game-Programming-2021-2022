#pragma once

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include <platformer/systems/assetStorage.hpp>
#include <platformer/systems/inputHandler.hpp>
#include <platformer/systems/soundboard.hpp>
#include <platformer/systems/renderer.hpp>

class Framework{
	private:
		static AssetStorage assetStorage;
		static InputHandler inputHandler;
		static Soundboard soundboard;
		static std::shared_ptr<Renderer> renderer;
	public:
		Framework() = delete;
		static AssetStorage& getAssetStorage();
		static InputHandler& getInputHandler();
		static Soundboard& getSoundboard();
		static Renderer& getRenderer();
};


