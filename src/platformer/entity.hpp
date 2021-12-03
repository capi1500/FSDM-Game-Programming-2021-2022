#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>

class Entity : public sf::Drawable{
	public:
		virtual void update(const sf::Time& time) = 0;
		virtual ~Entity() = default;
};


