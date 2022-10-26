//
// Created by ilyab on 11.10.2022.
//

#ifndef GAME_GAMECONTROLLER_H
#define GAME_GAMECONTROLLER_H

#include "GameMediator.h"

class GameController {
public:
    GameController();

    void start();

    ~GameController();
protected:
    view::ViewController *view_controller_;
    kernel::KernelController *kernel_controller_;
    GameMediator *game_mediator_;
    mapmaker::MapMaker *map_maker_;
    events::EventsController *events_controller_;
    logger::LoggerController *logger_controller_;
};


#endif //GAME_GAMECONTROLLER_H
