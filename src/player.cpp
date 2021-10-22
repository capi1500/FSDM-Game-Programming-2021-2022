#include "player.hpp"

void Player::move(Board& board, int deltaX, int deltaY){
	if(board.isCoordinateOk(posX + deltaX, posY + deltaY)){
		board.setField(posX, posY, '.');
		posX += deltaX;
		posY += deltaY;
		board.setField(posX, posY, '#');
	}
}

Player::Player() : Player(0, 0){

}

Player::Player(int x, int y){
	posX = x;
	posY = y;
	points = 0;
}
