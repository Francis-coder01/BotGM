#ifndef BOTGM_FENSUPPORTER_H
#define BOTGM_FENSUPPORTER_H

#include "board.h"

void parseFEN(const std::string& fen, BoardRepresentation& board);

std::string boardToFEN(const BoardRepresentation& board);


#endif //BOTGM_FENSUPPORTER_H
