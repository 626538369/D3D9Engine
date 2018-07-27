#include "Geometry/TexCube.h"

using namespace d3d;

bool TexCube::Setup(IDirect3DDevice9* Device)
{
	m_Device = Device;

	Device->CreateVertexBuffer(
		24 * sizeof(TextureVertex),
		D3DUSAGE_WRITEONLY,
		TextureVertex::FVF,
		D3DPOOL_MANAGED,
		&m_VB,
		0);

	//
	// Fill the TextureVertex buffer with pyramid data.
	//

	TextureVertex* v;
	m_VB->Lock(0, 0, (void**)&v, 0);

	// fill in the front face vertex data
	v[0] = TextureVertex(-1.0f, -1.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f);
	v[1] = TextureVertex(-1.0f, 1.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f);
	v[2] = TextureVertex(1.0f, 1.0f, -1.0f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f);
	v[3] = TextureVertex(1.0f, -1.0f, -1.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f);

	// fill in the back face vertex data
	v[4] = TextureVertex(-1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
	v[5] = TextureVertex(1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f);
	v[6] = TextureVertex(1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
	v[7] = TextureVertex(-1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f);

	// fill in the top face vertex data
	v[8] = TextureVertex(-1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f);
	v[9] = TextureVertex(-1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f);
	v[10] = TextureVertex(1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f);
	v[11] = TextureVertex(1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f);

	// fill in the bottom face vertex data
	v[12] = TextureVertex(-1.0f, -1.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f);
	v[13] = TextureVertex(1.0f, -1.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f);
	v[14] = TextureVertex(1.0f, -1.0f, 1.0f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f);
	v[15] = TextureVertex(-1.0f, -1.0f, 1.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f);

	// fill in the left face vertex data
	v[16] = TextureVertex(-1.0f, -1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[17] = TextureVertex(-1.0f, 1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[18] = TextureVertex(-1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
	v[19] = TextureVertex(-1.0f, -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	// fill in the right face vertex data
	v[20] = TextureVertex(1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[21] = TextureVertex(1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[22] = TextureVertex(1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
	v[23] = TextureVertex(1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	m_VB->Unlock();


	Device->CreateIndexBuffer(
		36 * sizeof(WORD),
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&m_IB,
		0);

	WORD* i = 0;
	m_IB->Lock(0, 0, (void**)&i, 0);

	// fill in the front face index data
	i[0] = 0; i[1] = 1; i[2] = 2;
	i[3] = 0; i[4] = 2; i[5] = 3;

	// fill in the back face index data
	i[6] = 4; i[7] = 5; i[8] = 6;
	i[9] = 4; i[10] = 6; i[11] = 7;

	// fill in the top face index data
	i[12] = 8; i[13] = 9; i[14] = 10;
	i[15] = 8; i[16] = 10; i[17] = 11;

	// fill in the bottom face index data
	i[18] = 12; i[19] = 13; i[20] = 14;
	i[21] = 12; i[22] = 14; i[23] = 15;

	// fill in the left face index data
	i[24] = 16; i[25] = 17; i[26] = 18;
	i[27] = 16; i[28] = 18; i[29] = 19;

	// fill in the right face index data
	i[30] = 20; i[31] = 21; i[32] = 22;
	i[33] = 20; i[34] = 22; i[35] = 23;

	m_IB->Unlock();

	m_D3DMaterial.Ambient = d3d::WHITE;
	m_D3DMaterial.Diffuse = d3d::WHITE;
	m_D3DMaterial.Specular = d3d::WHITE;
	m_D3DMaterial.Emissive = d3d::BLACK;
	m_D3DMaterial.Power = 5.0f;

	//
	// Create texture.
	//
	D3DXCreateTextureFromFile(
		Device,
		"resources\\cratealpha1.dds",
		&m_Texture);

	Device->SetStreamSource(0, m_VB, 0, sizeof(TextureVertex));
	Device->SetIndices(m_IB);
	Device->SetFVF(TextureVertex::FVF);

	return true;
}
void TexCube::Cleanup()
{
	d3d::Release<IDirect3DVertexBuffer9*>(m_VB);
}



void TexCube::Upate(float timeDelta)
{

	static float y = 0.0f;
	D3DXMatrixRotationY(&Ry, y);

	y += timeDelta;
	if (y >= 6.28f)
		y = 0.0f;

}
void TexCube::Render()
{
	// Draw teapot using DrawSubset method with 0 as the argument.
	if (this->GetAlphaBlendEnabled())
		m_Device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	m_Device->SetTexture(0, m_Texture);
	m_Device->SetMaterial(&m_D3DMaterial);
	m_Device->SetTransform(D3DTS_WORLD, &(m_D3DXMATRIX));
	m_Device->DrawIndexedPrimitive(
		D3DPT_TRIANGLELIST,
		0,
		0,
		24,
		0,
		12);

	if (this->GetAlphaBlendEnabled())
		m_Device->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
}