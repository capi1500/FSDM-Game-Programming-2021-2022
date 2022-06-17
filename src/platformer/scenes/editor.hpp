#pragma once

#include <platformer/scene.hpp>
#include <platformer/scenes/editor/tileChooser.hpp>
#include <platformer/gui/radioButtonGroup.hpp>
#include <platformer/scenes/editor/frame.hpp>
#include <platformer/scenes/editor/characterChooser.hpp>
#include <platformer/entities/background.hpp>
#include "editor/worldEditor.hpp"

class Editor : public Scene{
	private:
		WorldEditor* editor;
		Player* player = nullptr;
		std::vector<PhysicalEntity*> characters;
		TileChooser* tileChooser;
		CharacterChooser* characterChooser;
		Background background;
		bool tileMethodActive = true;
		
		RadioButton* size1;
		RadioButton* size3;
		RadioButton* size5;
		CheckboxButton* erase;
		RadioButton* tileMethod;
		RadioButton* characterMethod;
		
		Frame* tileChosen;
		Frame* characterChosen;
		Frame* editorChosen;
		Frame* editorCharacterChosen;
		
		RadioButtonGroup brushSizeRadioButtonGroup;
		RadioButtonGroup spawnMethodRadioButtonGroup;
		int brushSize;
		
		TileConfig getTileConfig(const sf::Vector2u& coord);
		sf::Vector2i getHighestSolidBelow(const sf::Vector2f& pixel);
	public:
		std::shared_ptr<Level> save();
		void load(const Level& level);
		
		Editor(StateMachine& stateMachine);
		virtual ~Editor();
		void onNotify(const sf::Event& event) override;
		void activate() override;
		void deactivate() override;
		void draw(sf::RenderStates renderStates = sf::RenderStates()) override;
		void update(const sf::Time& time) override;
};


