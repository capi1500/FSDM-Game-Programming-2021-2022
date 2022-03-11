#include <platformer/framework.hpp>
#include "longButton.hpp"

LongButton::LongButton(const sf::Vector2f& position, const std::string& text, const std::function<void()>& action){
	getSprite().setTexture(Framework::getAssetStorage().getTexture("ui_pack"));
	getSprite().setTextureRect(sf::IntRect(190, 0, 190, 49));
	getText().setFont(Framework::getAssetStorage().getFont("pixeled"));
	getText().setCharacterSize(20);
	getText().setString(text);
	
	setOnHoverStart([this]{
		getSprite().setTextureRect(sf::IntRect(0, 0, 190, 49));
	});
	setOnHoverEnd([this]{
		getSprite().setTextureRect(sf::IntRect(190, 0, 190, 49));
	});
	setOnButtonPressed([this]{
		getSprite().setTextureRect(sf::IntRect(0, 49, 190, 45));
	});
	setOnButtonReleased([this, action]{
		getSprite().setTextureRect(sf::IntRect(0, 0, 190, 49));
		action();
	});
	
	setCenter(position);
}
