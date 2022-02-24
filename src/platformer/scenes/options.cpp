#include "options.h"
#include "../gui/button.hpp"
#include "../framework.hpp"
#include "play.hpp"

Options::Options(StateMachine& stateMachine) : Scene(stateMachine)
{
    Button* buttonContinue = new Button();
    buttonContinue->getSprite() = {};

    buttonContinue->getText().setFont(Framework::getAssetStorage().getFont("pixeled"));
    buttonContinue->getText().setString("Continue");
    buttonContinue->getText().setCharacterSize(50);
    buttonContinue->getText().setFillColor(sf::Color::Magenta);
    buttonContinue->setPosition(Framework::getRenderer().getSize().x / 2, Framework::getRenderer().getSize().y / 4);

    buttonContinue->setOnHoverStart([buttonContinue]{buttonContinue->getText().setFillColor(sf::Color::Cyan);});
    buttonContinue->setOnHoverEnd([buttonContinue]{buttonContinue->getText().setFillColor(sf::Color::Magenta);});
    buttonContinue->setOnButtonPressed([buttonContinue, this]{getStateMachine().pop();});
    buttonContinue->setOnButtonReleased([buttonContinue]{buttonContinue->getText().setFillColor(sf::Color::Cyan);});

    Button* buttonPlayAgain = new Button();
    buttonPlayAgain->getSprite() = {};

    buttonPlayAgain->getText().setFont(Framework::getAssetStorage().getFont("pixeled"));
    buttonPlayAgain->getText().setString("Restart");
    buttonPlayAgain->getText().setCharacterSize(50);
    buttonPlayAgain->getText().setFillColor(sf::Color::Green);
    buttonPlayAgain->setPosition(Framework::getRenderer().getSize().x / 2, Framework::getRenderer().getSize().y / 2);

    buttonPlayAgain->setOnHoverStart([buttonPlayAgain]{buttonPlayAgain->getText().setFillColor(sf::Color::Blue);});
    buttonPlayAgain->setOnHoverEnd([buttonPlayAgain]{buttonPlayAgain->getText().setFillColor(sf::Color::Green);});
    buttonPlayAgain->setOnButtonPressed([buttonPlayAgain, this]{getStateMachine().replace(new Play(getStateMachine()));});
    buttonPlayAgain->setOnButtonReleased([buttonPlayAgain]{buttonPlayAgain->getText().setFillColor(sf::Color::Red);});

    entities.push_back(buttonPlayAgain);
    entities.push_back(buttonContinue);
}

void Options::onNotify(const sf::Event& event)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        getStateMachine().pop();
}

void Options::update(const sf::Time& time)
{
    Scene::update(time);
}