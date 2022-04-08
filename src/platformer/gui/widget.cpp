#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>
#include <platformer/framework.hpp>
#include "widget.hpp"

/*
 * [(rect.left + rect.width) / 2, (rect.top + rect.height) / 2] == [(rect2.left + rect2.width) / 2, (rect2.top + rect2.height) / 2]
 * rect.left + rect.width - rect2.width == rect2.left
 *
 */

void Widget::update(const sf::Time& time){

}

void Widget::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	states.transform *= getTransform();
	target.draw(sprite, states);
	if(isCenteredText()){
		states.transform.translate({-(text.getGlobalBounds().left + text.getGlobalBounds().width - sprite.getGlobalBounds().left - sprite.getGlobalBounds().width) / 2,
									       -(text.getGlobalBounds().top + text.getGlobalBounds().height - sprite.getGlobalBounds().top - sprite.getGlobalBounds().height) / 2});
	}
	target.draw(text, states);
}

sf::Sprite& Widget::getSprite(){
	return sprite;
}

sf::Text& Widget::getText(){
	return text;
}

const sf::Sprite& Widget::getSprite() const{
	return sprite;
}

const sf::Text& Widget::getText() const{
	return text;
}

sf::FloatRect Widget::getGlobalBounds() const{
	const auto& rectS = getTransform().transformRect(sprite.getGlobalBounds());
	auto rectT = getTransform().transformRect(text.getGlobalBounds());
	if(isCenteredText()){
		rectT.left -= (text.getGlobalBounds().left + text.getGlobalBounds().width - sprite.getGlobalBounds().left - sprite.getGlobalBounds().width) / 2;
		rectT.top  -= (text.getGlobalBounds().top + text.getGlobalBounds().height - sprite.getGlobalBounds().top - sprite.getGlobalBounds().height) / 2;
	}
	float minX = std::min(rectS.left, rectT.left);
	float maxX = std::max(rectS.left + rectS.width, rectT.left + rectT.width);
	float minY = std::min(rectS.top, rectT.top);
	float maxY = std::max(rectS.top + rectS.height, rectT.top + rectT.height);
	
	return {minX, minY, maxX - minX, maxY - minY};
}

bool Widget::isCenteredText() const{
	return centeredText;
}

void Widget::setCenteredText(bool centeredText){
	Widget::centeredText = centeredText;
}

void Widget::setCenter(const sf::Vector2f& center){
	setPosition(center.x - getGlobalBounds().width / 2, center.y - getGlobalBounds().height / 2);
}

Widget::Widget(){
	view = Framework::getRenderer().getDefaultView();
}

const sf::View& Widget::getView() const{
	return view;
}

void Widget::setView(const sf::View& view){
	Widget::view = view;
}
