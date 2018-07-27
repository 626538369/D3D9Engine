#include "Geometry/GeometryManager.h"
#include "Geometry/Cube.h"
#include "Geometry/Triangle.h"
#include "Geometry/Teapot.h"
#include "Geometry/Cylinder.h"
#include "Geometry/ColorTriangle.h"
#include "Geometry/LitPyramid.h"
#include "Geometry/LitSphere.h"
#include "Geometry/TexQuad.h"
#include "Geometry/TexCube.h"
using namespace d3d;

GeometryManager::GeometryManager()
{
	D3DXMATRIX postionMat;
	//D3DXMatrixTranslation(&postionMat, -2.0f, 0.0f, 0.0f);
	//m_Cube = new Cube();
	//m_Cube->SetPosition(postionMat);

	//D3DXMatrixTranslation(&postionMat, -3.0f, 0.0f, 0.0f);
	//m_Triangle = new Triangle();
	//m_Triangle->SetPosition(postionMat);


	//D3DXMatrixTranslation(&postionMat, -3.0f, 0.0f, 0.0f);
	//m_Cylinder = new Cylinder();
	//m_Cylinder->SetPosition(postionMat);

	//D3DXMatrixTranslation(&postionMat, 3.0f, 0.0f, 0.0f);
	//m_Teapot = new Teapot();
	//m_Teapot->SetPosition(postionMat);

	//D3DXMatrixTranslation(&postionMat, -3.0f, 0.0f, 0.0f);
	//m_ColorTriangle1 = new ColorTriangle();
	//m_ColorTriangle1->SetPosition(postionMat);
	//m_ColorTriangle1->SetShaderMode(D3DSHADE_FLAT);

	//D3DXMatrixTranslation(&postionMat, 3.0f, 0.0f, 0.0f);
	//m_ColorTriangle2 = new ColorTriangle();
	//m_ColorTriangle2->SetPosition(postionMat);
	//m_ColorTriangle1->SetShaderMode(D3DSHADE_GOURAUD);

	//D3DXMatrixTranslation(&postionMat, 3.0f, 0.0f, 0.0f);
	//m_LitPyramid = new LitPyramid();
	//m_LitPyramid->SetPosition(postionMat);

	//D3DXMatrixTranslation(&postionMat, 0.0f, -2.0f, 0.0f);
	//m_LitSphere = new LitSphere();
	//m_LitSphere->SetPosition(postionMat);

	//D3DXMatrixTranslation(&postionMat, 0.0f, 0.0f, 0.0f);
	//m_TexQuad = new TexQuad();
	//m_TexQuad->SetPosition(postionMat);

	D3DXMatrixTranslation(&postionMat, 0.0f, 0.0f, 0.0f);
	m_TexCube = new TexCube();
	m_TexCube->SetPosition(postionMat);
}


bool GeometryManager::Setup(IDirect3DDevice9* Device)
{
	//m_Cube->Setup(Device);
	//m_Triangle->Setup(Device);

	//m_Teapot->Setup(Device);
	//m_Cylinder->Setup(Device);

	//m_ColorTriangle1->Setup(Device);
	//m_ColorTriangle2->Setup(Device);

	//m_LitPyramid->Setup(Device);

	//m_LitSphere->Setup(Device);

	//m_TexQuad->Setup(Device);

	m_TexCube->Setup(Device);

	return true;
}
void GeometryManager::Cleanup()
{
	//m_Cube->Cleanup();

	//m_Triangle->Cleanup();

	//m_Teapot->Cleanup();
	//m_Cylinder->Cleanup();

	//m_ColorTriangle1->Cleanup();
	//m_ColorTriangle2->Cleanup();
	//m_LitPyramid->Cleanup();

	//m_LitSphere->Cleanup();

	//m_TexQuad->Cleanup();

	m_TexCube->Cleanup();
}

void GeometryManager::Upate(float timeDelta)
{
	//m_Cube->Upate(timeDelta);
	//m_Triangle->Upate(timeDelta);

	//m_Teapot->Upate(timeDelta);
	//m_Cylinder->Upate(timeDelta);
	
	//m_ColorTriangle1->Upate(timeDelta);
	//m_ColorTriangle2->Upate(timeDelta);

	//m_LitPyramid->Upate(timeDelta);

	//m_LitSphere->Upate(timeDelta);
	//m_TexQuad->Upate(timeDelta);

	m_TexCube->Upate(timeDelta);
}
void GeometryManager::Render()
{
	//m_Cube->Render();
	//m_Triangle->Render();

	//m_Teapot->Render();
	//m_Cylinder->Render();
	//m_ColorTriangle1->Render();
	//m_ColorTriangle2->Render();

	//m_LitPyramid->Render();
	//m_LitSphere->Render();


	//m_TexQuad->Render();

	m_TexCube->Render();
}

void GeometryManager::SetAlphaBlendEnabled(bool enabled)
{
	m_TexCube->SetAlphaBlendEnabled(enabled);
}