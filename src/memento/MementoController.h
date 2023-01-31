//
// Created by User on 02.12.2022.
//

#ifndef GAME_MEMENTOCONTROLLER_H
#define GAME_MEMENTOCONTROLLER_H


namespace memento {
    class MementoController;
}

#include "src/GameMediator.h"
#include "SnapshotsCollector.h"
#include "KernelSerializer.h"
#include "MementoException.h"
#include "../kernel/field/Field.h"

namespace memento {
    /// Отвечает за сохранение игры. Сделан, ориентируясь на паттерн "Снимок"
    class MementoController {
    public:
        explicit MementoController(GameMediator *game_mediator, const std::string& saves_dir = "saves/");

        void save();

        void load(const std::string& save_name = "");

        ~MementoController();
    protected:
        GameMediator *game_mediator_;
        KernelSerializer *kernel_serializer_;
        SnapshotsCollector *snapshots_collector_;
    };
}


#endif //GAME_MEMENTOCONTROLLER_H
