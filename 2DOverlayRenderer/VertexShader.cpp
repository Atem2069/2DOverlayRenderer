#include "VertexShader.h"

bool VertexShader::init(ComPtr<ID3D11Device> device, std::string fileName)
{
	std::ifstream file(fileName);
	std::stringstream buf;
	buf << file.rdbuf();
	m_byteCode = buf.str();
	
	HRESULT result;
	result = device->CreateVertexShader(m_byteCode.c_str(), m_byteCode.length(), nullptr, m_vertexShader.ReleaseAndGetAddressOf());
	if (FAILED(result))
	{
		std::cout << "Failed to create vertex shader" << std::endl;
		return false;
	}

	return true;
}

void VertexShader::destroy()
{
	m_vertexShader.Reset();
}

void VertexShader::bind(ComPtr<ID3D11DeviceContext> deviceContext)
{
	deviceContext->VSSetShader(m_vertexShader.Get(), nullptr, 0);
}

const ComPtr<ID3D11VertexShader> & VertexShader::getHandle()
{
	return m_vertexShader;
}

const std::string & VertexShader::getByteCode()
{
	return m_byteCode;
}