#pragma once

#include <platformer/scene.hpp>
#include <platformer/scenes/editor/tileChooser.hpp>
#include <platformer/gui/radioButtonGroup.hpp>
#include "editor/worldEditor.hpp"

class Editor : public Scene{
	private:
		WorldEditor* editor;
		TileChooser* tileChooser;
		
		RadioButtonGroup brushSizeRadioButtonGroup;
		int brushSize;
	public:
		Editor(StateMachine& stateMachine);
		void onNotify(const sf::Event& event) override;
		void onNotify(const std::shared_ptr<SceneEvent>& event) override;
		void activate() override;
		void deactivate() override;
};


