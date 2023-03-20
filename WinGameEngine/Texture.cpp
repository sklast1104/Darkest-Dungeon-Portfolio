#include "stdafx.h"
#include "Texture.h"

#include "Core.h"

Texture::Texture()
	: m_hBit(0)
	, m_dc(0)
	, m_bitInfo{}
{
}

Texture::~Texture()
{
	DeleteDC(m_dc);
	DeleteObject(m_hBit);
}

HBITMAP Texture::LoadPNG(const wstring& _filename)
{
	using namespace Gdiplus;

	ULONG_PTR gdiplusToken;

	GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	Image* image = Image::FromFile(_filename.c_str());

	assert(image);

	Bitmap* pBitmap = static_cast<Bitmap*>(image->Clone());
	HBITMAP hBitmap = NULL;
	Status status = pBitmap->GetHBITMAP(Color(0, 0, 0), &hBitmap);

	GdiplusShutdown(gdiplusToken);

	return hBitmap;
}

void Texture::Load(const wstring& _strFilePath)
{
	std::string fn(_strFilePath.begin(), _strFilePath.end());
	std::string ext = fn.substr(fn.find_last_of(".") + 1);

	if (ext == "bmp") {
		m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	}
	else if (ext == "png") {
		m_hBit = LoadPNG(_strFilePath);
	}

	assert(m_hBit);

	m_dc = CreateCompatibleDC(Core::GetInst()->GetMainDC());

	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_dc, m_hBit);
	DeleteObject(hPrevBit);

	GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);
}

void Texture::Create(UINT _iWidth, UINT _iHeight)
{
	HDC maindc = Core::GetInst()->GetMainDC();

	m_hBit = CreateCompatibleBitmap(maindc, _iWidth, _iHeight);
	m_dc = CreateCompatibleDC(maindc);

	HBITMAP hOldBit = (HBITMAP)SelectObject(m_dc, m_hBit);
	DeleteObject(hOldBit);

	//∫Ò∆Æ∏  ¡§∫∏
	GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);
}
