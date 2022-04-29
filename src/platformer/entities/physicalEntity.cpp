#include "physicalEntity.hpp"
#include "platformer/framework.hpp"

void PhysicalEntity::build(b2World& world){
	this->world = world;
	
	b2BodyDef bodyDef;
	bodyDef.position = Framework::getPhysicConfig().pixelToMeters(sf::Vector2f(position.x * 18, position.y * 18));
	bodyDef.type = b2_dynamicBody;
	bodyDef.fixedRotation = true;
	create(bodyDef);
	
	b2PolygonShape shape;
	shape.SetAsBox(hitboxSize.x / 2, hitboxSize.y / 2, hitboxCenter,0);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 1.0;
	fixtureDef.friction = 0;
	fixtureDef.filter.categoryBits = properties.type;
	fixtureDef.filter.maskBits = properties.mask;
	addFixture(fixtureDef);
}

void to_json(json& j, const PhysicalEntity& p){
	
}

void from_json(const json& j, PhysicalEntity& p){
	j["hitboxCenter"].get_to(p.hitboxCenter);
	j["hitboxSize"].get_to(p.hitboxSize);
	p.position = j["position"].get<sf::Vector2i>();
	j["properties"].get_to(p.properties);
}

void to_json(json& j, const b2BodyDef& b2){
	j["position"] = b2.position;
	j["angle"] = b2.angle;
	j["linearVelocity"] = b2.linearVelocity;
	j["angularVelocity"] = b2.angularVelocity;
	j["linearDamping"] = b2.linearDamping;
	j["angularDamping"] = b2.angularDamping;
	j["allowSleep"] = b2.allowSleep;
	j["awake"] = b2.awake;
	j["fixedRotation"] = b2.fixedRotation;
	j["bullet"] = b2.bullet;
	j["type"] = b2.type;
	j["enabled"] = b2.enabled;
	j["gravityScale"] = b2.gravityScale;
}

void from_json(const json& j, b2BodyDef& b2){
	j["position"].get_to(b2.position);
	j["angle"].get_to(b2.angle);
	j["linearVelocity"].get_to(b2.linearVelocity);
	j["angularVelocity"].get_to(b2.angularVelocity);
	j["linearDamping"].get_to(b2.linearDamping);
	j["angularDamping"].get_to(b2.angularDamping);
	j["allowSleep"].get_to(b2.allowSleep);
	j["awake"].get_to(b2.awake);
	j["fixedRotation"].get_to(b2.fixedRotation);
	j["bullet"].get_to(b2.bullet);
	j["type"].get_to(b2.type);
	j["enabled"].get_to(b2.enabled);
	j["gravityScale"].get_to(b2.gravityScale);
}

void to_json(json& j, const b2FixtureDef& b2){
	j["shape"] = *(b2.shape);
	j["friction"] = b2.friction;
	j["restitution"] = b2.restitution;
	j["restitutionThreshold"] = b2.restitutionThreshold;
	j["density"] = b2.density;
	j["isSensor"] = b2.isSensor;
}

void from_json(const json& j, b2FixtureDef& b2){
	b2.shape = j["shape"].get<b2Shape*>();
	j["friction"].get_to(b2.friction);
	j["restitution"].get_to(b2.restitution);
	j["restitutionThreshold"].get_to(b2.restitutionThreshold);
	j["density"].get_to(b2.density);
	j["isSensor"].get_to(b2.isSensor);
}

void to_json(json& j, const b2Vec2& b2){
	j["x"] = b2.x;
	j["y"] = b2.y;
}

void from_json(const json& j, b2Vec2& b2){
	j["x"].get_to(b2.x);
	j["y"].get_to(b2.y);
}

template<class T>
void to_json(json& j, const sf::Vector2<T>& vec){

}

template<class T>
void from_json(const json& j, sf::Vector2<T>& vec){

}

void to_json(json& j, const b2Shape& b2){
	j["type"] = b2.m_type;
	if(b2.m_type == b2Shape::e_circle)
		j["radius"] = b2.m_radius;
}

void from_json(const json& j, b2Shape*& b2){
	j["type"].get_to(b2->m_type);
	if(j.contains("radius"))
		j["radius"].get_to(b2->m_radius);
}

void PhysicalEntity::update(const sf::Time& time){
	setPosition(Framework::getPhysicConfig().metersToPixel(body->GetPosition()));
	setRotation(180 * body->GetAngle() / b2_pi);
}

void PhysicalEntity::create(const b2BodyDef& bodyDef){
	body = world.get().CreateBody(&bodyDef);
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

void PhysicalEntity::setMovingLeft(){
	if(properties.movementFlag){
		b2Vec2 vec = body->GetLinearVelocity();
		vec.x = -properties.movement.speed;
		body->SetLinearVelocity(vec);
	}
}

void PhysicalEntity::setMovingRight(){
	if(properties.movementFlag){
		b2Vec2 vec = body->GetLinearVelocity();
		vec.x = properties.movement.speed;
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

const EntityProperties& PhysicalEntity::getProperties() const{
	return properties;
}

EntityProperties& PhysicalEntity::getProperties(){
	return properties;
}
