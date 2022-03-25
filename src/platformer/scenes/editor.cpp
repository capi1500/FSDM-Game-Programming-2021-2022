#include <platformer/scenes/editor/worldEditor.hpp>
#include "editor.hpp"

void Editor::onNotify(const sf::Event& event){

}

void Editor::onNotify(const std::shared_ptr<SceneEvent>& event){

}

Editor::Editor(StateMachine& stateMachine) : Scene(stateMachine){
	entities.push_back(new WorldEditor({50, 20}));
}
