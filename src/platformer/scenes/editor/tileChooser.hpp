#pragma once

#include <platformer/entities/entity.hpp>
#include <platformer/gui/CoordChooser.hpp>

class TileChooser : public Entity, public CoordChooser{
	public:
		TileChooser();
		void update(const sf::Time& time) override;
};


