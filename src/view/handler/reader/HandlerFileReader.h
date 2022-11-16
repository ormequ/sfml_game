//
// Created by ilyab on 14.11.2022.
//

#ifndef GAME_HANDLERFILEREADER_H
#define GAME_HANDLERFILEREADER_H

#include "IHandlerReader.h"
#include <fstream>
#include <sstream>
#include <algorithm>

namespace view {
    class HandlerFileReader : public IHandlerReader {
    public:
        HandlerFileReader();

        std::map<std::string, std::string> read() override;

        ~HandlerFileReader() override;

    protected:
        std::ifstream file_;
    };
}


#endif //GAME_HANDLERFILEREADER_H
