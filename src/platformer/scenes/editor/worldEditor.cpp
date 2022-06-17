#include <platformer/framework.hpp>
#include <platformer/scenes/editor.hpp>
#include <platformer/entities/world/tiles.hpp>
#include "worldEditor.hpp"

void WorldEditor::update(const sf::Time& time){
}

WorldEditor::WorldEditor(const sf::Vector2u& size) : size(size), textureInfo(Framework::getAssetStorage().getTextureInfo("tiles")){
	setRect(sf::FloatRect(0, 0, size.x * textureInfo.getSize().x, size.y * textureInfo.getSize().y));
	setTileSize(sf::Vector2f(textureInfo.getSize().x, textureInfo.getSize().y));
	
	texture.create(textureInfo.getSize().x * size.x, textureInfo.getSize().y * size.y);
	
	tiles.resize(size.x, std::vector<TileConfig>(size.y, Tiles::empty));
	redraw();
}

void WorldEditor::redraw(){
	sf::Sprite tmp;
	tmp.setTexture(Framework::getAssetStorage().getTexture("tiles"));
	texture.clear(sf::Color::Transparent);
	
	sf::RenderStates states;
	for(auto& vec : tiles){
		for(auto& t : vec){
			if(t.texture_coord != Tiles::empty.texture_coord){
				tmp.setTextureRect(
						{static_cast<int>(t.texture_coord.x * (textureInfo.getSize().x + textureInfo.getMargin().x)),
						 static_cast<int>(t.texture_coord.y * (textureInfo.getSize().y + textureInfo.getMargin().y)),
						 textureInfo.getSize().x,
						 textureInfo.getSize().y}
				);
				texture.draw(tmp, states);
			}
			states.transform.translate(0, textureInfo.getSize().y);
		}
		states.transform.translate(textureInfo.getSize().x, -textureInfo.getSize().y * static_cast<float>(size.y));
	}
	
	texture.display();
	
	sprite.setTexture(texture.getTexture(), true);
}

void WorldEditor::updateTile(const TileConfig& type, const sf::Vector2i& tile){
	if(0 <= tile.x && tile.x < size.x && 0 <= tile.y && tile.y < size.y)
		tiles[tile.x][tile.y] = type;
}

const sf::Vector2u& WorldEditor::getSize() const{
	return size;
}

std::vector<TileConfig>& WorldEditor::operator [](std::size_t i){
	return tiles[i];
}

const std::vector<TileConfig>& WorldEditor::operator [](std::size_t i) const{
	return tiles[i];
}

void WorldEditor::set(const std::vector<std::vector<TileConfig>>& tiles){
	size = sf::Vector2u(tiles.size(), tiles.size() == 0 ? 0 : tiles[0].size());
	this->tiles = tiles;
	redraw();
}
