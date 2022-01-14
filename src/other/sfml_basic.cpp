#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <box2d/box2d.h>

sf::Vector2f metersToPixel(const b2Vec2 vec){
    return {vec.x * 10, vec.y * 10};
}

int main(){
	sf::RenderWindow window;
	window.create(sf::VideoMode(500, 700), "Hello world");
	//window.setFramerateLimit(60);
	
	sf::RectangleShape circle;
	circle.setSize({40, 40});
	circle.setFillColor(sf::Color::Red);
    circle.setOrigin(20, 20);

    sf::RectangleShape boxes[20];
    for(int i = 0; i < 20; i++){
        boxes[i].setSize({40, 40});
        boxes[i].setFillColor(sf::Color::Green);
        boxes[i].setOrigin(20, 20);
    }
    sf::RectangleShape groundGraphics;
    groundGraphics.setSize({400, 50});
    groundGraphics.setOrigin(200, 25);
	
	sf::Texture texW, texA, texS, texD, texWl, texAl, texSl, texDl;
	texW.loadFromFile("../assets/textures/keyboard_and_controller/Keyboard & Mouse/Dark/W_Key_Dark.png");
	texA.loadFromFile("../assets/textures/keyboard_and_controller/Keyboard & Mouse/Dark/A_Key_Dark.png");
	texS.loadFromFile("../assets/textures/keyboard_and_controller/Keyboard & Mouse/Dark/S_Key_Dark.png");
	texD.loadFromFile("../assets/textures/keyboard_and_controller/Keyboard & Mouse/Dark/D_Key_Dark.png");
	texWl.loadFromFile("../assets/textures/keyboard_and_controller/Keyboard & Mouse/Light/W_Key_Light.png");
	texAl.loadFromFile("../assets/textures/keyboard_and_controller/Keyboard & Mouse/Light/A_Key_Light.png");
	texSl.loadFromFile("../assets/textures/keyboard_and_controller/Keyboard & Mouse/Light/S_Key_Light.png");
	texDl.loadFromFile("../assets/textures/keyboard_and_controller/Keyboard & Mouse/Light/D_Key_Light.png");
	
	sf::Sprite sprW, sprA, sprS, sprD;
	sprW.setTexture(texW);
	sprA.setTexture(texA);
	sprS.setTexture(texS);
	sprD.setTexture(texD);
	sprW.setPosition(texA.getSize().x, 0);
	sprA.setPosition(0, texA.getSize().y);
	sprS.setPosition(texA.getSize().x, texA.getSize().y);
	sprD.setPosition(2 * texA.getSize().x, texA.getSize().y);

    // fizyka:

    b2World world(b2Vec2(0, 10));

    b2Body* bodyBoxes[20];
    for(int i = 0; i < 20; i++) {
        b2BodyDef bodyDef;
        bodyDef.position = b2Vec2(10, -5 * i);
        bodyDef.type = b2_dynamicBody;

        bodyBoxes[i] = world.CreateBody(&bodyDef);

        b2PolygonShape polygonShape;
        polygonShape.SetAsBox(2, 2); // Tak na prawdę to jest 4x4m

        b2FixtureDef fixture;
        fixture.shape = &polygonShape;
        fixture.density = 1.0;
        fixture.friction = 0.3;

        bodyBoxes[i]->CreateFixture(&fixture);
    }
    b2BodyDef bodyDef;
    bodyDef.position = b2Vec2(30, 5);
    bodyDef.type = b2_dynamicBody;

    b2Body* body = world.CreateBody(&bodyDef);

    b2PolygonShape polygonShape;
    polygonShape.SetAsBox(2, 2); // Tak na prawdę to jest 4x4m

    b2FixtureDef fixture;
    fixture.shape = &polygonShape;
    fixture.density = 1.0;
    fixture.friction = 0.3;

    body->CreateFixture(&fixture);


    b2BodyDef groundDef;
    groundDef.position = b2Vec2(25, 60);
    groundDef.type = b2_staticBody;

    b2Body* ground = world.CreateBody(&groundDef);

    b2PolygonShape polygonShape2;
    polygonShape2.SetAsBox(20, 2.5); // Tak na prawdę to jest 400x5m

    b2FixtureDef fixture2;
    fixture2.shape = &polygonShape2;
    fixture2.density = 1.0;
    fixture2.friction = 0.3;

    ground->CreateFixture(&fixture2);
    groundGraphics.setPosition(metersToPixel(ground->GetPosition()));

    // coś dalej

	sf::SoundBuffer soundDef;
	soundDef.loadFromFile("../assets/sounds/jump.ogg");
	
	sf::Sound sound;
	sound.setBuffer(soundDef);
	
	sf::Clock clock;
	sf::Time frame;
	while(window.isOpen()){
		frame = clock.restart();
		// obsługa eventów
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window.close();
			if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::W)
					sprW.setTexture(texWl);
				if(event.key.code == sf::Keyboard::A)
					sprA.setTexture(texAl);
				if(event.key.code == sf::Keyboard::S)
					sprS.setTexture(texSl);
				if(event.key.code == sf::Keyboard::D)
					sprD.setTexture(texDl);
				if(event.key.code == sf::Keyboard::Space)
					sound.play();
			}
			if(event.type == sf::Event::KeyReleased){
				if(event.key.code == sf::Keyboard::W)
					sprW.setTexture(texW);
				if(event.key.code == sf::Keyboard::A)
					sprA.setTexture(texA);
				if(event.key.code == sf::Keyboard::S)
					sprS.setTexture(texS);
				if(event.key.code == sf::Keyboard::D)
					sprD.setTexture(texD);
			}
		}
		// update
		b2Vec2 v = body->GetLinearVelocity();
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            v.x = -1;
		//if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
       //     v.y = 1;
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            v.x = 1;
        body->SetLinearVelocity(v);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            body->ApplyLinearImpulseToCenter({0, -1}, true);

        world.Step(frame.asSeconds(), 8, 3);

        for(int i = 0; i < 20; i++){
            boxes[i].setPosition(metersToPixel(bodyBoxes[i]->GetPosition()));
            boxes[i].setRotation(180 * bodyBoxes[i]->GetAngle() / b2_pi);
        }
        circle.setPosition(metersToPixel(body->GetPosition()));
        circle.setRotation(180 * body->GetAngle() / b2_pi);
		// draw
		window.clear();
		window.draw(circle);
		window.draw(sprW);
		window.draw(sprA);
		window.draw(sprS);
		window.draw(sprD);
        window.draw(groundGraphics);
        for(int i = 0; i < 20; i++){
            window.draw(boxes[i]);
        }
		window.display();
	}
	
	window.close();
}