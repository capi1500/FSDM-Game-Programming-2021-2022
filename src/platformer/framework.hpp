#pragma once

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include <platformer/systems/assetStorage.hpp>
#include <platformer/systems/inputHandler.hpp>
#include <platformer/systems/soundboard.hpp>
#include <platformer/systems/renderer.hpp>
#include <platformer/scenes/events/sceneEvent.hpp>
#include "platformer/utils/PhysicsConfig.h"

class Framework{
	private:
		static AssetStorage assetStorage;
		static InputHandler inputHandler;
		static Soundboard soundboard;
		static std::shared_ptr<Renderer> renderer;
        static PhysicsConfig physicsConfig;
		static Emitter<std::shared_ptr<SceneEvent>> eventHandler;
	public:
		Framework() = delete;
		static AssetStorage& getAssetStorage();
		static InputHandler& getInputHandler();
		static Soundboard& getSoundboard();
		static Renderer& getRenderer();
        static PhysicsConfig& getPhysicConfig();
		static Emitter<std::shared_ptr<SceneEvent>>& getEventHandler();
};


