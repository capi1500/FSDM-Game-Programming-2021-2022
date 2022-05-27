#include <platformer/scenes/editor/worldEditor.hpp>
#include <iostream>
#include <platformer/framework.hpp>
#include <platformer/gui/radioButton.hpp>
#include "editor.hpp"
#include <platformer/utils/stateMachine.hpp>
#include <platformer/scenes/editor/editorPause.hpp>

void Editor::onNotify(const sf::Event& event){
	if(event.type == sf::Event::KeyPressed){
		if(event.key.code == sf::Keyboard::Escape)
			getStateMachine().add(new EditorPause(getStateMachine(), *this));
	}
}

void Editor::onNotify(const std::shared_ptr<SceneEvent>& event){

}

void Editor::update(const sf::Time& time){
	Scene::update(time);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		editor->getView().move(-100 * time.asSeconds(), 0);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		editor->getView().move(0, -100 * time.asSeconds());
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		editor->getView().move(100 * time.asSeconds(), 0);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		editor->getView().move(0, 100 * time.asSeconds());
}

Editor::Editor(StateMachine& stateMachine) : Scene(stateMachine){
	editor = new WorldEditor({50, 20});

	editorChosen = new Frame();
	editorChosen->setBaseSize(editor->getTileSize());
	editorChosen->setSize(editor->getTileSize());
	editorChosen->hide();
	
	editor->setView(sf::View());
	editor->getView().setViewport({0, 0, 1, 0.6});
	editor->getView().setSize(sf::Vector2f(Framework::getRenderer().getSize().x, Framework::getRenderer().getSize().y * 6 / 10.0));
	editor->getView().setCenter(0, 0);
	editor->getView().zoom(0.5);
	
	editor->setOnHoverUpdate([this](const sf::Vector2i& coord){
		if(coord == Tiles::empty.texture_coord)
			editorChosen->hide();
		else{
			editorChosen->show();
			editorChosen->setPosition({coord.x * editor->getTileSize().x, coord.y * editor->getTileSize().y});
		}
	});
	editor->setOnChosenUpdate([this](const sf::Vector2i& coord){
		for(int dx = -brushSize / 2; dx <= brushSize / 2; dx++){
			for(int dy = -brushSize / 2; dy <= brushSize / 2; dy++){
				editor->updateTile(getTileConfig(sf::Vector2u(tileChooser->getChosen().x, tileChooser->getChosen().y)), {coord.x + dx, coord.y + dy});
			}
		}
		editor->redraw();
	});
	
	entities.push_back(editor);
	entities.push_back(editorChosen);
	
	tileChooser = new TileChooser();
	
	tileChooser->setView(sf::View());
	tileChooser->getView().setViewport({0, 0.6, 1, 0.4});
	tileChooser->getView().setSize(sf::Vector2f(Framework::getRenderer().getSize().x, Framework::getRenderer().getSize().y * 4 / 10.0));
	tileChooser->getView().setCenter(0, 0);
	
	tileChosen = new Frame();
	tileChosen->setBaseSize(editor->getTileSize() * tileChooser->getScaleFactor());
	tileChosen->setSize({editor->getTileSize().x * tileChooser->getScaleFactor(), editor->getTileSize().y * tileChooser->getScaleFactor()});
	
	tileChooser->setOnChosenUpdate([this](const sf::Vector2i& coord){
		if(coord == sf::Vector2i(-1, -1))
			tileChosen->hide();
		else{
			tileChosen->show();
			erase->release();
		}
		tileChosen->setPosition({tileChooser->getScaleFactor() * coord.x * tileChooser->getTileSize().x - tileChooser->getScaleFactor() * tileChooser->getOrigin().x,
									 tileChooser->getScaleFactor() * coord.y * tileChooser->getTileSize().y - tileChooser->getScaleFactor() * tileChooser->getOrigin().y});
	});
	
	entities.push_back(tileChooser);
	entities.push_back(tileChosen);
	
	size1 = new RadioButton(sf::Vector2f(Framework::getRenderer().getSize().x / 2 - 52, -36),
	                                     [this]{ brushSize = 1; editorChosen->setSize(editor->getTileSize());},
	                                     []{},
	                                     true,
	                                    brushSizeRadioButtonGroup);
	size1->setView(tileChooser->getView());
	size3 = new RadioButton(sf::Vector2f(Framework::getRenderer().getSize().x / 2 - 52, 0),
	                                     [this]{ brushSize = 3; editorChosen->setSize(editor->getTileSize() * 3.f);},
	                                     []{},
	                                     false,
	                                     brushSizeRadioButtonGroup);
	size3->setView(tileChooser->getView());
	size5 = new RadioButton(sf::Vector2f(Framework::getRenderer().getSize().x / 2 - 52, 36),
	                                     [this]{ brushSize = 5; editorChosen->setSize(editor->getTileSize() * 5.f);},
	                                     []{},
	                                     false,
	                                     brushSizeRadioButtonGroup);
	size5->setView(tileChooser->getView());
	
	entities.push_back(size1);
	entities.push_back(size3);
	entities.push_back(size5);
	
	erase = new CheckboxButton(sf::Vector2f(-static_cast<float>(Framework::getRenderer().getSize().x) / 2 + 52, 36),
	                           [this]{
										tileChooser->setChosen(Tiles::empty.texture_coord);
										tileChosen->hide();
								},
	                           []{},
	                           false);
	erase->setView(tileChooser->getView());
	
	entities.push_back(erase);
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

void Editor::draw(sf::RenderStates renderStates){
	sf::View prev = Framework::getRenderer().getView();
	
	Framework::getRenderer().setView(editor->getView());
	Framework::getRenderer().draw(*editor, renderStates);
	Framework::getRenderer().draw(*editorChosen, renderStates);
	
	Framework::getRenderer().setView(tileChooser->getView());
	Framework::getRenderer().draw(*tileChooser, renderStates);
	Framework::getRenderer().draw(*tileChosen, renderStates);
	Framework::getRenderer().draw(*size1, renderStates);
	Framework::getRenderer().draw(*size3, renderStates);
	Framework::getRenderer().draw(*size5, renderStates);
	Framework::getRenderer().draw(*erase, renderStates);
	
	Framework::getRenderer().setView(prev);
}

std::shared_ptr<Level> Editor::save(){
	const WorldEditor& world = (*editor);
	
	std::shared_ptr<Level> level = std::make_shared<Level>();
	
	level->world = std::make_shared<World>();
	level->world->getTiles().resize(world.getSize().x, std::vector<TileConfig>(world.getSize().y));
	for(unsigned x = 0; x < world.getSize().x; x++){
		for(unsigned y = 0; y < world.getSize().y; y++){
			level->world->getTiles()[x][y] = world[x][y];
		}
	}
	level->world->build(*level->b2World);
	level->player = std::make_shared<Player>();
	level->player->buildDefault(*level->b2World);
	
	return level;
}

TileConfig Editor::getTileConfig(const sf::Vector2u& coord){
	return Tiles::tilemap[coord.y][coord.x];
}

void Editor::load(const Level& level){
	editor->set(level.world->getTiles());
}
