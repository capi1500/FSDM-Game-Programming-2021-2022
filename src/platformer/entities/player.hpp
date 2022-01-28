#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include "physicalEntity.hpp"

class Player : public PhysicalEntity{
	private:
		sf::Sprite sprite;
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		Player(b2World& world, const sf::Vector2i& position);
		
		void update(const sf::Time& time) override;
};


