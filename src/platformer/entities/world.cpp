#include <platformer/framework.hpp>
#include <iostream>
#include "world.hpp"

WorldBuilder::WorldBuilder(b2World& world, const sf::Vector2u& size) : world(world), size(size){
	solid.resize(size.x, std::vector<bool>(size.y, false));
	type.resize(size.x, std::vector<sf::Vector2u>(size.y, sf::Vector2u(-1, -1)));
}

World WorldBuilder::create(){
	return World(*this);
}

World* WorldBuilder::create_ptr(){
	return new World(*this);
}

WorldBuilder& WorldBuilder::setTile(const sf::Vector2u& position, const sf::Vector2u& tile, bool solid){
	this->solid[position.x][position.y] = solid;
	type[position.x][position.y] = tile;
	return *this;
}

World::World(WorldBuilder& worldBuilder) : PhysicalEntity(worldBuilder.world){
	std::swap(size, worldBuilder.size);
	std::swap(solid, worldBuilder.solid);
	std::swap(type, worldBuilder.type);
	
	sf::Sprite tmp;
	tmp.setTexture(Framework::getAssetStorage().getTexture("tiles"));
	texture.create(18 * size.x, 18 * size.y);

	sf::RenderStates states;
	for(auto& vec : type){
		for(auto& t : vec){
			if(t != sf::Vector2u(-1, -1)){
				tmp.setTextureRect({static_cast<int>(t.x * 20), static_cast<int>(t.y * 20), 18, 18});
				texture.draw(tmp, states);
			}
			states.transform.translate(0, 18);
		}
		states.transform.translate(18, -18 * static_cast<float>(size.y));
	}
	
	texture.display();
	
	sprite.setTexture(texture.getTexture());
	//sprite.setOrigin(9 * size.x, 9 * size.y);
	
	b2BodyDef bodyDef;
	create(bodyDef);
	
	auto createBox = [this](int x, int y, int beg){
		b2PolygonShape shape;
		shape.SetAsBox((x - beg) / 2.f,
		               0.5,
		               Framework::getPhysicConfig().pixelToMeters(sf::Vector2f(9 * (x + beg), 18 * (y + 0.5))),
		               0);
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &shape;
		fixtureDef.density = 1.0;
		fixtureDef.friction = 0.3;
		addFixture(fixtureDef);
	};
	
	for(int y = 0; y < size.y; y++){
		int beg = -1;
		for(int x = 0; x < size.x; x++){
			if(!solid[x][y] && beg != -1){
				createBox(x, y, beg);
				beg = -1;
			}
			else if(solid[x][y] && beg == -1){
				beg = x;
			}
		}
		if(beg != -1){
			createBox(size.x, y, beg);
		}
	}
	
	properties.solidFlag = true;
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	states.transform.combine(getTransform());
	target.draw(sprite, states);
}
