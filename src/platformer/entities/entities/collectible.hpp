#pragma once

#include <platformer/entities/physicalEntity.hpp>

class Collectible : public PhysicalEntity{
	public:
		virtual void collect(PhysicalEntity& physicalEntity) = 0;
};


