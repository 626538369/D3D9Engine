#include "Geometry/LitPyramid.h"

using namespace d3d;

bool LitPyramid::Setup(IDirect3DDevice9* Device)
{
	m_Device = Device;
	
	Device->CreateVertexBuffer(
		12 * sizeof(NormalVertex),
		D3DUSAGE_WRITEONLY,
		Vertex::FVF,
		D3DPOOL_MANAGED,
		&m_VB,
		0);

	//
	// Fill the vertex buffer with pyramid data.
	//

	NormalVertex* v;
	m_VB->Lock(0, 0, (void**)&v, 0);

	// front face
	v[0] = NormalVertex(-1.0f, 0.0f, -1.0f, 0.0f, 0.707f, -0.707f);
	v[1] = NormalVertex(0.0f, 1.0f, 0.0f, 0.0f, 0.707f, -0.707f);
	v[2] = NormalVertex(1.0f, 0.0f, -1.0f, 0.0f, 0.707f, -0.707f);

	// left face
	v[3] = NormalVertex(-1.0f, 0.0f, 1.0f, -0.707f, 0.707f, 0.0f);
	v[4] = NormalVertex(0.0f, 1.0f, 0.0f, -0.707f, 0.707f, 0.0f);
	v[5] = NormalVertex(-1.0f, 0.0f, -1.0f, -0.707f, 0.707f, 0.0f);

	// right face
	v[6] = NormalVertex(1.0f, 0.0f, -1.0f, 0.707f, 0.707f, 0.0f);
	v[7] = NormalVertex(0.0f, 1.0f, 0.0f, 0.707f, 0.707f, 0.0f);
	v[8] = NormalVertex(1.0f, 0.0f, 1.0f, 0.707f, 0.707f, 0.0f);

	// back face
	v[9] = NormalVertex(1.0f, 0.0f, 1.0f, 0.0f, 0.707f, 0.707f);
	v[10] = NormalVertex(0.0f, 1.0f, 0.0f, 0.0f, 0.707f, 0.707f);
	v[11] = NormalVertex(-1.0f, 0.0f, 1.0f, 0.0f, 0.707f, 0.707f);

	m_VB->Unlock();

	m_D3DMaterial.Ambient = d3d::WHITE;
	m_D3DMaterial.Diffuse = d3d::WHITE;
	m_D3DMaterial.Specular = d3d::WHITE;
	m_D3DMaterial.Emissive = d3d::BLACK;
	m_D3DMaterial.Power = 5.0f;

	Device->SetStreamSource(0, m_VB, 0, sizeof(NormalVertex));
	Device->SetFVF(NormalVertex::FVF);

	return true;
}
void LitPyramid::Cleanup()
{
	d3d::Release<IDirect3DVertexBuffer9*>(m_VB);
}



void LitPyramid::Upate(float timeDelta)
{

	static float y = 0.0f;
	D3DXMatrixRotationY(&Ry, y);

	y += timeDelta;
	if (y >= 6.28f)
		y = 0.0f;

}
void LitPyramid::Render()
{
	// Draw teapot using DrawSubset method with 0 as the argument.
	m_Device->SetMaterial(&m_D3DMaterial);
	m_Device->SetTransform(D3DTS_WORLD, &(Ry * m_D3DXMATRIX));
	m_Device->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 4);
}