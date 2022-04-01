#include <platformer/scenes/editor/worldEditor.hpp>
#include <platformer/scenes/editor/frame.hpp>
#include <iostream>
#include <platformer/framework.hpp>
#include <platformer/gui/radioButton.hpp>
#include "editor.hpp"

void Editor::onNotify(const sf::Event& event){

}

void Editor::onNotify(const std::shared_ptr<SceneEvent>& event){

}

Editor::Editor(StateMachine& stateMachine) : Scene(stateMachine){
	editor = new WorldEditor({50, 20});

	Frame* editorChosen = new Frame();
	editorChosen->setBaseSize(editor->getTileSize());
	editorChosen->setSize(editor->getTileSize());
	
	editor->setOnHoverUpdate([editorChosen, this](const sf::Vector2i& coord){
		editorChosen->setPosition({coord.x * editor->getTileSize().x, coord.y * editor->getTileSize().y});
	});
	editor->setOnChosenUpdate([this](const sf::Vector2i& coord){
		for(int dx = -brushSize / 2; dx <= brushSize / 2; dx++){
			for(int dy = -brushSize / 2; dy <= brushSize / 2; dy++){
				editor->updateTile(sf::Vector2u(tileChooser->getChosen().x, tileChooser->getChosen().y), {coord.x + dx, coord.y + dy});
			}
		}
		editor->redraw();
	});
	
	entities.push_back(editor);
	entities.push_back(editorChosen);
	
	tileChooser = new TileChooser();
	
	Frame* tileChosen = new Frame();
	tileChosen->setBaseSize(editor->getTileSize());
	tileChosen->setSize(editor->getTileSize());
	
	tileChooser->setOnChosenUpdate([tileChosen, this](const sf::Vector2i& coord){
		if(coord == sf::Vector2i(-1, -1))
			tileChosen->hide();
		else
			tileChosen->show();
		tileChosen->setPosition({coord.x * tileChooser->getTileSize().x + tileChooser->getPosition().x, coord.y * tileChooser->getTileSize().y + tileChooser->getPosition().y});
	});
	
	entities.push_back(tileChooser);
	entities.push_back(tileChosen);
	
	RadioButton* size1 = new RadioButton({400, 450},
	                                     [this, editorChosen]{ brushSize = 1; editorChosen->setSize(editor->getTileSize());},
	                                     []{},
	                                     true,
	                                     brushSizeRadioButtonGroup);
	RadioButton* size3 = new RadioButton({400, 500},
	                                     [this, editorChosen]{ brushSize = 3; editorChosen->setSize(editor->getTileSize() * 3.f);},
	                                     []{},
	                                     false,
	                                     brushSizeRadioButtonGroup);
	RadioButton* size5 = new RadioButton({400, 550},
	                                     [this, editorChosen]{ brushSize = 5; editorChosen->setSize(editor->getTileSize() * 5.f);},
	                                     []{},
	                                     false,
	                                     brushSizeRadioButtonGroup);
	entities.push_back(size1);
	entities.push_back(size3);
	entities.push_back(size5);
}

void Editor::activate(){
	Scene::activate();
	Framework::getInputHandler().subscribe(editor);
	Framework::getInputHandler().subscribe(tileChooser);
}

void Editor::deactivate(){
	Scene::deactivate();
	Framework::getInputHandler().unsubscribe(editor);
	Framework::getInputHandler().unsubscribe(tileChooser);
}
