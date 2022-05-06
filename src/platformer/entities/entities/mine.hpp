#pragma once

#include <platformer/entities/physicalEntity.hpp>

class Mine : public PhysicalEntity{
	private:
		sf::Time timer;
		bool facingLeft = false;
	public:
		Mine();
		void update(const sf::Time& time) override;
};


