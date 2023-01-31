//
// Created by ilyab on 14.11.2022.
//

#ifndef GAME_ICOMMAND_H
#define GAME_ICOMMAND_H

namespace view {
    /// Интерфейс команд, сделанный по паттерну команда
    class ICommand {
    public:
        virtual void execute() = 0;

        virtual ~ICommand() = default;
    };
}

#endif //GAME_ICOMMAND_H
