#include "physicalEntity.hpp"
#include "platformer/framework.hpp"

PhysicalEntity::PhysicalEntity(b2World& world) : world(world){}

void PhysicalEntity::update(const sf::Time& time){
	setPosition(Framework::getPhysicConfig().metersToPixel(body->GetPosition()));
	setRotation(180 * body->GetAngle() / b2_pi);
}

void PhysicalEntity::create(const b2BodyDef& bodyDef){
	body = world.CreateBody(&bodyDef);
	body->GetUserData().pointer = reinterpret_cast<uintptr_t>(this);
}

b2Fixture* PhysicalEntity::addFixture(const b2FixtureDef& fixtureDef){
	b2Fixture* f = body->CreateFixture(&fixtureDef);
	return f;
}

void PhysicalEntity::jump(){
	if(properties.jumpFlag){
		if(!properties.jump.midAir){
			body->ApplyLinearImpulseToCenter({0, -body->GetMass() * properties.jump.height}, true);
			properties.jump.midAir = true;
		}
		else if(properties.doubleJumpFlag && !properties.doubleJump.midAir){
			body->ApplyLinearImpulseToCenter({0, -body->GetMass() * properties.doubleJump.height}, true);
			properties.doubleJump.midAir = true;
		}
	}
}

void PhysicalEntity::stop(){
	if(properties.movementFlag)
		body->SetLinearVelocity({0, body->GetLinearVelocity().y});
}

void PhysicalEntity::moveLeft(){
	if(properties.movementFlag){
		b2Vec2 vec = body->GetLinearVelocity();
		vec.x -= properties.movement.speed;
		body->SetLinearVelocity(vec);
	}
}

void PhysicalEntity::moveRight(){
	if(properties.movementFlag){
		b2Vec2 vec = body->GetLinearVelocity();
		vec.x += properties.movement.speed;
		body->SetLinearVelocity(vec);
	}
}

void PhysicalEntity::contactBegin(PhysicalEntity& entity, b2Contact* contact){
	if(entity.getProperties().solidFlag){
		if(properties.jumpFlag)
			properties.jump.midAir = false;
	}
}

void PhysicalEntity::contactEnd(PhysicalEntity& entity, b2Contact* contact){
	if(entity.getProperties().solidFlag){
		if(properties.jumpFlag)
			properties.jump.midAir = true;
		if(properties.doubleJumpFlag)
			properties.doubleJump.midAir = false;
	}
}

int PhysicalEntity::getCollisionPrecedence() const{
	return collisionPrecedence;
}

const EntityProperties& PhysicalEntity::getProperties() const{
	return properties;
}
