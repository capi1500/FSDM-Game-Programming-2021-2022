#include <platformer/framework.hpp>
#include <platformer/scenes/editor.hpp>
#include "worldEditor.hpp"
#include "tilePlacedEvent.hpp"

void WorldEditor::update(const sf::Time& time){
}

void WorldEditor::onNotify(const std::shared_ptr<SceneEvent>& event){
	if(event->getEventId() == Editor::TilePlaced){
		auto& e = dynamic_cast<TilePlacedEvent&>(*event);
		type[e.getCoord().x][e.getCoord().y] = e.getTexturePosition();
	}
}

WorldEditor::WorldEditor(const sf::Vector2u& size) : size(size), textureInfo(Framework::getAssetStorage().getTextureInfo("tiles")){

}

sf::Vector2i WorldEditor::getCoord(const sf::Vector2i& pixel){
	return sf::Vector2i(pixel.x / textureInfo.getSize().x, pixel.y / textureInfo.getSize().y);
}

void WorldEditor::redraw(){
	sf::Sprite tmp;
	tmp.setTexture(Framework::getAssetStorage().getTexture("tiles"));
	texture.create(18 * size.x, 18 * size.y);
	
	sf::RenderStates states;
	for(auto& vec : type){
		for(auto& t : vec){
			if(t != sf::Vector2u(-1, -1)){
				tmp.setTextureRect({static_cast<int>(t.x * 20), static_cast<int>(t.y * 20), 18, 18});
				texture.draw(tmp, states);
			}
			states.transform.translate(0, 18);
		}
		states.transform.translate(18, -18 * static_cast<float>(size.y));
	}
	
	texture.display();
	
	sprite.setTexture(texture.getTexture());
}
