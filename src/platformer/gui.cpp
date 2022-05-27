#include <platformer/entities/world/tiles.hpp>
#include "gui.hpp"
#include "framework.hpp"

int Gui::getHealth() const{
	return health;
}

void Gui::setHealth(int health){
	Gui::health = health;
	updateTexture();
}

int Gui::getKeys() const{
	return keys;
}

void Gui::setKeys(int keys){
	Gui::keys = keys;
	updateTexture();
}

int Gui::getCoins() const{
	return coins;
}

void Gui::setCoins(int coins){
	Gui::coins = coins;
	updateTexture();
}

int Gui::getDiamonds() const{
	return diamonds;
}

void Gui::setDiamonds(int diamonds){
	Gui::diamonds = diamonds;
	updateTexture();
}

void Gui::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw(sprite, states);
}

Gui::Gui(){
	textureInfo = Framework::getAssetStorage().getTextureInfo("tiles");
	updateTexture();
}

void Gui::updateTexture(){
	sprite.setTexture(Framework::getAssetStorage().getTexture(textureInfo.getName()));
	
	auto updateTextureRect = [this](const TileConfig& t){
		sprite.setTextureRect({
			static_cast<int>(t.texture_coord.x * (textureInfo.getSize().x + textureInfo.getMargin().x)),
			static_cast<int>(t.texture_coord.y * (textureInfo.getSize().y + textureInfo.getMargin().y)),
			textureInfo.getSize().x,
			textureInfo.getSize().y}
		);
	};
	
	sf::Vector2u size = Framework::getRenderer().getSize();
	
	texture.create(size.x, size.y);
	sf::RenderStates states;
	
	updateTextureRect(Tiles::hearth_full);
	for(int i = 1; i * 2 <= health; i++){
		texture.draw(sprite, states);
		states.transform.translate(sf::Vector2f(textureInfo.getSize().x, 0));
	}
	if(health % 2 == 1){
		updateTextureRect(Tiles::hearth_half);
		texture.draw(sprite, states);
		states.transform.translate(sf::Vector2f(textureInfo.getSize().x, 0));
	}
	updateTextureRect(Tiles::hearth_empty);
	for(int i = ((health + 1) / 2) * 2; i * 2 <= max_health; i++){
		texture.draw(sprite, states);
		states.transform.translate(sf::Vector2f(textureInfo.getSize().x, 0));
	}
	
	states.transform = sf::Transform::Identity;
	states.transform.translate(sf::Vector2f(0, textureInfo.getSize().y));
	updateTextureRect(Tiles::key);
	for(int i = 0; i < keys; i++){
		texture.draw(sprite, states);
		states.transform.translate(sf::Vector2f(textureInfo.getSize().x, 0));
	}
	
	texture.display();
	
	sprite.setTexture(texture.getTexture(), true);
}

/*
 * health = 3 ->
 * max_health = 6
 *
 *
 *
 */

