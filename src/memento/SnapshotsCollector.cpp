//
// Created by User on 02.12.2022.
//

#include "SnapshotsCollector.h"
namespace memento {


    SnapshotsCollector::~SnapshotsCollector() {
        for (auto& it : snapshots_) {
            delete it.second;
        }
        snapshots_.clear();
    }

    SnapshotsCollector::SnapshotsCollector(const std::string &saves_dir) {
        saves_path_ = saves_dir;
        for (const auto &p : std::filesystem::recursive_directory_iterator(saves_path_)) {
            filenames_.push_back(p.path().filename().string());
        }

        std::sort(filenames_.begin(), filenames_.end(), [](const std::string& f1, const std::string& f2) {
            return std::stoi(f1.substr(0, f1.find('.'))) > std::stoi(f2.substr(0, f2.find('.')));
        });
    }

    void SnapshotsCollector::loadSnapshotsFromFilename(const std::string& filename) {
        if ( std::find(filenames_.begin(), filenames_.end(), filename) == filenames_.end() ) {
            throw MementoException(MementoException::Reason::FILE_NOT_FOUND, MementoException::Action::LOADING);
        }
        std::fstream file;
        file.open(saves_path_.string() + filename);
        try {
            loadSnapshotsFromFile(file);
            file.close();
        } catch (std::exception &err) {
            file.close();
            throw err;
        }
    }

    void SnapshotsCollector::loadSnapshotsFromFile(std::fstream &file) {
        if (!file.is_open()) {
            throw MementoException(MementoException::Reason::FILE_IS_CLOSED, MementoException::Action::LOADING);
        }
        std::string line, type;
        std::vector<std::string> type_input {};
        while (file) {
            file >> line;
            if (line[0] == '#') {
                if (type.length()) {
                    snapshots_[type.substr(1, type.size())] = new Snapshot{type_input};
                }
                type = line;
                type_input.clear();
            } else {
                if (!type.length()) {
                    throw MementoException(MementoException::Reason::INCORRECT_DATA, MementoException::Action::LOADING);
                }
                type_input.push_back(line);
            }
        }
        if (!type_input.empty()) {
            snapshots_[type.substr(1, type.size())] = new Snapshot{type_input};
            type_input.clear();
        }
    }

    void SnapshotsCollector::loadLastSnapshotsFile() {
        for (const auto &filename : filenames_) {
            try {
                loadSnapshotsFromFilename(filename);
                return;
            } catch (...) {}
        }
        throw MementoException(MementoException::Reason::NO_VALID_SAVES, MementoException::Action::LOADING);
    }

    void SnapshotsCollector::save() {
        std::ofstream file;
        std::time_t time = std::time(nullptr);
        std::localtime(&time);
        std::stringstream time_str;
        time_str << time;
        std::string filename = time_str.str() + ".env";
        file.open(saves_path_.string() + filename);
        for (auto &snapshot : snapshots_) {
            file << '#' << snapshot.first << '\n';
            file << snapshot.second->serialize();
        }
        filenames_.insert(filenames_.begin(), filename);
        file.close();
    }

    void SnapshotsCollector::setSnapshot(const std::string &type, Snapshot *snapshot) {
        snapshots_[type] = snapshot;
    }

    std::map<std::string, Snapshot *> SnapshotsCollector::getSnapshots() {
        return snapshots_;
    }

    void SnapshotsCollector::loadSnapshotsByIndex(int idx) {
        if (idx >= filenames_.size()) {
            idx = (int)filenames_.size() - 1;
        }
        loadSnapshotsFromFilename(filenames_[idx]);
    }

}
