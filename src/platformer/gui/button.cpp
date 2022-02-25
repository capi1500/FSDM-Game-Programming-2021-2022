#include <platformer/framework.hpp>
#include <iostream>
#include "button.hpp"

void Button::setOnHoverStart(const std::function<void()>& onHoverStart){
	Button::onHoverStart = onHoverStart;
}

void Button::setOnHoverEnd(const std::function<void()>& onHoverEnd){
	Button::onHoverEnd = onHoverEnd;
}

void Button::setOnButtonPressed(const std::function<void()>& onButtonPressed){
	Button::onButtonPressed = onButtonPressed;
}

void Button::setOnButtonReleased(const std::function<void()>& onButtonReleased){
	Button::onButtonReleased = onButtonReleased;
}

void Button::onNotify(const sf::Event& event){
	if(!pressed){
		if(event.type == sf::Event::MouseMoved){
			if(!hover && getGlobalBounds().contains(Framework::getRenderer().mapPixelToCoords({event.mouseMove.x, event.mouseMove.y}))){
				hover = true;
				onHoverStart();
			}
			else if(hover && !getGlobalBounds().contains(Framework::getRenderer().mapPixelToCoords({event.mouseMove.x, event.mouseMove.y}))){
				hover = false;
				onHoverEnd();
			}
		}
		else if(hover && event.type == sf::Event::MouseButtonPressed){
			pressed = true;
			onButtonPressed();
		}
	}
	else{
		if(event.type == sf::Event::MouseButtonReleased){
			pressed = false;
			if(getGlobalBounds().contains(Framework::getRenderer().mapPixelToCoords({event.mouseButton.x, event.mouseButton.y}))){
				onButtonReleased();
				onHoverStart();
			}
			else{
				hover = false;
				onHoverEnd();
			}
		}
	}
}

Button::Button(){
	Framework::getInputHandler().subscribe(this);
}

Button::~Button(){
	Framework::getInputHandler().unsubscribe(this);
}

ButtonBuilder& ButtonBuilder::setOnHoverStart(const std::function<void()>& onHoverStart){
	ButtonBuilder::onHoverStart = onHoverStart;
}

ButtonBuilder& ButtonBuilder::setOnHoverEnd(const std::function<void()>& onHoverEnd){
	ButtonBuilder::onHoverEnd = onHoverEnd;
}

ButtonBuilder& ButtonBuilder::setOnButtonPressed(const std::function<void()>& onButtonPressed){
	ButtonBuilder::onButtonPressed = onButtonPressed;
}

ButtonBuilder& ButtonBuilder::setOnButtonReleased(const std::function<void()>& onButtonReleased){
	ButtonBuilder::onButtonReleased = onButtonReleased;
}

Button ButtonBuilder::create(){
	Button button;
	button.setOnHoverStart(onHoverStart);
	button.setOnHoverEnd(onHoverEnd);
	button.setOnButtonPressed(onButtonPressed);
	button.setOnButtonReleased(onButtonReleased);
	return button;
}

Button* ButtonBuilder::createPtr(){
	Button* button = new Button();
	button->setOnHoverStart(onHoverStart);
	button->setOnHoverEnd(onHoverEnd);
	button->setOnButtonPressed(onButtonPressed);
	button->setOnButtonReleased(onButtonReleased);
	return button;
}
