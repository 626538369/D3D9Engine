#pragma once

#include "d3dUtility.h"

namespace d3d
{
	class Cube;
	class Triangle;
	class Teapot;
	class Cylinder;
	class ColorTriangle;
	class LitPyramid;
	class LitSphere;
	class TexQuad;
	class TexCube;

	class GeometryManager
	{
	public:
		GeometryManager();
		~GeometryManager() {}


		bool Setup(IDirect3DDevice9* Device);
		void Cleanup();

		void Upate(float timeDelta);
		void Render();

		void SetAlphaBlendEnabled(bool enabled);

	private:
		Cube* m_Cube;
		Triangle* m_Triangle;
		Teapot* m_Teapot;
		Cylinder* m_Cylinder;

		ColorTriangle* m_ColorTriangle1;
		ColorTriangle* m_ColorTriangle2;

		LitPyramid* m_LitPyramid;

		LitSphere* m_LitSphere;

		TexQuad* m_TexQuad;

		TexCube* m_TexCube;
	};

}

