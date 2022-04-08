#include <platformer/framework.hpp>
#include "checkboxButton.hpp"

CheckboxButton::CheckboxButton(const sf::Vector2f& position, const std::function<void()>& actionOnPressed, const std::function<void()>& actionOnReleased, bool defaultState){
	getSprite().setTexture(Framework::getAssetStorage().getTexture("ui_pack"));
	sf::IntRect statesRect[2] = {sf::IntRect(380, 36, 38, 36),
								 sf::IntRect(380, 0 , 38, 36)};
	state = defaultState;
	getSprite().setTextureRect(statesRect[defaultState]);
	
	onButtonPressed = [this, statesRect, actionOnPressed]{
		getSprite().setTextureRect(statesRect[1]);
		actionOnPressed();
	};
	
	onButtonReleased = [this, statesRect, actionOnReleased]{
		getSprite().setTextureRect(statesRect[0]);
		actionOnReleased();
	};
	
	if(defaultState)
		actionOnPressed();
	else
		actionOnReleased();
	
	setCenter(position);
	activate();
}

void CheckboxButton::onNotify(const sf::Event& event){
	if(!pressed){
		if(event.type == sf::Event::MouseMoved){
			if(!hover && getGlobalBounds().contains(Framework::getRenderer().mapPixelToCoords({event.mouseMove.x, event.mouseMove.y}, getView()))){
				hover = true;
			}
			else if(hover && !getGlobalBounds().contains(Framework::getRenderer().mapPixelToCoords({event.mouseMove.x, event.mouseMove.y}, getView()))){
				hover = false;
			}
		}
		else if(hover && event.type == sf::Event::MouseButtonPressed){
			pressed = true;
		}
	}
	else{
		if(event.type == sf::Event::MouseButtonReleased){
			pressed = false;
			if(getGlobalBounds().contains(Framework::getRenderer().mapPixelToCoords({event.mouseButton.x, event.mouseButton.y}, getView()))){
				state = !state;
				if(state)
					onButtonPressed();
				else
					onButtonReleased();
			}
			else{
				hover = false;
			}
		}
	}
}

void CheckboxButton::activate(){
	Framework::getInputHandler().subscribe(this);
}

void CheckboxButton::deactivate(){
	Framework::getInputHandler().unsubscribe(this);
}

CheckboxButton::~CheckboxButton(){
	deactivate();
}
