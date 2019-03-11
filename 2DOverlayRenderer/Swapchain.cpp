#include "Swapchain.h"

bool Swapchain::init(ComPtr<ID3D11Device> device, HWND windowHandle, int width, int height, int numMSAALevels)
{
	DXGI_SWAP_CHAIN_DESC swapChainDesc = {};
	swapChainDesc.BufferCount = 2;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferDesc.Width = width;
	swapChainDesc.BufferDesc.Height = height;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.Flags = 0;
	swapChainDesc.OutputWindow = windowHandle;
	swapChainDesc.SampleDesc.Count = numMSAALevels;
	swapChainDesc.SampleDesc.Quality = 0;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_SEQUENTIAL;
	swapChainDesc.Windowed = TRUE;

	ComPtr<IDXGIDevice> dev;
	device.As(&dev);

	ComPtr<IDXGIAdapter> adapter;
	dev->GetAdapter(adapter.ReleaseAndGetAddressOf());

	ComPtr<IDXGIFactory> factory;
	adapter->GetParent(__uuidof(IDXGIFactory), (void**)factory.ReleaseAndGetAddressOf());

	HRESULT result;
	result = factory->CreateSwapChain(dev.Get(), &swapChainDesc, m_swapChain.ReleaseAndGetAddressOf());
	if (FAILED(result))
	{
		std::cout << "Swapchain creation failed: " << result << std::endl;
		return false;
	}

	MSAALevels = numMSAALevels;
	MSAAQualityLevels = 0;

	return true;
}

void Swapchain::destroy()
{
	m_swapChain.Reset();
}

bool Swapchain::swapBuffers(bool vsync)
{
	m_swapChain->Present(vsync, 0);
	return true;
}

const ComPtr<IDXGISwapChain>& Swapchain::getSwapChain()
{
	return m_swapChain;
}