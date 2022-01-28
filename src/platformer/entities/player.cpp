#include <SFML/Graphics/RenderTarget.hpp>
#include <platformer/framework.hpp>
#include <platformer/entities/world/tiles.hpp>
#include "player.hpp"

void Player::update(const sf::Time& time){
	PhysicalEntity::update(time);
	b2Vec2 vec = body->GetLinearVelocity();
	vec.x = 0;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		vec.x -= 5;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		vec.x += 5;
	body->SetLinearVelocity(vec);
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		body->ApplyLinearImpulseToCenter({0, -0.5}, true);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	states.transform.combine(getTransform());
	target.draw(sprite, states);
}

Player::Player(b2World& world, const sf::Vector2i& position) : PhysicalEntity(world){
	sprite.setTexture(Framework::getAssetStorage().getTexture("tiles"));
	sprite.setTextureRect({static_cast<int>(Tiles::snowman.x * 20), static_cast<int>(Tiles::snowman.y * 20), 18, 18});
	
	b2BodyDef bodyDef;
	bodyDef.position = Framework::getPhysicConfig().pixelToMeters(sf::Vector2f(position.x * 18, position.y * 18));
	bodyDef.type = b2_dynamicBody;
	bodyDef.fixedRotation = true;
	create(bodyDef);
	
	b2PolygonShape shape;
	shape.SetAsBox(0.5,0.5,{0.5, 0.5},0);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 1.0;
	fixtureDef.friction = 0.3;
	addFixture(fixtureDef);
}
