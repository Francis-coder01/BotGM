#ifndef BOTGM_COMMAND_H
#define BOTGM_COMMAND_H

#include <string>
#include <optional>
#include <variant>
#include <vector>

enum class UCICommandType {
    Debug,
    Go,
    IsReady,
    Position,
    Stop,
    DoMove,
    NewGame,
    Display,
    ListMoves,
    Clear,
    Quit,
    Invalid
};

struct PositionCommand {
    std::string position;
    std::vector<std::string> move_history;
};

struct GoCommand {
    std::optional<int> depth;
    std::optional<int> move_time;
    std::optional<int> white_time;
    std::optional<int> black_time;
    std::optional<int> white_increment;
    std::optional<int> black_increment;
    bool ponder = false;
};

struct DebugCommand {
    std::string debug;
};

struct DoMoveCommand {
    std::string move;
};

using Command = std::variant<
        PositionCommand,
        GoCommand,
        UCICommandType, // For simple commands like Stop, PonderHit, etc.
        DebugCommand,
        DoMoveCommand
>;

UCICommandType parseCommandType(const std::string& cmd);
Command parseCommand(const std::string& cmd);

#endif //BOTGM_COMMAND_H
