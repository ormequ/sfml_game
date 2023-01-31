//
// Created by ilyab on 27.11.2022.
//

#ifndef GAME_MAPGENERATOR_H
#define GAME_MAPGENERATOR_H

namespace mapmaker {
    class MapGenerator;
}

#include "../GameMediator.h"

namespace mapmaker {
    /// Variadic template генератор из правил
    class MapGenerator {
    public:
        explicit MapGenerator(GameMediator *game_mediator) : game_mediator_(game_mediator) {};

        template<typename MainRule, typename ... AdditionalRules>
        void generate() {
            MainRule{game_mediator_}();
            if constexpr (sizeof...(AdditionalRules) > 0) {
                // Правила реализоавны в виде функторов
                generate<AdditionalRules...>();
            }
        }

    private:
        GameMediator *game_mediator_;
    };
}

#endif //GAME_MAPGENERATOR_H
