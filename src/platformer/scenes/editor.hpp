#pragma once

#include <platformer/scene.hpp>
#include <platformer/scenes/editor/tileChooser.hpp>
#include <platformer/gui/radioButtonGroup.hpp>
#include <platformer/scenes/editor/frame.hpp>
#include "editor/worldEditor.hpp"

class Editor : public Scene{
	private:
		WorldEditor* editor;
		TileChooser* tileChooser;
		
		RadioButton* size1;
		RadioButton* size3;
		RadioButton* size5;
		CheckboxButton* erase;
		
		Frame* tileChosen;
		Frame* editorChosen;
		
		RadioButtonGroup brushSizeRadioButtonGroup;
		int brushSize;
		
		TileConfig getTileConfig(const sf::Vector2u& coord);
	public:
		std::shared_ptr<Level> save();
		void load(const Level& level);
		
		Editor(StateMachine& stateMachine);
		void onNotify(const sf::Event& event) override;
		void onNotify(const std::shared_ptr<SceneEvent>& event) override;
		void activate() override;
		void deactivate() override;
		void draw(sf::RenderStates renderStates = sf::RenderStates()) override;
		void update(const sf::Time& time) override;
		
		enum SceneEventID{
			PlaytestEvent
		};
};


