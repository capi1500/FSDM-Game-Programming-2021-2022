#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "board.hpp"
#include "player.hpp"
#include "point.hpp"

int main(){
	srand(time(NULL));
	
	sf::RenderWindow window(sf::VideoMode(800, 500), "board game");
	sf::View view = window.getDefaultView();
	sf::Clock clock;
	sf::Time frame;
	
	Point::init();
	
	Board board(15, 20);
	Player player(board, 3, 3);
	Point point(board, player);
	bool lost = false;
	
	while(!lost && window.isOpen()){
		frame = clock.restart();
		
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window.close();
			if(event.type == sf::Event::Resized)
				view.setSize(event.size.width, event.size.height);
			player.handleEvent(event);
		}
		
		if(player.getPos() == point.getPos()){
			player.pointGet();
			point.randomPlace(player);
		}
		
		if(!player.update(frame)){
			lost = true;
		}
		
		view.setCenter(player.getCenter());
		window.setView(view);
		
		window.clear();
		window.draw(board);
		window.draw(player);
		window.draw(point);
		window.display();
	}
	
	Point::clear();
	
	sf::Font font;
	font.loadFromFile("../assets/fonts/Pixeled.ttf");
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::White);
	text.setString("Game Over!");
	text.setPosition((window.getSize().x - text.getLocalBounds().width) / 2,
					 (window.getSize().y - text.getLocalBounds().height) / 2);
	
	window.setView(window.getDefaultView());
	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear();
		window.draw(text);
		window.display();
	}
}

/*
 * Wyścigi    3
 * Uproszcozna platformówka   11
 * Saper         8
 * Pasjans       6
 * Rewolwerowiec  8
 *
 */