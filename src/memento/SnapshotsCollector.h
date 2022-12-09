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
    class SnapshotsCollector {
    public:
        explicit SnapshotsCollector(const std::string &saves_dir);

        void loadSnapshotsFromFilename(const std::string &filename);

        void loadSnapshotsByIndex(int idx);

        void loadSnapshotsFromFile(std::fstream &file);

        std::map<std::string, Snapshot *> getSnapshots();

        void setSnapshot(const std::string &type, Snapshot *snapshot);

        void save();

        void loadLastSnapshotsFile();

        ~SnapshotsCollector();

    protected:
        std::map<std::string, Snapshot *> snapshots_{};
        std::vector<std::string> filenames_{};
        std::filesystem::path saves_path_;
    };
}


#endif //GAME_SNAPSHOTSCOLLECTOR_H
