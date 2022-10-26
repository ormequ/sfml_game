//
// Created by ilyab on 11.10.2022.
//

#include "PlayerEvent.h"

namespace events {
    PlayerEvent::PlayerEvent(kernel::ICreature *player) : player_(player) {}
}