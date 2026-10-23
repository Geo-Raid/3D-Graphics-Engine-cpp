#include "Window.h"

static HWND hwnd = nullptr;

// Handle Windows messages
static LRESULT CALLBACK WindowProc(
    HWND hwnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam
)
{
    switch (uMsg)
    {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

// Initialise the window
bool InitWindow(HINSTANCE hInstance, int nCmdShow)
{
    const char CLASS_NAME[] = "MyWindowClass";

    WNDCLASSA wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    if (!RegisterClassA(&wc))
        return false;

    hwnd = CreateWindowExA(
        0,
        CLASS_NAME,
        "My Win32 Window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        800, 600,
        nullptr,
        nullptr,
        hInstance,
        nullptr
    );

    if (!hwnd)
        return false;

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    return true;
}

// Process pending messages
bool ProcessMessages()
{
    MSG msg = {};

    while (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE))
    {
        if (msg.message == WM_QUIT)
            return false;

        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }

    return true;
}

// Return the window handle
HWND GetWindowHandle()
{
    return hwnd;
}

// Close the window
void CloseWindow()
{
    if (hwnd)
        DestroyWindow(hwnd);
}
