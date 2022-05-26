#include <platformer/framework.hpp>
#include "inputButton.hpp"

InputButton::InputButton(const sf::Vector2f& position, const std::string& default_text = "") :
		CheckboxButton(position, []{}, []{}, false),
		default_text(default_text),
		text(""){
	getSprite().setTextureRect(sf::IntRect(190, 0, 190, 49));
	
	onButtonPressed = [this]{};
	
	onButtonReleased = [this]{};
	
	Widget::getText().setFont(Framework::getAssetStorage().getFont("pixeled"));
	Widget::getText().setCharacterSize(20);
	Widget::getText().setString(text);
	
	setCenter(position);
}

void InputButton::onNotify(const sf::Event& event){
	CheckboxButton::onNotify(event);
	if(isPressed() && event.type == sf::Event::TextEntered){
		text += event.text.unicode;
		if(text.getSize() != 0)
			Widget::getText().setString(text);
		else
			Widget::getText().setString(default_text);
	}
}

const std::string& InputButton::getDefaultText() const{
	return default_text;
}

const sf::String& InputButton::getText() const{
	return text;
}
