#include "systemclass.h"
#include <memory>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	std::unique_ptr<SystemClass> System;
	bool result;

	// Create the system object.
	System = std::make_unique<SystemClass>();

	if (!System)
	{
		return 0;
	}

	// Initialize and run the system object.
	result = System->Initialize();
	if (result)
	{
		System->Run();
	}
	else
	{
		MessageBox(0, L"Window Initialization - Failed",
			L"Error", MB_OK);
	}

	// Shutdown and release the system object.
	System->Shutdown();

	return 0;
}