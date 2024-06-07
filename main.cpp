#include <iostream>
#include <bitset>
#include <sstream>
#include <cstdint>
#include "board.cpp"
#include "fenSupporter.cpp"

typedef struct engine {
    BoardRepresentation board;
} Engine;






void testFEN(){
    Engine engine;
    parseFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", engine.board);
    if(!engine.board.blackHasQSideCastlingRights){
        printf("")
    }
}


int main() {
    testFEN();


    return 0;
}