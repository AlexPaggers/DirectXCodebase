#pragma once

#ifndef _SYSTEMCLASS_H_
#define _SYSTEMCLASS_H_

#include <Windows.h>
#include "inputclass.h"
#include "graphicsclass.h"
#include <memory>
#include "game.h"
<<<<<<< HEAD
#include "Scene.h"
=======
>>>>>>> c5cdf751d494af544a85e377889bf5034825443c

#define WIN32_LEAN_AND_MEAN

class SystemClass
{
public:
	SystemClass();
	SystemClass(const SystemClass&);
	~SystemClass();

	bool Initialize();
	void Shutdown();
	void Run();

	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

private:
	bool Frame();
	void InitializeWindows(int&, int&);
	void ShutdownWindows();

private:
	LPCWSTR m_applicationName;
	HINSTANCE m_hinstance;
	HWND m_hwnd;

	//InputClass* m_Input;
	std::unique_ptr<InputClass> m_Input;

	//GraphicsClass* m_Graphics;
	std::unique_ptr<GraphicsClass> m_Graphics;

<<<<<<< HEAD
	std::unique_ptr<Scene> m_Scene;
=======
	std::unique_ptr<Game> m_game;
>>>>>>> c5cdf751d494af544a85e377889bf5034825443c
};

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


static SystemClass* ApplicationHandle = 0;


#endif