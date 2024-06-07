#include <bitset>
#include <cstdint>

enum pieces {
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
    uint8_t squares[64] {};
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
