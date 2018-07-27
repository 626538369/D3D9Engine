#include "Geometry/Teapot.h"

using namespace d3d;

bool Teapot::Setup(IDirect3DDevice9* Device)
{
	m_Device = Device;
	D3DXCreateTeapot(Device, &m_Teapot, 0);
	return true;
}
void Teapot::Cleanup()
{
	d3d::Release<ID3DXMesh*>(m_Teapot);
}



void Teapot::Upate(float timeDelta)
{
	
	static float y = 0.0f;
	D3DXMatrixRotationY(&Ry, y);

	y += timeDelta ;
	if (y >= 6.28f)
		y = 0.0f;

}
void Teapot::Render()
{
	// Draw teapot using DrawSubset method with 0 as the argument.
	m_Device->SetTransform(D3DTS_WORLD, &(Ry * m_D3DXMATRIX));
	m_Teapot->DrawSubset(0);
}