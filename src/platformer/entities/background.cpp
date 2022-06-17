#include <platformer/framework.hpp>
#include "background.hpp"

Background::Type Background::getType() const{
	return type;
}

void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	states.transform.translate(-display.left + offset.x, -display.top + offset.y);
	Entity::draw(target, states);
}

void Background::setType(Background::Type type){
	Background::type = type;
	updateTexture();
}

void Background::update(const sf::Time& time){

}

void Background::updateTexture(){
	sf::Sprite tmp;
	tmp.setTexture(Framework::getAssetStorage().getTexture("background"));
	TextureInfo textureInfo = Framework::getAssetStorage().getTextureInfo("background");

	
	
	int x_size = ceil(display.width / textureInfo.getSize().x);
	int y_size = ceil(display.height / textureInfo.getSize().y);
	
	texture->create(textureInfo.getSize().x * x_size, textureInfo.getSize().y * y_size);
	
	sf::RenderStates states;
	for(int x = -1; x <= x_size; x++){
		for(int y = -1; y <= y_size; y++){
			int o = 0;
			if(y == y_size / 2)
				o = 1;
			else if(y > y_size / 2)
				o = 2;
			tmp.setTextureRect({
                   static_cast<int>(((type % 2) * 3 + o) * (textureInfo.getSize().x + textureInfo.getMargin().x)),
                   static_cast<int>((type / 2) * (textureInfo.getSize().y + textureInfo.getMargin().y)),
                   textureInfo.getSize().x,
                   textureInfo.getSize().y});
			texture->draw(tmp, states);
			states.transform.translate(0, textureInfo.getSize().y);
		}
		states.transform.translate(textureInfo.getSize().x, -textureInfo.getSize().y * static_cast<float>(y_size + 2));
	}
	
	texture->display();
	
	sprite.setTexture(texture->getTexture());
}

const sf::FloatRect& Background::getDisplay() const{
	return display;
}

void Background::setDisplay(const sf::FloatRect& display){
	Background::display = display;
	updateTexture();
}

const sf::Vector2f& Background::getOffset() const{
	return offset;
}

void Background::setOffset(const sf::Vector2f& offset){
	Background::offset = offset;
	updateTexture();
}

Background::Background(){
	texture = std::make_shared<sf::RenderTexture>();
}
