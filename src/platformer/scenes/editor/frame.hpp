#pragma once

#include <platformer/entities/entity.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Frame : public Entity{
	private:
		sf::RectangleShape shape;
		sf::Vector2f base_size;
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		void update(const sf::Time& time) override;
		Frame();
		void setBaseSize(const sf::Vector2f& size);
		void setSize(const sf::Vector2f& size);
		void setPosition(const sf::Vector2f& position);
};


