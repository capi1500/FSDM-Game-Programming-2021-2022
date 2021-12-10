#pragma once

#include <platformer/entity.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Image : public Entity{
	private:
		sf::Sprite sprite;
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		void update(const sf::Time& time) override;
		
		void setTexture(const sf::Texture& texture);
		
		sf::FloatRect getGlobalBounds() const;
};


