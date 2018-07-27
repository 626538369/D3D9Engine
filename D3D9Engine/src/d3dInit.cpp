//////////////////////////////////////////////////////////////////////////////////////////////////
// 
// File: d3dinit.cpp
// 
// Author: Frank Luna (C) All Rights Reserved
//
// System: AMD Athlon 1800+ XP, 512 DDR, Geforce 3, Windows XP, MSVC++ 7.0 
//
// Desc: Demonstrates how to initialize Direct3D, how to use the book's framework
//       functions, and how to clear the screen to black.  Note that the Direct3D
//       initialization code is in the d3dUtility.h/.cpp files.
//          
//////////////////////////////////////////////////////////////////////////////////////////////////

#include "d3dUtility.h"
#include "Geometry/GeometryManager.h"
#include "Vertex.h"
//
// Globals
//

using namespace d3d;

IDirect3DDevice9* Device = 0; 

//
// Framework Functions
//

const int Width = 640;
const int Height = 480;

d3d::GeometryManager GGeometryManager;

void SetupBackground();

IDirect3DVertexBuffer9* BackDropVB = 0;
IDirect3DTexture9*      BackDropTex = 0;
bool ShowBackground = true;
bool LightEnabled = true;
bool AlphaBlendEnabled = true;

bool Setup()
{
	
	if (ShowBackground)
	{
		SetupBackground();
	}

	D3DXVECTOR3 position(0.0f, 0.0f, -5.0f);
	D3DXVECTOR3 target(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
	D3DXMATRIX V;
	D3DXMatrixLookAtLH(&V, &position, &target, &up);

	Device->SetTransform(D3DTS_VIEW, &V);


	D3DXMATRIX proj;
	D3DXMatrixPerspectiveFovLH(
		&proj,
		D3DX_PI * 0.5f, // 90 - degree
		(float)Width / (float)Height,
		1.0f,
		1000.0f);
	Device->SetTransform(D3DTS_PROJECTION, &proj);

	//
	// Switch to wireframe mode.
	//
	//Device->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);


	if (LightEnabled)
	{
		D3DXVECTOR3 dir(1.0f, -0.0f, 0.25f);
		D3DXCOLOR   c = d3d::WHITE;
		D3DLIGHT9 dirLight = d3d::InitDirectionalLight(&dir, &c);

		//
		// Set and Enable the light.
		//

		Device->SetLight(0, &dirLight);
		Device->LightEnable(0, true);
	}
		

	//
	// Turn on specular lighting and instruct Direct3D
	// to renormalize normals.
	//

	//
	// set alpha blending stuff
	//

	// use alpha channel in texture for alpha
	Device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	Device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);

	// set blending factors so that alpha component determines transparency
	Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	Device->SetRenderState(D3DRS_NORMALIZENORMALS, true);
	Device->SetRenderState(D3DRS_SPECULARENABLE, true);

	Device->SetRenderState(D3DRS_LIGHTING, LightEnabled);
	Device->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_PHONG);

	Device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	Device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	Device->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);

	GGeometryManager.Setup(Device);

	GGeometryManager.SetAlphaBlendEnabled(AlphaBlendEnabled);

	return true;
}

void Cleanup()
{
	// Nothing to cleanup in this sample.
}

void UpdateCamera(float timeDelta)
{
	static float angle = (3.0f * D3DX_PI) / 2.0f;
	static float height = 5.0f;

	if (::GetAsyncKeyState(VK_LEFT) & 0x8000f)
		angle -= 0.5f * timeDelta;

	if (::GetAsyncKeyState(VK_RIGHT) & 0x8000f)
		angle += 0.5f * timeDelta;

	if (::GetAsyncKeyState(VK_UP) & 0x8000f)
		height += 5.0f * timeDelta;

	if (::GetAsyncKeyState(VK_DOWN) & 0x8000f)
		height -= 5.0f * timeDelta;

	D3DXVECTOR3 position(cosf(angle) * 7.0f, height, sinf(angle) * 7.0f);
	D3DXVECTOR3 target(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
	D3DXMATRIX V;
	D3DXMatrixLookAtLH(&V, &position, &target, &up);

	Device->SetTransform(D3DTS_VIEW, &V);
}

void SetupBackground()
{
	Device->CreateVertexBuffer(
		6 * sizeof(TextureVertex),
		D3DUSAGE_WRITEONLY,
		TextureVertex::FVF,
		D3DPOOL_MANAGED,
		&BackDropVB,
		0);

	TextureVertex* v;
	BackDropVB->Lock(0, 0, (void**)&v, 0);

	// quad built from two triangles, note texture coordinates:
	v[0] = TextureVertex(-10.0f, -10.0f, 5.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f);
	v[1] = TextureVertex(-10.0f, 10.0f, 5.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f);
	v[2] = TextureVertex(10.0f, 10.0f, 5.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f);

	v[3] = TextureVertex(-10.0f, -10.0f, 5.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f);
	v[4] = TextureVertex(10.0f, 10.0f, 5.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f);
	v[5] = TextureVertex(10.0f, -10.0f, 5.0f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f);

	BackDropVB->Unlock();

	D3DXCreateTextureFromFile(
		Device,
		"resources\\lobbyxpos.JPG",
		&BackDropTex);
}
void DrawBackground()
{
	// draw back drop
	D3DXMATRIX I;
	D3DXMatrixIdentity(&I);
	Device->SetStreamSource(0, BackDropVB, 0, sizeof(TextureVertex));
	Device->SetFVF(FVF_VERTEX);
	Device->SetTexture(0, BackDropTex);
	Device->SetTransform(D3DTS_WORLD, &I);
	Device->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
}

bool Display(float timeDelta)
{
	if( Device ) // Only use Device methods if we have a valid device.
	{

		//UpdateCamera(timeDelta);

		GGeometryManager.Upate(timeDelta);
		// Instruct the device to set each pixel on the back buffer black -
		// D3DCLEAR_TARGET: 0x00000000 (black) - and to set each pixel on
		// the depth buffer to a value of 1.0 - D3DCLEAR_ZBUFFER: 1.0f.
		Device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xff0000ff, 1.0f, 0);
		Device->BeginScene();

		if (ShowBackground)
			DrawBackground();

		GGeometryManager.Render();
		Device->EndScene();
		// Swap the back and front buffers.
		Device->Present(0, 0, 0, 0);
	}
	return true;
}

//
// WndProc
//
LRESULT CALLBACK d3d::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch( msg )
	{
	case WM_DESTROY:
		::PostQuitMessage(0);
		break;
		
	case WM_KEYDOWN:
		if( wParam == VK_ESCAPE )
			::DestroyWindow(hwnd);
		break;
	}
	return ::DefWindowProc(hwnd, msg, wParam, lParam);
}

//
// WinMain
//
int WINAPI WinMain(HINSTANCE hinstance,
				   HINSTANCE prevInstance, 
				   PSTR cmdLine,
				   int showCmd)
{
	if(!d3d::InitD3D(hinstance,
		1024, 768, true, D3DDEVTYPE_HAL, &Device))
	{
		::MessageBox(0, "InitD3D() - FAILED", 0, 0);
		return 0;
	}
		
	if(!Setup())
	{
		::MessageBox(0, "Setup() - FAILED", 0, 0);
		return 0;
	}

	d3d::EnterMsgLoop( Display );

	Cleanup();

	Device->Release();

	return 0;
}