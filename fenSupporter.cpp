#include <sstream>
#include <unordered_map>
#include <iostream>
#include "fenSupporter.h"

void parseFEN(const std::string& fen, BoardRepresentation& board){
    std::unordered_map<char, int> pieceMap;
    pieceMap['p'] = PAWN;
    pieceMap['r'] = ROOK;
    pieceMap['b'] = BISHOP;
    pieceMap['n'] = KNIGHT;
    pieceMap['q'] = QUEEN;
    pieceMap['k'] = KING;
    std::istringstream iss(fen);
    for(int i = 7; i >= 0; i--){
        std::string rank;
        if( i != 0 ) getline(iss, rank, '/');
        else getline(iss, rank, ' ');
        for(int j = 0; j < 8; j++){
            if(isdigit(rank[j])){
                j += rank[j] - '0';
                continue;
            }
            int color = isupper(rank[j]) ? WHITE : BLACK;
            int piece = pieceMap[char(tolower(rank[j]))];
            board.pieces[piece].set(i * 8 + j);
            board.squares[(i * 8) + j] = piece | color;
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
    }
    else board.hasEnPassant = false;
    iss >> board.halfMoveClock >> board.fullMoveClock;
}

std::string boardToFEN(const BoardRepresentation& board){
    std::ostringstream fen;
    std::unordered_map<int, char> pieceToChar;
    pieceToChar[PAWN] = 'p';
    pieceToChar[ROOK] = 'r';
    pieceToChar[BISHOP] = 'b';
    pieceToChar[KNIGHT] = 'n';
    pieceToChar[QUEEN] = 'q';
    pieceToChar[KING] = 'k';
    for(int i = 7; i >= 0; i--){
        std::string rank;
        for(int j = 0; j < 8; j++){
            uint8_t square = board.squares[(i * 8) + j];
            if (square == NONE) {
                uint8_t emptyCount = 1;
                while(++j < 8 && board.squares[(i * 8) + j] == NONE) {
                    emptyCount++;
                }
                rank += std::to_string(emptyCount);
                continue;
            }
            bool white = (square & WHITE) != 0;
            char piece = pieceToChar[square & 0b111];
            if(white) piece = char(toupper(piece));
            rank += piece;
        }
        fen << rank;
        if(i != 0) fen << "/";
    }
    fen << " ";
    fen << (board.whiteToMove ? "w" : "b");
    fen << " ";
    std::string castlingRights;
    if(board.whiteHasKSideCastlingRights) castlingRights += 'K';
    if(board.whiteHasQSideCastlingRights) castlingRights += 'Q';
    if(board.blackHasQSideCastlingRights) castlingRights += 'k';
    if(board.blackHasQSideCastlingRights) castlingRights += 'q';
    fen << (castlingRights.empty() ? "-" : castlingRights);
    fen << " ";
    if(board.hasEnPassant){
        fen << 'a' + (board.enPassantSquare / 8);
        fen << board.enPassantSquare % 8;
    }
    else fen << "-";
    fen << " ";
    fen << board.halfMoveClock << ' ' << board.fullMoveClock;
    return fen.str();
}