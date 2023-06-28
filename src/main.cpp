#include "game.h"

int main(int argc, char* argv[])
{
    if (initSDL())
    {
        Game game;

        game.run();

        freeSDL();
    }

    return 0;
}
