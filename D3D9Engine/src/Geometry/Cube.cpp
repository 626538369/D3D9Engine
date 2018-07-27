#include "Geometry/Cube.h"

using namespace d3d;


bool Cube::Setup(IDirect3DDevice9* Device)
{
	//
	// Create vertex and index buffers.
	//

	m_Device = Device;

	Device->CreateVertexBuffer(
		8 * sizeof(Vertex),
		D3DUSAGE_WRITEONLY,
		Vertex::FVF,
		D3DPOOL_MANAGED,
		&m_VB,
		0);

	Device->CreateIndexBuffer(
		36 * sizeof(WORD),
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&m_IB,
		0);


	// define unique vertices:
	Vertex* vertices;
	m_VB->Lock(0, 0, (void**)&vertices, 0);

	// vertices of a unit cube
	vertices[0] = Vertex(-1.0f, -1.0f, -1.0f);
	vertices[1] = Vertex(-1.0f, 1.0f, -1.0f);
	vertices[2] = Vertex(1.0f, 1.0f, -1.0f);
	vertices[3] = Vertex(1.0f, -1.0f, -1.0f);
	vertices[4] = Vertex(-1.0f, -1.0f, 1.0f);
	vertices[5] = Vertex(-1.0f, 1.0f, 1.0f);
	vertices[6] = Vertex(1.0f, 1.0f, 1.0f);
	vertices[7] = Vertex(1.0f, -1.0f, 1.0f);

	m_VB->Unlock();

	// define the triangles of the cube:
	WORD* indices = 0;
	m_IB->Lock(0, 0, (void**)&indices, 0);

	// front side
	indices[0] = 0; indices[1] = 1; indices[2] = 2;
	indices[3] = 0; indices[4] = 2; indices[5] = 3;

	// back side
	indices[6] = 4; indices[7] = 6; indices[8] = 5;
	indices[9] = 4; indices[10] = 7; indices[11] = 6;

	// left side
	indices[12] = 4; indices[13] = 5; indices[14] = 1;
	indices[15] = 4; indices[16] = 1; indices[17] = 0;

	// right side
	indices[18] = 3; indices[19] = 2; indices[20] = 6;
	indices[21] = 3; indices[22] = 6; indices[23] = 7;

	// top
	indices[24] = 1; indices[25] = 5; indices[26] = 6;
	indices[27] = 1; indices[28] = 6; indices[29] = 2;

	// bottom
	indices[30] = 4; indices[31] = 0; indices[32] = 3;
	indices[33] = 4; indices[34] = 3; indices[35] = 7;

	m_IB->Unlock();

	m_Device->SetStreamSource(0, m_VB, 0, sizeof(Vertex));
	m_Device->SetIndices(m_IB);
	m_Device->SetFVF(Vertex::FVF);

	return true;
}

void Cube::SetDirect3DDevice(IDirect3DDevice9* Device)
{
	m_Device = Device;
}

void Cube::Cleanup()
{
	d3d::Release<IDirect3DVertexBuffer9*>(m_VB);
	d3d::Release<IDirect3DIndexBuffer9*>(m_IB);
}

void Cube::Upate(float timeDelta)
{
	
}


void Cube::Render()
{

	// Draw cube.
	//m_Device->SetTransform(D3DTS_WORLD, &m_D3DXMATRIX);
	m_Device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 12);
}