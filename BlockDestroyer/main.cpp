#include "Game.h"
#include "Engine.h"
#include "ResourceManager.h"

int main(int argc, char* argv[]) {
    BlockDestroyer::Engine engine;
    BlockDestroyer::ResourceManager resourceManager(engine.getRenderer());
    BlockDestroyer::Game game(engine);
    game.start();
    return 0;
}