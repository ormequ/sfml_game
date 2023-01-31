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
    /// Класс снимка -- обертка над std::map для состояний, нужен для сериализации
    class Snapshot {
    public:
        explicit Snapshot(std::map<std::string, std::string> state);

        /**
         * Конструктор, считывающий состояние из строки (десериализация)
         * @param input строка для считывания
         * @param equ_delim разделитель равенства
         * */
        explicit Snapshot(const std::vector<std::string> &input, const std::string &equ_delim = "=");

        /**
         * Преобразовывает состояние в строку. По умолчанию формат env
         * @param fields_delim разделитель полей
         * @param equ_delim разделитель равенства
         *
         * @return сериализованное состояние
         * */
        std::string serialize(const std::string &fields_delim = "\n", const std::string &equ_delim = "=");

        const std::map<std::string, std::string> &getState();

        ~Snapshot();
    private:
        std::map<std::string, std::string> state_{};
    };
}


#endif //GAME_SNAPSHOT_H
