#include "command.h"
#include "../fenSupporter.h"
#include <unordered_map>
#include <sstream>
#include <vector>

static const std::unordered_map<std::string, UCICommandType> command_map = {
        {"position", UCICommandType::Position},
        {"go", UCICommandType::Go},
        {"stop", UCICommandType::Stop},
        {"debug", UCICommandType::Debug},
        {"isready", UCICommandType::IsReady},
        {"ucinewgame", UCICommandType::NewGame},
        {"move", UCICommandType::DoMove},
        {"m", UCICommandType::DoMove},
        {"display", UCICommandType::Display},
        {"d", UCICommandType::Display},
        {"list", UCICommandType::ListMoves},
        {"l", UCICommandType::ListMoves},
        {"clear", UCICommandType::Clear},
        {"c", UCICommandType::Clear},
        {"quit", UCICommandType::Quit},
        {"q", UCICommandType::Quit},
};

UCICommandType parseCommandType(const std::string& token) {
    auto it = command_map.find(token);
    if (it != command_map.end()) {
        return it->second;
    } else {
        return UCICommandType::Invalid;
    }
}

PositionCommand parsePositionCommand(const std::string& str){
    std::string fen;
    std::vector<std::string> moves;
    if (str.contains("startpos")) {
        fen = startingPosFEN;
    }
    else {

    }

    return {.position = fen, .move_history = moves};
}

Command parseCommand(const std::string& cmd){
    std::istringstream iss(cmd);
    std::string token;
    while(iss >> std::ws >> token) {
        UCICommandType commandType = parseCommandType(token);
        switch (commandType) {
            case UCICommandType::Position:
                return parsePositionCommand(iss.str());
            case UCICommandType::Debug:
                break;
            case UCICommandType::Go:
                break;
            case UCICommandType::IsReady:
                break;
            case UCICommandType::Stop:
                break;
            case UCICommandType::DoMove:
                break;
            case UCICommandType::NewGame:
                break;
            case UCICommandType::Display:
                break;
            case UCICommandType::ListMoves:
                break;
            case UCICommandType::Clear:
                break;
            case UCICommandType::Quit:
                break;
            case UCICommandType::Invalid:
                break;
        }
    }
}
