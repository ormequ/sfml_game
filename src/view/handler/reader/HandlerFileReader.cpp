//
// Created by ilyab on 14.11.2022.
//

#include "HandlerFileReader.h"

namespace view {

    HandlerFileReader::HandlerFileReader() {
        file_.open("../src/config.txt");
    }

    HandlerFileReader::~HandlerFileReader() {
        file_.close();
    }

    std::map<std::string, std::string> HandlerFileReader::read() {
        std::map<std::string, std::string> commands;
        while (!file_.eof()) {
            std::string cmd_key, cmd_val;
            file_ >> cmd_key >> cmd_val;
            std::transform(
                    cmd_key.begin(), cmd_key.end(), cmd_key.begin(),
                    [](unsigned char c) { return std::tolower(c); }
            );
            commands[cmd_key] = cmd_val;
        }
        return commands;
    }
}