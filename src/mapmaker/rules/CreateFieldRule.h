//
// Created by ilyab on 27.11.2022.
//

#ifndef GAME_CREATEFIELDRULE_H
#define GAME_CREATEFIELDRULE_H

#include "../../GameMediator.h"

namespace mapmaker {
    /// Правило создания пустого поля
    template<unsigned int width, unsigned int height>
    class CreateFieldRule {
    public:
        explicit CreateFieldRule(GameMediator *game_mediator) : game_mediator_(game_mediator) {};

        void operator()() {
            game_mediator_->setField(
                new kernel::Field(width, height)
            );
        }
    private:
        GameMediator *game_mediator_;
    };
}

#endif //GAME_CREATEFIELDRULE_H
