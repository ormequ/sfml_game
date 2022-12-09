//
// Created by User on 02.12.2022.
//

#include "MementoController.h"

namespace memento {

    MementoController::MementoController(GameMediator *game_mediator, const std::string& saves_dir) :
            game_mediator_(game_mediator) {
        kernel_serializer_ = new KernelSerializer(game_mediator);
        snapshots_collector_ = new SnapshotsCollector(saves_dir);
    }

    void MementoController::save() {
        auto serialized = kernel_serializer_->serialize();
        for (const auto &pair: serialized) {
            snapshots_collector_->setSnapshot(pair.first, new Snapshot{pair.second});
        }
        snapshots_collector_->save();
    }

    MementoController::~MementoController() {
        delete kernel_serializer_;
        delete snapshots_collector_;
    }

    void MementoController::load(const std::string& save_name) {
        if (save_name.empty() || save_name == "last") {
            snapshots_collector_->loadLastSnapshotsFile();
        } else {
            try {
                snapshots_collector_->loadSnapshotsByIndex(std::stoi(save_name));
//                snapshots_collector_->loadSnapshotsFromFilename(save_name + ".env");
            } catch (...) {
                snapshots_collector_->loadLastSnapshotsFile();
            }
        }
        std::map<std::string, std::map<std::string, std::string>> snapshot_data {};
        for (const auto &pair : snapshots_collector_->getSnapshots()) {
            snapshot_data[pair.first] = pair.second->getState();
        }
        kernel::IField *prev_field = new kernel::Field;
        prev_field->change(*game_mediator_->getField());
        try {
            kernel_serializer_->deserialize(snapshot_data);
        } catch (...) {
            game_mediator_->setField(prev_field);
        }
    }
}