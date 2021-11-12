#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main(){
	sf::RenderWindow window;
	window.create(sf::VideoMode(500, 700), "Hello world");
	//window.setFramerateLimit(60);
	
	sf::CircleShape circle;
	circle.setRadius(50);
	circle.setPosition(200, 200);
	circle.setFillColor(sf::Color::Red);
	
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
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			circle.move(0, -100 * frame.asSeconds());
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			circle.move(-100 * frame.asSeconds(), 0);
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			circle.move(0, 100 * frame.asSeconds());
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			circle.move(100 * frame.asSeconds(), 0);
		// draw
		window.clear();
		window.draw(circle);
		window.draw(sprW);
		window.draw(sprA);
		window.draw(sprS);
		window.draw(sprD);
		window.display();
	}
	
	window.close();
}