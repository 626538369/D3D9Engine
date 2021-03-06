#pragma once
#include "d3dUtility.h"
#include "Geometry/GeometryBase.h"

namespace d3d
{
	class LitSphere : public GeometryBase
	{
	public:
		bool Setup(IDirect3DDevice9* Device);
		void Cleanup();
		void Upate(float timeDelta);
		void Render();
	private:
		// Mesh interface that will store the teapot data and contains
		// ma method to render the teapot data.
		ID3DXMesh * m_Sphere = 0;

		IDirect3DDevice9* m_Device;

		D3DMATERIAL9 m_D3DMaterial;

		D3DXMATRIX Ry;
	};
}