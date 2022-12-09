//
// Created by User on 08.12.2022.
//

#ifndef GAME_MEMENTOEXCEPTION_H
#define GAME_MEMENTOEXCEPTION_H

#include <exception>
#include <map>
#include <string>
#include <cstring>

namespace memento {
    class MementoException : public std::exception {
    public:
        enum class Reason {
            FILE_NOT_FOUND, FILE_IS_CLOSED, INCORRECT_DATA, NO_VALID_SAVES
        };
        enum class Action {
            SAVING, LOADING
        };

        MementoException(Reason reason, Action action) noexcept;

        [[nodiscard]] const char *what() const noexcept override;
    protected:
        Reason reason_;
        Action action_;
    };
}


#endif //GAME_MEMENTOEXCEPTION_H
