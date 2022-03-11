#include <platformer/framework.hpp>
#include "radioButton.hpp"
#include "radioButtonGroup.hpp"

RadioButton::RadioButton(const sf::Vector2f& position, const std::function<void()>& actionOnPressed, const std::function<void()>& actionOnReleased, bool defaultState, RadioButtonGroup& group) : CheckboxButton(position, actionOnPressed, actionOnReleased, defaultState){
	getSprite().setTexture(Framework::getAssetStorage().getTexture("ui_pack"));
	sf::IntRect statesRect[2] = {sf::IntRect(380, 36, 38, 36),
	                             sf::IntRect(380, 0 , 38, 36)};
	getSprite().setTextureRect(statesRect[defaultState]);
	
	onButtonPressed = [this, statesRect, actionOnPressed, &group]{
		getSprite().setTextureRect(statesRect[1]);
		state = true;
		group.buttonPressed(this);
		actionOnPressed();
	};
	
	onButtonReleased = [this, statesRect, actionOnReleased]{
		getSprite().setTextureRect(statesRect[0]);
		state = false;
		actionOnReleased();
	};
	
	group.group.insert(this);
	
	setCenter(position);
	activate();
}
