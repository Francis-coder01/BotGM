#include <iostream>
#include <limits>
#include <sstream>
#include "fenSupporter.h"
#include "UCI/command.h"

typedef struct engine {
    BoardRepresentation board;
} Engine;

void UCI();

int main() {
    Engine engine;
    parseFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", engine.board);
    UCI();
    return 0;
}


void UCI() {
    std::string command;
    for(int i = 0; i < 5; i++) {
        std::getline(std::cin, command);
        auto c = parseCommand(command);
    }
}
