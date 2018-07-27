#include "Geometry/LitSphere.h"

using namespace d3d;

bool LitSphere::Setup(IDirect3DDevice9* Device)
{
	m_Device = Device;
	D3DXCreateSphere(Device,1,20,20, &m_Sphere, 0);
	m_D3DMaterial =  d3d::BLUE_MTRL;
	return true;
}
void LitSphere::Cleanup()
{
	d3d::Release<ID3DXMesh*>(m_Sphere);
}


void LitSphere::Upate(float timeDelta)
{

	static float y = 0.0f;
	D3DXMatrixRotationY(&Ry, y);

	y += timeDelta;
	if (y >= 6.28f)
		y = 0.0f;

}
void LitSphere::Render()
{
	// Draw teapot using DrawSubset method with 0 as the argument.
	m_Device->SetMaterial(&m_D3DMaterial);
	m_Device->SetTransform(D3DTS_WORLD, &(Ry * m_D3DXMATRIX));
	m_Sphere->DrawSubset(0);
}