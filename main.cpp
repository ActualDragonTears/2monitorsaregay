#include <Windows.h>

HWND valve;
RECT window;

int main()
{
	// Hide console ( durr )
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	// L-Shift + F6 panic button

	while (!(GetAsyncKeyState(VK_LMENU) && GetAsyncKeyState(VK_F6)))
	{

		// Find the window for all valve games

		valve = FindWindowA("Valve001", NULL);

		// If active window is a valve game

		if (GetForegroundWindow() == valve)
		{
			// Convert the resolution of the game into a rect 

			if (GetWindowRect(valve, &window))
				ClipCursor(&window); // Clip the cursor to the rect
		}
		else
			ClipCursor(NULL); // Reset the clip if not in game
	}

	ClipCursor(NULL);

}