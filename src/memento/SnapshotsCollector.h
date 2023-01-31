//
// Created by User on 02.12.2022.
//

#ifndef GAME_SNAPSHOTSCOLLECTOR_H
#define GAME_SNAPSHOTSCOLLECTOR_H

#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <filesystem>
#include "Snapshot.h"
#include "MementoException.h"

namespace memento {
    /// Класс сборника снимков -- обертка над std::map снимков, нужен для работы с файлами
    class SnapshotsCollector {
    public:
        explicit SnapshotsCollector(const std::string &saves_dir);

        /**
         * Загрузка сохранения по названию файла
         * @param filename название файла без директории
         * */
        void loadSnapshotsFromFilename(const std::string &filename);

        /**
         * Загрузка сохранения по его номеру
         * Метод нужен для удобства пользователя (чтобы не вводить длинный timestamp)
         * @param idx индекс файла в директории при сортировке по убыванию имени
         */
        void loadSnapshotsByIndex(int idx);

        ///@param file открытый файл
        void loadSnapshotsFromFile(std::fstream &file);

        std::map<std::string, Snapshot *> getSnapshots();

        void setSnapshot(const std::string &type, Snapshot *snapshot);

        /// Сохраняет в файл, имя которого -- текущий timestamp для удобства загрузки последнего сохранения
        void save();

        /// Загружает последнее доступное и корректное сохранение
        void loadLastSnapshotsFile();

        ~SnapshotsCollector();

    protected:
        std::map<std::string, Snapshot *> snapshots_{};
        std::vector<std::string> filenames_{};
        std::filesystem::path saves_path_;
    };
}


#endif //GAME_SNAPSHOTSCOLLECTOR_H
