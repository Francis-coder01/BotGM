#include <sstream>
#include <iostream>
#include "board.h"

void printBoard(BoardRepresentation board){
    std::ostringstream oss;
    
    for(int i = 0; i < 8; i++){
        oss << "\n";
        for(int j = 0; j < 8; j++){
            oss << "" << std::endl;
        }
    }
    std::cout << oss.str();
}