#include <SFML/Graphics/RectangleShape.hpp>
#include <platformer/framework.hpp>
#include <platformer/entities/PhysicalEntity.hpp>
#include "play.hpp"

Play::Play(StateMachine &stateMachine) : Scene(stateMachine), b2World(Framework::getPhysicConfig().gravity) {
	tiles.setTexture(Framework::getAssetStorage().getTexture("tiles"));
	tiles.setTextureSize({18, 18});
	tiles.setOffset({2, 2});
	
	background.setTexture(Framework::getAssetStorage().getTexture("background"));
	background.setTextureSize({24, 24});
	background.setOffset({2, 2});
	
	characters.setTexture(Framework::getAssetStorage().getTexture("characters"));
	characters.setTextureSize({24, 24});
	characters.setOffset({2, 2});
	
	ui.setTexture(Framework::getAssetStorage().getTexture("rpg ui"));
	ui.setTextureSize({18, 18});
	ui.setOffset({2, 2});
	
	b2BodyDef groundDef;
    groundDef.position = b2Vec2(25, 60);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(20, 2.5);

    b2FixtureDef groundFix;
    groundFix.shape = &groundBox;

    PhysicalEntity* ground = new PhysicalEntity(b2World);
    ground->create(groundDef);
    ground->addFixture(groundFix, new sf::RectangleShape({400, 50}));
    ground->setOrigin(200, 25);

    b2BodyDef movingDef;
    movingDef.position = b2Vec2(25, 5);
    movingDef.type = b2_dynamicBody;

    b2PolygonShape movingBox;
    movingBox.SetAsBox(2, 2);

    b2FixtureDef movingFix;
    movingFix.shape = &movingBox;
    movingFix.density = 1;
    movingFix.friction = 0.3;

    PhysicalEntity* moving = new PhysicalEntity(b2World);
    moving->create(movingDef);
    moving->addFixture(movingFix, new sf::RectangleShape({40, 40}));
    moving->setOrigin(20, 20);

    entities.push_back(ground);
    entities.push_back(moving);
}

void Play::onNotify(const sf::Event &event) {

}

void Play::update(const sf::Time &time) {
    Scene::update(time);
    b2World.Step(time.asSeconds(), Framework::getPhysicConfig().velocityIterations, Framework::getPhysicConfig().positionIterations);
}
