#pragma once
#include "d3dUtility.h"

namespace d3d
{
	class GeometryBase
	{
	public:
		GeometryBase() {}
		~GeometryBase(){}

		void SetPosition(D3DXMATRIX mat) { m_D3DXMATRIX = mat; }
		void SetAlphaBlendEnabled(bool enabled) { m_AlphaBlendEnabled = enabled; };
		bool GetAlphaBlendEnabled() { return m_AlphaBlendEnabled; };
	protected :
		bool m_AlphaBlendEnabled = false;
		D3DXMATRIX  m_D3DXMATRIX;
	};
}
