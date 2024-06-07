#include <sstream>
#include "board.cpp"

void parseFEN(const std::string& fen, BoardRepresentation& board){
    std::istringstream iss(fen);
    for(int i = 0; i < 8; i++){
        std::string rank;
        if( i < 7 ) getline(iss, rank, '/');
        else getline(iss, rank, ' ');
        for(int j = 0; j < 8; j++){
            if(isdigit(rank[j])){
                j += rank[j] - '0';
                continue;
            }
            switch (rank[j]) {
                case 'p':
                    board.pieces[PAWN].set(BLACK + i);
                    board.squares[(i+1)*(j+1) -1] = PAWN | BLACK;
                    break;
                case 'r':
                    board.pieces[ROOK].set(BLACK + i);
                    board.squares[(i+1)*(j+1) -1] = ROOK | BLACK;
                    break;
                case 'n':
                    board.pieces[KNIGHT].set(BLACK + i);
                    board.squares[(i+1)*(j+1) -1] = KNIGHT | BLACK;
                    break;
                case 'b':
                    board.pieces[BISHOP].set(BLACK + i);
                    board.squares[(i+1)*(j+1) -1] = BISHOP | BLACK;
                    break;
                case 'q':
                    board.pieces[QUEEN].set(BLACK + i);
                    board.squares[(i+1)*(j+1) -1] = QUEEN | BLACK;
                    break;
                case 'k':
                    board.pieces[KING].set(BLACK + i);
                    board.squares[(i+1)*(j+1) -1] = KING | BLACK;
                    break;
                case 'P':
                    board.pieces[PAWN].set(WHITE + i);
                    board.squares[(i+1)*(j+1) -1] = PAWN | WHITE;
                    break;
                case 'R':
                    board.pieces[ROOK].set(WHITE + i);
                    board.squares[(i+1)*(j+1) -1] = ROOK | WHITE;
                    break;
                case 'N':
                    board.pieces[KNIGHT].set(WHITE + i);
                    board.squares[(i+1)*(j+1) -1] = KNIGHT | WHITE;
                    break;
                case 'B':
                    board.pieces[BISHOP].set(WHITE + i);
                    board.squares[(i+1)*(j+1) -1] = BISHOP | WHITE;
                    break;
                case 'Q':
                    board.pieces[QUEEN].set(WHITE + i);
                    board.squares[(i+1)*(j+1) -1] = QUEEN | WHITE;
                    break;
                case 'K':
                    board.pieces[KING].set(WHITE + i);
                    board.squares[(i+1)*(j+1) -1] = KING | WHITE;
                    break;
            }
        }
    }
    std::string activeColor; getline(iss, activeColor, ' ');
    board.whiteToMove = activeColor.contains("w");
    std::string castlingRights; getline(iss, castlingRights, ' ');
    board.whiteHasKSideCastlingRights = castlingRights.contains("K");
    board.whiteHasKSideCastlingRights = castlingRights.contains("K");
    board.blackHasKSideCastlingRights = castlingRights.contains("k");
    board.blackHasQSideCastlingRights = castlingRights.contains("q");
    std::string enPassant; getline(iss, enPassant, ' ');
    if(!enPassant.contains("-")){
        board.hasEnPassant = true;
        board.enPassantSquare = (enPassant[0] - 'a') * 8 + (enPassant[1] - '0');
    } else board.hasEnPassant = false;
    iss >> board.halfMoveClock >> board.fullMoveClock;
}

std::string boardToFEN(const BoardRepresentation& board){
    std::string fen;
    for(int i = 0; i < 8; i++) {

    }
}