#include "GameController.h"

int main() {
    try {
        GameController game;
        game.start();
    } catch (...) {
        main();
    }
    return 0;
}
