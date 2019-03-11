#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <d3d11.h>

#include <wrl.h>
using Microsoft::WRL::ComPtr;

class VertexShader
{
public:
	bool init(ComPtr<ID3D11Device> device, std::string path);
	void destroy();

	void bind(ComPtr<ID3D11DeviceContext> deviceContext);

	const ComPtr<ID3D11VertexShader> & getHandle();
	const std::string & getByteCode();
private:
	ComPtr<ID3D11VertexShader> m_vertexShader;
	std::string m_byteCode;
};