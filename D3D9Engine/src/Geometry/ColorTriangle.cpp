#include "Geometry/ColorTriangle.h"

using namespace d3d;

bool ColorTriangle::Setup(IDirect3DDevice9* Device)
{
	m_Device = Device;
	Device->CreateVertexBuffer(
		3 * sizeof(Vertex), // size in bytes
		D3DUSAGE_WRITEONLY, // flags
		ColorVertex::FVF,        // vertex format
		D3DPOOL_MANAGED,    // managed memory pool
		&m_VB,          // return create vertex buffer
		0);                 // not used - set to 0

							//
							// Fill the buffers with the triangle data.
							//

	ColorVertex* vertices;
	m_VB->Lock(0, 0, (void**)&vertices, 0);

	vertices[0] = ColorVertex(-2.0f, 0.0f, 0.0f, D3DCOLOR_XRGB(255, 0, 0));
	vertices[1] = ColorVertex(0.0f, 2.0f, 0.0f, D3DCOLOR_XRGB(0, 255, 0));
	vertices[2] = ColorVertex(2.0f, 0.0f, 0.0f, D3DCOLOR_XRGB(0, 0, 255));

	m_VB->Unlock();

	Device->SetStreamSource(0, m_VB, 0, sizeof(ColorVertex));
	Device->SetFVF(ColorVertex::FVF);

	return true;
}
void ColorTriangle::Cleanup()
{
	d3d::Release<IDirect3DVertexBuffer9*>(m_VB);
}
void ColorTriangle::Upate(float timeDelta)
{

}
void ColorTriangle::Render()
{
	// Draw one triangle.
	m_Device->SetRenderState(D3DRS_SHADEMODE, m_D3DSHADEMODE);
	m_Device->SetTransform(D3DTS_WORLD, &m_D3DXMATRIX);
	m_Device->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
}