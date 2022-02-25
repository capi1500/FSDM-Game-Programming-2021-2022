#include <iostream>
#include "options.h"
#include "../gui/button.hpp"
#include "../framework.hpp"
#include "play.hpp"

Options::Options(StateMachine& stateMachine) : Scene(stateMachine){
	Button* buttonContinue = new Button();
	buttonContinue->getSprite() = {};
	
	buttonContinue->getText().setFont(Framework::getAssetStorage().getFont("pixeled"));
	buttonContinue->getText().setString("Continue");
	buttonContinue->getText().setCharacterSize(50);
	buttonContinue->getText().setFillColor(sf::Color::Magenta);
	buttonContinue->setPosition(static_cast<float>(Framework::getRenderer().getSize().x) / 2.f, static_cast<float>(Framework::getRenderer().getSize().y) / 4.f);
	
	buttonContinue->setOnHoverStart([buttonContinue]{ buttonContinue->getText().setFillColor(sf::Color::Cyan); });
	buttonContinue->setOnHoverEnd([buttonContinue]{ buttonContinue->getText().setFillColor(sf::Color::Magenta); });
	buttonContinue->setOnButtonPressed([buttonContinue, this]{
		buttonContinue->getText().setFillColor(sf::Color::Cyan);
	});
	buttonContinue->setOnButtonReleased([buttonContinue, this]{
		getStateMachine().pop();
	});
	
	Button* buttonPlayAgain = new Button();
	buttonPlayAgain->getSprite() = {};
	
	buttonPlayAgain->getText().setFont(Framework::getAssetStorage().getFont("pixeled"));
	buttonPlayAgain->getText().setString("Restart");
	buttonPlayAgain->getText().setCharacterSize(50);
	buttonPlayAgain->getText().setFillColor(sf::Color::Green);
	buttonPlayAgain->setPosition(static_cast<float>(Framework::getRenderer().getSize().x) / 2.f, static_cast<float>(Framework::getRenderer().getSize().y) / 2.f);
	
	buttonPlayAgain->setOnHoverStart([buttonPlayAgain]{ buttonPlayAgain->getText().setFillColor(sf::Color::Blue); });
	buttonPlayAgain->setOnHoverEnd([buttonPlayAgain]{ buttonPlayAgain->getText().setFillColor(sf::Color::Green); });
	buttonPlayAgain->setOnButtonReleased([buttonPlayAgain, this]{
		buttonPlayAgain->getText().setFillColor(sf::Color::Red);
		getStateMachine().pop();
		getStateMachine().replace(new Play(getStateMachine()));
	});
	
	entities.push_back(buttonContinue);
	entities.push_back(buttonPlayAgain);
}

void Options::onNotify(const sf::Event& event){
	if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		getStateMachine().pop();
}

void Options::update(const sf::Time& time){
	Scene::update(time);
}