#include <iostream>
#include "board.hpp"
#include "player.hpp"

int main(){
	Board board(15, 15);
	Player player(3, 6);
	
	/*
    Player player;
    Player player2 = Player();
	Player player3{};
	Player player4(1, 2);
	Player player5 = Player(1, 2);
	Player player6{1, 2};
    */
	
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
	}
}