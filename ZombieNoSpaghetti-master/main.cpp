#include "Header/Engine.h"
#include <unistd.h>
using namespace sf;
using namespace std;

int main()
{
    Engine engine;
    while (engine.window.isOpen())
    {
        engine.run_engine();
    }

    return 0;
}