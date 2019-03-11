#pragma once

#include <iostream>
#include <d3d11.h>

#include <wrl.h>
using Microsoft::WRL::ComPtr;

class Renderer
{
public:
	bool init();
	void destroy();


	const ComPtr<ID3D11Device> & getDevice();
	const ComPtr<ID3D11DeviceContext> & getDeviceContext();
	///TODO
	///void bindAndClearRenderTargets(RenderView renderView, DepthView depthView);
	///void drawSceneGraph(SceneGraph sceneGraph);
private:
	ComPtr<ID3D11Device> m_device;
	ComPtr<ID3D11DeviceContext> m_deviceContext;
};