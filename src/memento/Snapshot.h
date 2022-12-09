//
// Created by User on 02.12.2022.
//

#ifndef GAME_SNAPSHOT_H
#define GAME_SNAPSHOT_H

#include <map>
#include <string>
#include <vector>
#include <utility>
#include "MementoException.h"

namespace memento {
    class Snapshot {
    public:
        explicit Snapshot(std::map<std::string, std::string> state);

        explicit Snapshot(const std::vector<std::string> &input, const std::string &equ_delim = "=");

        std::string serialize(const std::string &fields_delim = "\n", const std::string &equ_delim = "=");

        const std::map<std::string, std::string> &getState();

        ~Snapshot();
    private:
        std::map<std::string, std::string> state_{};
    };
}


#endif //GAME_SNAPSHOT_H
