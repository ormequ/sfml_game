//
// Created by ilyab on 12.10.2022.
//

#ifndef GAME_EMPTYEVENT_H
#define GAME_EMPTYEVENT_H

namespace events {
    class EmptyEvent;
}

#include "EventChainLink.h"

namespace events {
    /// Пустое событие, для проверки условий перехода к первому событию
    class EmptyEvent final : public EventChainLink {
    public:
        void dispatch(Point point) final;

        std::pair<FactoryName, std::string> serialize() override;
    };

}


#endif //GAME_EMPTYEVENT_H
