#pragma once

#include "collectible.hpp"

class Diamond : public Collectible{
	public:
		Diamond();
		void collect(PhysicalEntity& physicalEntity) override;
};


