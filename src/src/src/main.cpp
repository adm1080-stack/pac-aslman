#include "Game.h"

int main() {
    Game game;
    if (game.Init(1280, 720, "Native 3D Pac-Man")) {
        game.Run();
    }
    return 0;
}
