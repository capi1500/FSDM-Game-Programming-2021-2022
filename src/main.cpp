#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "board.hpp"
#include "player.hpp"

int main(){
	sf::RenderWindow window(sf::VideoMode(800, 500), "board game");
	sf::View view = window.getDefaultView();
	
	Board board(15, 20);
	Player player(board, 3, 3);
	
	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window.close();
			if(event.type == sf::Event::Resized)
				view.setSize(event.size.width, event.size.height);
			player.handleEvent(event);
		}
		view.setCenter(player.getCenter());
		window.setView(view);
		
		window.clear();
		window.draw(board);
		window.draw(player);
		window.display();
	}
}