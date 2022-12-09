//
// Created by User on 02.12.2022.
//

#include "Snapshot.h"

namespace memento {
    Snapshot::Snapshot(std::map<std::string, std::string> state) : state_(std::move(state)) {}

    const std::map<std::string, std::string> &Snapshot::getState() {
        return state_;
    }

    Snapshot::Snapshot(const std::vector<std::string> &input, const std::string &equ_delim) {
        for (const auto& line : input) {
            size_t equ_pos = line.find(equ_delim);
            if (equ_pos != std::string::npos && line.length() > equ_pos + 1) {
                state_[line.substr(0, equ_pos)] = line.substr(equ_pos + 1, line.length());
            }
        }

    }

    std::string Snapshot::serialize(const std::string &fields_delim, const std::string &equ_delim) {
        std::string output;
        for (const auto& it : state_) {
            output += it.first;
            output += equ_delim;
            output += it.second;
            output += fields_delim;
        }
        return output;
    }

    Snapshot::~Snapshot() {
        state_.clear();
    }

}