#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>

class Entity : public sf::Drawable, public sf::Transformable{
	public:
		virtual void update(const sf::Time& time) = 0;
		virtual ~Entity() = default;
		
		virtual void activate();
		virtual void deactivate();
};


