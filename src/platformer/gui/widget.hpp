#pragma once

#include "platformer/entities/entity.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

class Widget : public Entity{
	private:
		sf::Sprite sprite;
		sf::Text text;
		bool centeredText = true;
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		void update(const sf::Time& time) override;
		
		sf::Sprite& getSprite();
		sf::Text& getText();
		const sf::Sprite& getSprite() const;
		const sf::Text& getText() const;
		
		bool isCenteredText() const;
		void setCenteredText(bool centeredText);
		
		sf::FloatRect getGlobalBounds() const;
};


