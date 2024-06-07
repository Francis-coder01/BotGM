#include <iostream>
#include <bitset>
#include <cstring>
#include "fenSupporter.h"
typedef struct engine {
    BoardRepresentation board;
} Engine;






void testFEN(){
    Engine engine;
    parseFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", engine.board);


    std::cout << boardToFEN(engine.board);
}


int main() {
    testFEN();


    return 0;
}