//
// Created by User on 08.12.2022.
//

#include "MementoException.h"

namespace memento {

    MementoException::MementoException(MementoException::Reason reason, MementoException::Action action) noexcept :
        reason_(reason), action_(action) {}

    const char *MementoException::what() const noexcept {
        std::map<Action, std::string> actions = {
                {Action::LOADING, "loading"},
                {Action::SAVING, "saving"},
        };
        std::map<Reason, std::string> reasons = {
                {Reason::FILE_NOT_FOUND, "file not found"},
                {Reason::FILE_IS_CLOSED, "file is closed"},
                {Reason::INCORRECT_DATA, "incorrect data"},
                {Reason::NO_VALID_SAVES, "no valid saves"},
        };

        std::string action_start = "Memento error occurred while ";
        std::string reason_start = " with reason of ";
        char *res = new char[action_start.size() + reason_start.size() + reasons[reason_].size() + actions[action_].size() + 1];

        strcpy(res, action_start.c_str());
        strcat(res, actions[action_].c_str());
        strcat(res, reason_start.c_str());
        strcat(res, reasons[reason_].c_str());
        return res;
    }
}