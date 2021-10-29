#include <iostream>
#include "board.hpp"
#include "player.hpp"
#include <SFML/Graphics.hpp>

int main(){
	sf::RenderWindow window;
	window.create(sf::VideoMode(500, 700), "Hello world");
	
	sf::CircleShape circle;
	circle.setRadius(50);
	circle.setPosition(200, 200);
	circle.setFillColor(sf::Color::Red);
	
	sf::Texture texW, texA, texS, texD;
	texW.loadFromFile("../assets/textures/keyboard_and_controller/Keyboard & Mouse/Dark/W_Key_Dark.png");
	texA.loadFromFile("../assets/textures/keyboard_and_controller/Keyboard & Mouse/Dark/A_Key_Dark.png");
	texS.loadFromFile("../assets/textures/keyboard_and_controller/Keyboard & Mouse/Dark/S_Key_Dark.png");
	texD.loadFromFile("../assets/textures/keyboard_and_controller/Keyboard & Mouse/Dark/D_Key_Dark.png");
	
	sf::Sprite sprW, sprA, sprS, sprD;
	sprW.setTexture(texW);
	sprA.setTexture(texA);
	sprS.setTexture(texS);
	sprD.setTexture(texD);
	sprW.setPosition(texA.getSize().x, 0);
	sprA.setPosition(0, texA.getSize().y);
	sprS.setPosition(texA.getSize().x, texA.getSize().y);
	sprD.setPosition(2 * texA.getSize().x, texA.getSize().y);
	
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
	
	/*Board board(15, 15);
	Player player(3, 6);
	
	char cmd;
	while(true){
		board.draw();
		std::cin >> cmd;
		if(cmd == 'w'){
			player.move(board, 0, 1);
		}
		else if(cmd == 'a'){
			player.move(board, -1, 0);
		}
		else if(cmd == 's'){
			player.move(board, 0, -1);
		}
		else if(cmd == 'd'){
			player.move(board, 1, 0);
		}
		else if(cmd == 'e'){
			break;
		}
	}*/
}