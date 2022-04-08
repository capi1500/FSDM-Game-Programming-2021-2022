#pragma once

#include "platformer/entities/entity.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/View.hpp>

class Widget : public Entity{
	private:
		sf::Sprite sprite;
		sf::Text text;
		bool centeredText = true;
		sf::View view;
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		Widget();
		void update(const sf::Time& time) override;
		
		sf::Sprite& getSprite();
		sf::Text& getText();
		const sf::Sprite& getSprite() const;
		const sf::Text& getText() const;
		
		void setCenter(const sf::Vector2f& center);
		
		bool isCenteredText() const;
		void setCenteredText(bool centeredText);
		
		const sf::View& getView() const;
		void setView(const sf::View& view);
		sf::FloatRect getGlobalBounds() const;
};


