#pragma once

#include <platformer/systems/assetStorage.hpp>
#include <platformer/systems/inputHandler.hpp>
#include <platformer/systems/soundboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

class Framework{
	private:
		static AssetStorage assetStorage;
		static InputHandler inputHandler;
		static Soundboard soundboard;
		static std::shared_ptr<sf::RenderWindow> renderer;
	public:
		Framework() = delete;
		static AssetStorage& getAssetStorage();
		static InputHandler& getInputHandler();
		static Soundboard& getSoundboard();
		static sf::RenderWindow& getRenderer();
};


