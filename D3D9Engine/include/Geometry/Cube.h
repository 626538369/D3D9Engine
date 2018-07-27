//////////////////////////////////////////////////////////////////////////////////////////////////
// 
// File: cube.cpp
// 
// Author: Frank Luna (C) All Rights Reserved
//
// System: AMD Athlon 1800+ XP, 512 DDR, Geforce 3, Windows XP, MSVC++ 7.0 
//
// Desc: Renders a spinning cube in wireframe mode.  Demonstrates vertex and 
//       index buffers, world and view transformations, render states and
//       drawing commands.
//          
//////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "d3dUtility.h"
#include "Geometry/GeometryBase.h"
namespace d3d
{
	class Cube : public GeometryBase
	{
	public:
		bool Setup(IDirect3DDevice9* Device);
		void Cleanup();
		void Upate(float timeDelta);
		void Render();
		void SetDirect3DDevice(IDirect3DDevice9* Device);
		
	private :
		IDirect3DVertexBuffer9* m_VB = 0;
		IDirect3DIndexBuffer9*  m_IB = 0;

		IDirect3DDevice9* m_Device;

	};
}