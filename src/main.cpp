#include <windows.h>
#include "Window.h"

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
)
{
    // Create the window
    if (!InitWindow(hInstance, nCmdShow))
        return 1;

    // Main program loop
    bool running = true;

    while (running)
    {
        running = ProcessMessages();

        if (!running)
            break;

        // Your game logic goes here
        // Update();
        // Render();
    }

    return 0;
}
