#pragma once

#include <iostream>
#include <d3d11.h>

#include <wrl.h>
using Microsoft::WRL::ComPtr;

class Swapchain
{
public:
	bool init(ComPtr<ID3D11Device> device, HWND windowHandle, int width, int height, int numMSAALevels);
	void destroy();

	bool swapBuffers(bool vsync);

	const ComPtr<IDXGISwapChain> & getSwapChain();
	int MSAALevels;
	int MSAAQualityLevels;
private:
	ComPtr<IDXGISwapChain> m_swapChain;
};