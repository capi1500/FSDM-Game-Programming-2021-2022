#include <platformer/framework.hpp>
#include "world.hpp"

void World::build(b2World &world) {
	getFixtureDefs().clear();
	
	sf::Vector2u size = {static_cast<unsigned int>(tiles.size()), static_cast<unsigned int>(tiles.empty() ? 0 : tiles[0].size())};
	
	sf::Sprite tmp;
	tmp.setTexture(Framework::getAssetStorage().getTexture(getTextureInfo().getName()));
	texture->create(18 * size.x, 18 * size.y);

	sf::RenderStates states;
	for(auto& vec : tiles){
		for(auto& t : vec){
			if(t.texture_coord != Tiles::empty.texture_coord){
				tmp.setTextureRect({
					static_cast<int>(t.texture_coord.x * 20),
					static_cast<int>(t.texture_coord.y * 20),
					18,
					18});
				texture->draw(tmp, states);
			}
			states.transform.translate(0, 18);
		}
		states.transform.translate(18, -18 * static_cast<float>(size.y));
	}
	
	texture->display();
	
	sprite->setTexture(texture->getTexture());
	
	PhysicalEntity::build(world);
	
	auto createBox = [this](int x, int y, int beg){
		b2PolygonShape shape;
		shape.SetAsBox(0.75f * static_cast<float>(x - beg) / 2.f,
		               0.75 * 0.5,
		               Framework::getPhysicConfig().pixelToMeters(
							   sf::Vector2f(static_cast<float>(9 * (x + beg)),
											18 * (static_cast<float>(y) + 0.5f))),
		               0);
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &shape;
		fixtureDef.density = 1.0;
		fixtureDef.friction = 0.3;
		fixtureDef.filter.categoryBits = EntityProperties::EntityType::Ground;
		fixtureDef.filter.maskBits = EntityTypeBuilder().collectible(true).player(true).npc(true).build();
		addFixture(fixtureDef);
	};
	
	for(unsigned y = 0; y < size.y; y++){
		int beg = -1;
		for(unsigned x = 0; x < size.x; x++){
			if(!tiles[x][y].solid && beg != -1){
				createBox(static_cast<int>(x), static_cast<int>(y), beg);
				beg = -1;
			}
			else if(tiles[x][y].solid && beg == -1){
				beg = static_cast<int>(x);
			}
		}
		if(beg != -1){
			createBox(static_cast<int>(size.x), static_cast<int>(y), beg);
		}
	}
	
	properties.solidFlag = true;
	properties.type = EntityProperties::Ground;
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	states.transform.combine(getTransform());
	target.draw(*sprite, states);
}

std::vector<std::vector<TileConfig>>& World::getTiles(){
	return tiles;
}

const std::vector<std::vector<TileConfig>>& World::getTiles() const{
	return tiles;
}

void World::setTiles(const std::vector<std::vector<TileConfig>>& tiles){
	World::tiles = tiles;
}
