#include "Geometry/TexQuad.h"

using namespace d3d;

bool TexQuad::Setup(IDirect3DDevice9* Device)
{
	m_Device = Device;

	Device->CreateVertexBuffer(
		6 * sizeof(TextureVertex),
		D3DUSAGE_WRITEONLY,
		TextureVertex::FVF,
		D3DPOOL_MANAGED,
		&m_VB,
		0);

	//
	// Fill the vertex buffer with pyramid data.
	//

	TextureVertex* v;
	m_VB->Lock(0, 0, (void**)&v, 0);

	// quad built from two triangles, note texture coordinates:
	v[0] = TextureVertex(-4.0f, -4.0f, 1.25f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f);
	v[1] = TextureVertex(-4.0f, 4.0f, 1.25f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f);
	v[2] = TextureVertex(4.0f, 4.0f, 1.25f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f);

	v[3] = TextureVertex(-4.0f, -4.0f, 1.25f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f);
	v[4] = TextureVertex(4.0f, 4.0f, 1.25f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f);
	v[5] = TextureVertex(4.0f, -4.0f, 1.25f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f);

	m_VB->Unlock();


	D3DXCreateTextureFromFile(
		Device,
		"resources\\dx5_logo.bmp",
		&m_Texture);

	m_D3DMaterial.Ambient = d3d::WHITE;
	m_D3DMaterial.Diffuse = d3d::WHITE;
	m_D3DMaterial.Specular = d3d::WHITE;
	m_D3DMaterial.Emissive = d3d::BLACK;
	m_D3DMaterial.Power = 5.0f;

	Device->SetStreamSource(0, m_VB, 0, sizeof(TextureVertex));
	Device->SetFVF(TextureVertex::FVF);

	return true;
}
void TexQuad::Cleanup()
{
	d3d::Release<IDirect3DVertexBuffer9*>(m_VB);
	d3d::Release<IDirect3DTexture9*>(m_Texture);
}



void TexQuad::Upate(float timeDelta)
{

	static float y = 0.0f;
	D3DXMatrixRotationY(&Ry, y);

	y += timeDelta;
	if (y >= 6.28f)
		y = 0.0f;

}
void TexQuad::Render()
{
	// Draw teapot using DrawSubset method with 0 as the argument.
	m_Device->SetTexture(0, m_Texture);
	m_Device->SetMaterial(&m_D3DMaterial);
	m_Device->SetTransform(D3DTS_WORLD, &(m_D3DXMATRIX));
	m_Device->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 4);
}