#include "Geometry/Triangle.h"

using namespace d3d;

bool Triangle::Setup(IDirect3DDevice9* Device)
{
	m_Device = Device;
	Device->CreateVertexBuffer(
		3 * sizeof(Vertex), // size in bytes
		D3DUSAGE_WRITEONLY, // flags
		Vertex::FVF,        // vertex format
		D3DPOOL_MANAGED,    // managed memory pool
		&m_VB,          // return create vertex buffer
		0);                 // not used - set to 0

							//
							// Fill the buffers with the triangle data.
							//

	Vertex* vertices;
	m_VB->Lock(0, 0, (void**)&vertices, 0);

	vertices[0] = Vertex(-2.0f, 0.0f, 0.0f);
	vertices[1] = Vertex(0.0f, 2.0f, 0.0f);
	vertices[2] = Vertex(2.0f, 0.0f, 0.0f);

	m_VB->Unlock();

	Device->SetStreamSource(0, m_VB, 0, sizeof(Vertex));
	Device->SetFVF(Vertex::FVF);

	return true;
}
void Triangle::Cleanup()
{
	d3d::Release<IDirect3DVertexBuffer9*>(m_VB);
}
void Triangle::Upate(float timeDelta)
{

}
void Triangle::Render()
{
	// Draw one triangle.
	m_Device->SetTransform(D3DTS_WORLD, &m_D3DXMATRIX);
	m_Device->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
}