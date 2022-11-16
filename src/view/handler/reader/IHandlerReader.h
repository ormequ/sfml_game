//
// Created by ilyab on 14.11.2022.
//

#ifndef GAME_IHANDLERREADER_H
#define GAME_IHANDLERREADER_H

#include <map>
#include <string>

namespace view {
    class IHandlerReader {
    public:
        virtual std::map<std::string, std::string> read() = 0;
        virtual ~IHandlerReader() = default;
    };
}

#endif //GAME_IHANDLERREADER_H
