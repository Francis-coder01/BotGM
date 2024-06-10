#ifndef BOTGM_FENSUPPORTER_H
#define BOTGM_FENSUPPORTER_H

#include "board.h"

const std::string startingPosFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

void parseFEN(const std::string& fen, BoardRepresentation& board);

std::string boardToFEN(const BoardRepresentation& board);


#endif //BOTGM_FENSUPPORTER_H
