﻿#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>
#include "CKeyEventHandler.h"

#define DIRECTINPUT_VERSION 0x0800
#define KEYBOARD_BUFFER_SIZE 1024
#define SCREEN_WIDTH 640.0f
#define SCREEN_HEIGHT 480.0f

class CGame
{
	static CGame* __instance;
	HWND hWnd;									// Window handle

	LPDIRECT3D9 d3d = NULL;						// Direct3D handle
	LPDIRECT3DDEVICE9 d3ddv = NULL;				// Direct3D device object

	LPDIRECT3DSURFACE9 backBuffer = NULL;
	LPD3DXSPRITE spriteHandler = NULL;			// Sprite helper library to help us draw 2D image on the screen 

	LPDIRECTINPUT8       di;		// The DirectInput object         
	LPDIRECTINPUTDEVICE8 didv;		// The keyboard device 

	D3DXMATRIX matScale;	// để xoay hình

	BYTE  keyStates[256];			// DirectInput keyboard state buffer 
	DIDEVICEOBJECTDATA keyEvents[KEYBOARD_BUFFER_SIZE];		// Buffered keyboard data

	LPKEYEVENTHANDLER keyHandler;
public:
	void InitKeyboard(LPKEYEVENTHANDLER handler);
	void Init(HWND hWnd);
	void Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom);
	void DrawFlip(float x, float y, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom, float flip_X, float flip_Y);
	
	int IsKeyDown(int key);
	void ProcessKeyboard();

	LPDIRECT3DDEVICE9 GetDirect3DDevice() {
		return this->d3ddv;
	}
	LPDIRECT3DSURFACE9 GetBackBuffer() {
		return this->backBuffer;
	}
	LPD3DXSPRITE GetSpriteHandler() {
		return this->spriteHandler;
	}

	static CGame* GetInstance();

	~CGame();
};
