#pragma once

#include "collectible.hpp"

class Coin : public Collectible{
	public:
		Coin();
		void collect(PhysicalEntity& physicalEntity) override;
};


