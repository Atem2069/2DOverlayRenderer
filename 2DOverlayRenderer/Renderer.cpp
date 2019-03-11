#include "Renderer.h"

bool Renderer::init()
{
	HRESULT result;
	
	D3D_FEATURE_LEVEL featureLevels = { D3D_FEATURE_LEVEL_11_0 };

	result = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, &featureLevels, 1, D3D11_SDK_VERSION, m_device.ReleaseAndGetAddressOf(), nullptr, m_deviceContext.ReleaseAndGetAddressOf());
	if (FAILED(result))
	{
		std::cout << "Failed to Create D3D11 Device: " << result << std::endl;
		return false;
	}

	return true;
}

void Renderer::destroy()
{
	m_device.Reset();
	m_deviceContext.Reset();
}

const ComPtr<ID3D11Device> & Renderer::getDevice()
{
	return m_device;
}

const ComPtr<ID3D11DeviceContext> & Renderer::getDeviceContext()
{
	return m_deviceContext;
}