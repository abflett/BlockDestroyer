#include "Game.h"
#include "Engine.h"

int main(int argc, char* argv[]) {
    BlockDestroyer::Engine engine;
    BlockDestroyer::Game game(engine);
    game.start();
    return 0;
}