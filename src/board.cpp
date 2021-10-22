#include <iostream>
#include "board.hpp"

void Board::draw(){
	for(int y = 0; y < sizeY; y++){
		for(int x = 0; x < sizeX; x++){
			std::cout << fields[x][y] << " ";
		}
		std::cout << "\n";
	}
}

Board::Board(int sizeX, int sizeY) : sizeX(sizeX), sizeY(sizeY){
	fields.resize(sizeX, std::vector<char>(sizeY, '.'));
}

void Board::setField(int x, int y, char c){
	fields[x][y] = c;
}

bool Board::isCoordinateOk(int x, int y){

}
