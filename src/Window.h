#pragma once

#include <windows.h>

// Initialise the window
bool InitWindow(HINSTANCE hInstance, int nCmdShow);

// Process Windows messages
bool ProcessMessages();

// Get the window handle
HWND GetWindowHandle();

// Close the window
void CloseWindow();
