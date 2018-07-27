#pragma once
#include "d3dUtility.h"
#include "Geometry/GeometryBase.h"
namespace d3d
{
	class ColorTriangle :public GeometryBase
	{
	public:
		bool Setup(IDirect3DDevice9* Device);
		void Cleanup();
		void Upate(float timeDelta);
		void Render();
		void SetShaderMode(D3DSHADEMODE mode) { m_D3DSHADEMODE = mode; }
	private:
		IDirect3DVertexBuffer9 * m_VB = 0;
		IDirect3DIndexBuffer9*  m_IB = 0;

		IDirect3DDevice9* m_Device;

		D3DSHADEMODE m_D3DSHADEMODE = D3DSHADE_FLAT;
	};
}


#pragma once
