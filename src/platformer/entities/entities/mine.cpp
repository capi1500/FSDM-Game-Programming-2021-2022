#include <platformer/entities/world/characters.h>
#include <platformer/framework.hpp>
#include "mine.hpp"

void Mine::update(const sf::Time& time){
	PhysicalEntity::update(time);
	timer += time;
	if(timer >= sf::seconds(1)){
		facingLeft = !facingLeft;
		timer -= sf::seconds(1);
	}
	if(facingLeft)
		setMovingLeft();
	else
		setMovingRight();
}

Mine::Mine(){
	setTextureInfo(Framework::getAssetStorage().getTextureInfo("characters"));
}
