#ifndef BOTGM_BOARD_H
#define BOTGM_BOARD_H

#include <bitset>
#include <cstdint>

enum pieces {
    NONE,
    PAWN,
    BISHOP,
    KNIGHT,
    ROOK,
    QUEEN,
    KING
};

enum COLOR {
    WHITE = 8,
    BLACK = 16
};

typedef struct BoardRepresentation {
    uint8_t squares[64] { 0 };
    std::bitset<64> pieces[12];
    bool whiteToMove = true;
    bool whiteHasKSideCastlingRights = true;
    bool whiteHasQSideCastlingRights = true;
    bool blackHasKSideCastlingRights = true;
    bool blackHasQSideCastlingRights = true;
    uint8_t enPassantSquare = 0;
    bool hasEnPassant = false;
    uint32_t halfMoveClock = 0, fullMoveClock = 1;
} BoardRepresentation;

void printBoard(BoardRepresentation board);

#endif //BOTGM_BOARD_H
