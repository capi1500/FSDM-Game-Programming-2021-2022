#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "board.hpp"
#include "player.hpp"
#include "point.hpp"

int main(){
	srand(time(NULL));
	
	sf::RenderWindow window(sf::VideoMode(800, 500), "board game");
	sf::View view = window.getDefaultView();
	
	Point::init();
	
	Board board(15, 20);
	Player player(board, 3, 3);
	Point point(board, player);
	
	while(window.isOpen()){
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
		player.update();
		if(player.isOnTail(player.getPos()))
			window.close();
		
		view.setCenter(player.getCenter());
		window.setView(view);
		
		window.clear();
		window.draw(board);
		window.draw(player);
		window.draw(point);
		window.display();
	}
	
	Point::clear();
}