#include <platformer/entities/world/tiles.hpp>
#include <platformer/scenes/play.hpp>
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
	for(int i = health; i * 2 <= max_health; i++){
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
	
	states.transform = sf::Transform::Identity;
	states.transform.translate(sf::Vector2f(0, 2 * textureInfo.getSize().y));
	updateTextureRect(Tiles::coin1);
	texture.draw(sprite, states);
	states.transform.translate(sf::Vector2f(textureInfo.getSize().x, 0));
	drawNumber(states, coins);
	
	states.transform = sf::Transform::Identity;
	states.transform.translate(sf::Vector2f(0, 3 * textureInfo.getSize().y));
	updateTextureRect(Tiles::diamond);
	texture.draw(sprite, states);
	states.transform.translate(sf::Vector2f(textureInfo.getSize().x, 0));
	drawNumber(states, diamonds);
	
	texture.display();
	
	sprite.setTexture(texture.getTexture(), true);
}

void Gui::updateTextureRect(const TileConfig& t){
	sprite.setTextureRect({
		static_cast<int>(t.texture_coord.x * (textureInfo.getSize().x + textureInfo.getMargin().x)),
		static_cast<int>(t.texture_coord.y * (textureInfo.getSize().y + textureInfo.getMargin().y)),
		textureInfo.getSize().x,
		textureInfo.getSize().y}
	);
}

void Gui::drawNumber(sf::RenderStates& states, int value){
	std::vector<int> digits;
	int x = value;
	if(x == 0)
		digits.push_back(0);
	while(x > 0){
		digits.push_back(x % 10);
		x /= 10;
	}
	std::reverse(digits.begin(), digits.end());
	for(auto d: digits){
		updateTextureRect(Tiles::number[d]);
		texture.draw(sprite, states);
		states.transform.translate(sf::Vector2f(textureInfo.getSize().x, 0));
	}
}

void Gui::onNotify(const std::shared_ptr<SceneEvent>& event){
	if(event->getEventId() == Play::DiamondCollected){
		diamonds++;
		updateTexture();
	}
	else if(event->getEventId() == Play::CoinCollected){
		coins++;
		updateTexture();
	}
}
