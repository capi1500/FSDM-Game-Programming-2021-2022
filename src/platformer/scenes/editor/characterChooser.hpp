#pragma once

#include <platformer/entities/entity.hpp>
#include <platformer/gui/CoordChooser.hpp>

class CharacterChooser : public Entity, public CoordChooser{
	public:
		CharacterChooser();
		void update(const sf::Time& time) override;
};


