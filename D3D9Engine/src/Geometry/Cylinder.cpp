#include "Geometry/Cylinder.h"

using namespace d3d;

bool Cylinder::Setup(IDirect3DDevice9* Device)
{
	m_Device = Device;
	D3DXCreateCylinder(
		Device,
		1.0f, // radius at negative z end
		1.0f, // radius at positive z end
		3.0f, // length of cylinder
		10,   // slices
		10,   // stacks
		&m_Cylinder,
		0);
	return true;
}
void Cylinder::Cleanup()
{
	d3d::Release<ID3DXMesh*>(m_Cylinder);
}
void Cylinder::Upate(float timeDelta)
{
	static float y = 0.0f;
	D3DXMatrixRotationY(&Ry, y);

	y += timeDelta;
	if (y >= 6.28f)
		y = 0.0f;

}
void Cylinder::Render()
{
	// Draw teapot using DrawSubset method with 0 as the argument.
	m_Device->SetTransform(D3DTS_WORLD, &(Ry * m_D3DXMATRIX));
	m_Cylinder->DrawSubset(0);
}