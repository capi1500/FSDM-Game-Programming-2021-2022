#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include "physicalEntity.hpp"

class Player : public PhysicalEntity, public Listener<sf::Event>{
	private:
		sf::Sprite sprite;
		
		bool canDoubleJump = false;
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		Player(b2World& world, const sf::Vector2i& position);
		
		void onNotify(const sf::Event& event) override;
		void update(const sf::Time& time) override;
};


