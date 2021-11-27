#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main(){
	sf::RenderWindow window(sf::VideoMode(800, 500), "board game");
	
	sf::RectangleShape square;
	square.setSize(sf::Vector2f(50, 50));
	square.setFillColor(sf::Color::Green);
	square.setPosition(50, 50);
	square.setOrigin(25, 25);
	
	window.setFramerateLimit(60);
	
	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window.close();
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			square.rotate(0.5);
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			square.rotate(-0.5);
		
		window.clear();
		window.draw(square);
		window.display();
	}
}