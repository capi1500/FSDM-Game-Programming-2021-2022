#pragma once

#include "board.hpp"

class Player{
	private:
		int posX;
		int posY;
		int points;
	public:
		void move(Board& board, int deltaX, int deltaY);
		
		Player();
		Player(int x, int y);
};
