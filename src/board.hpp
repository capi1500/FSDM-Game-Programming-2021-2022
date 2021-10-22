#pragma once

#include <vector>

class Board{
	private:
		int sizeX;
		int sizeY;
		std::vector<std::vector<char>> fields;
	public:
		void draw();
		void setField(int x, int y, char c);
		bool isCoordinateOk(int x, int y);
		
		Board(int sizeX, int sizeY);
};
