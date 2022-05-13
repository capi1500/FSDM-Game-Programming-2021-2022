#include <platformer/gui/longButton.hpp>
#include <platformer/framework.hpp>
#include <platformer/scenes/editor.hpp>
#include <platformer/scenes/settings.hpp>
#include <platformer/scenes/play.hpp>
#include <fstream>
#include <platformer/scenes/levelChooser.hpp>
#include "editorPause.hpp"

EditorPause::EditorPause(StateMachine& stateMachine, Editor& editor) : Scene(stateMachine){
	float centerX = Framework::getRenderer().getSize().x / 2, centerY = Framework::getRenderer().getSize().y / 2;
	
	LongButton* playButton = new LongButton(
			{centerX, centerY - 184},
			"Resume",
			[this]{
				getStateMachine().pop();
			});
	LongButton* restartButton = new LongButton(
			{centerX, centerY - 92},
			"Restart",
			[this]{
				getStateMachine().pop();
				getStateMachine().replace(new Editor(getStateMachine()));
			});
	LongButton* playtestButton = new LongButton(
			{centerX, centerY},
			"Test",
			[this, &editor]{
				editor.save()->save("../saves/editor.json");
				getStateMachine().replace(new Play(getStateMachine(), "editor"));
			});
	LongButton* loadFileButton = new LongButton(
			{centerX, centerY + 92},
			"Load",
			[this, &editor]{
				getStateMachine().replace(new LevelChooser(getStateMachine(), [&editor](const std::string& path){
					Level l;
					l.load("../saves/" + path + ".json");
					editor.load(l);
				}));
			});
	LongButton* saveFileButton = new LongButton(
			{centerX, centerY + 184},
			"Save",
			[this, &editor]{
				editor.save()->save("../saves/save.json");
			});
	LongButton* settingsButton = new LongButton(
			{centerX, centerY + 276},
			"Settings",
			[this]{
				getStateMachine().add(new Settings(getStateMachine()));
			});
	LongButton* quitButton = new LongButton(
			{centerX, centerY + 368},
			"Quit",
			[this]{
				getStateMachine().pop();
				getStateMachine().pop();
			});
	
	entities.push_back(playButton);
	entities.push_back(restartButton);
	entities.push_back(playtestButton);
	entities.push_back(loadFileButton);
	entities.push_back(saveFileButton);
	entities.push_back(settingsButton);
	entities.push_back(quitButton);
}

void EditorPause::onNotify(const sf::Event& event){
	if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		getStateMachine().pop();
}

void EditorPause::update(const sf::Time& time){
	Scene::update(time);
}
