#include "stdafx.h"
#include "cButton.h"
#include"Tool.h"
using namespace MyEngine;

cButton::cButton()
{
	m_bgBitmap = NULL;
	m_firstBountColor = RGB(0, 255, 0);
	m_secBountColor = RGB(127, 127, 127);
	m_firstColor = RGB(153,217,234);
	m_font = L"����";
	m_fontColor = RGB(250, 0, 0);
	m_height = 30;
	m_Name = L"Button";
	m_nBount = 3;
	m_secondColor= RGB(255, 255, 255);
	m_width = 100;
	m_bgColor = m_firstColor;
	m_BountColor = m_firstBountColor;
}

MyEngine::cButton::cButton(const LPWSTR & Name, const int & width, const int & height)
{
	m_bgBitmap = NULL;
	m_firstBountColor = RGB(0, 255, 0);
	m_secBountColor = RGB(127, 127, 127);
	m_firstColor = RGB(153, 217, 234);
	m_font = L"����";
	m_fontColor = RGB(255, 0, 0);
	m_height = height;
	m_Name = Name;
	m_nBount = 3;
	m_secondColor = RGB(255, 255, 255);
	m_width = width;
	m_bgColor = m_firstColor;
	m_BountColor = m_firstBountColor;
}

MyEngine::cButton::cButton(const LPWSTR & bmpPath)
{
	m_bgBitmap = (HBITMAP)LoadImage(nullptr, bmpPath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	BITMAP bitmap;
	GetObject(m_bgBitmap, sizeof(BITMAP), &bitmap);
	m_firstBountColor = RGB(0, 255, 0);
	m_secBountColor = RGB(127, 127, 127);
	m_firstColor = RGB(153, 217, 234);
	m_font = L"����";
	m_fontColor = RGB(250, 0, 0);
	m_height = bitmap.bmHeight;
	m_Name = L"Button";
	m_nBount = 3;
	m_secondColor = RGB(255, 255, 255);
	m_width = bitmap.bmWidth;
	m_bgColor = m_firstColor;
	m_BountColor = m_firstBountColor;
}

MyEngine::cButton::cButton(const HBITMAP & hbitmap)
{
	m_bgBitmap = hbitmap;
	BITMAP bitmap;
	GetObject(m_bgBitmap, sizeof(BITMAP), &bitmap);
	m_firstBountColor = RGB(0, 255, 0);
	m_secBountColor = RGB(127, 127, 127);
	m_firstColor = RGB(153, 217, 234);
	m_font = L"����";
	m_fontColor = RGB(250, 0, 0);
	m_height = bitmap.bmHeight;
	m_Name = L"Button";
	m_nBount = 3;
	m_secondColor = RGB(255, 255, 255);
	m_width = bitmap.bmWidth;
	m_bgColor = m_firstColor;
	m_BountColor = m_firstBountColor;
}

cButton::~cButton()
{
	if (m_bgBitmap)
	{
		DeleteObject(m_bgBitmap);
	}
}

void MyEngine::cButton::SetName(const LPWSTR & Name)
{
	m_Name = Name;
}

const LPWSTR & MyEngine::cButton::GetName() const
{
	return m_Name;
}

void MyEngine::cButton::SetWidth(const int & width)
{
	m_width = width;
}

const int & MyEngine::cButton::GetWidth() const
{
	return m_width;
}

void MyEngine::cButton::SetHeight(const int & Height)
{
	m_height = Height;
}

const int & MyEngine::cButton::GetHeight() const
{
	return m_height;
}

void MyEngine::cButton::SetnBount(const int & n)
{
	m_nBount = n;
}

const int & MyEngine::cButton::GetBount() const
{
	return m_nBount;
}

void MyEngine::cButton::SetBountColor(const UINT & rgb)
{
	m_BountColor = rgb;
}

const UINT & MyEngine::cButton::GetBountColor() const
{
	return m_BountColor;
}

void MyEngine::cButton::SetfirstColor(const UINT & rgb)
{
	m_firstColor = rgb;
}

const UINT & MyEngine::cButton::GetfirstColor() const
{
	return m_BountColor;
}

void MyEngine::cButton::SetsecondColor(const UINT & rgb)
{
	m_secondColor = rgb;
}

const UINT & MyEngine::cButton::GetsecondColor() const
{
	return m_secondColor;
}

const RECT MyEngine::cButton::GetRect() const
{
	RECT rect;
	rect.left = GetX();
	rect.right = GetX() + m_width;
	rect.top = GetY();
	rect.bottom = GetY() + m_height;
	return rect;
}

bool MyEngine::cButton::Draw(HDC hDc)
{
	if (!m_bgBitmap)
	{
		return DrawNormal(hDc);
	}
	else
	{
		return DrawBitmapBtn(hDc);
	}
}

bool MyEngine::cButton::DrawNormal(HDC hDc)
{
	if (hDc == NULL)
	{
		return false;
	}
	static unsigned wordLen = lstrlenW(m_Name);  //�ַ�����
	static unsigned wordHei = m_height - 8;   //���ָ߶�
	static unsigned wordWid = wordHei / 2;  //����
											//ͳ�ư�ť�����к��Ӹ���
	static int num = WcharArrayChineseNums(m_Name);
	//��������
	HFONT hFont = CreateFont(wordHei, wordWid, NULL, NULL, 400, FALSE,
		FALSE, FALSE, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH, m_font);
	hFont = (HFONT)SelectObject(hDc, hFont);
	//���û���
	HPEN hPen = CreatePen(PS_SOLID, m_nBount, m_BountColor);
	hPen = (HPEN)SelectObject(hDc, hPen);
	//���û�ˢ
	HBRUSH hBrush = CreateSolidBrush(m_bgColor);
	hBrush = (HBRUSH)SelectObject(hDc, hBrush);
	//���ư�ť����
	RECT rect = GetRect();
	Rectangle(hDc, rect.left, rect.top, rect.right, rect.bottom);
	//���ư�ť����
	SetBkMode(hDc, NULL);
	SetTextColor(hDc, m_fontColor);
	TextOut(hDc, rect.left + (m_width - wordWid*(wordLen + num)) / 2,
		rect.top + 4, m_Name, wordLen);
	//��ԭhDc���ü�ɾ�������Դ
	SelectObject(hDc, hPen);
	SelectObject(hDc, hBrush);
	SelectObject(hDc, hFont);
	DeleteObject(hPen);
	DeleteObject(hBrush);
	DeleteObject(hFont);
	return true;
}

bool MyEngine::cButton::DrawBitmapBtn(HDC hDc)
{
	if (hDc == NULL)
	{
		return false;
	}

	HDC hMemDc = CreateCompatibleDC(hDc);
	SelectObject(hMemDc, m_bgBitmap);
	BitBlt(hDc, GetX(), GetY(), m_width, m_height, hMemDc, 0, 0, SRCCOPY);

	RECT rect = GetRect();
	HPEN hPen = CreatePen(PS_SOLID, m_nBount, m_BountColor);
	hPen = (HPEN)SelectObject(hDc, hPen);
	HBRUSH hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
	hBrush = (HBRUSH)SelectObject(hDc, hBrush);
	Rectangle(hDc, rect.left, rect.top, rect.right, rect.bottom);

	SelectObject(hDc,hPen);
	SelectObject(hDc, hBrush);
	DeleteObject(hPen);
	DeleteObject(hBrush);
	DeleteDC(hMemDc);
	return true;
}

void MyEngine::cButton::SetFont(const LPWSTR & font)
{
	m_font = font;
}

const LPWSTR & MyEngine::cButton::GetFont() const
{
	return m_font;
}

void MyEngine::cButton::SetFontColor(const UINT & rgb)
{
	m_fontColor = rgb;
}

const UINT & MyEngine::cButton::GetFontColor() const
{
	return m_fontColor;
}

void MyEngine::cButton::ChangeColor(Btn_Status focus)
{
	if (focus == Get_Focus)
	{
		m_bgColor = m_secondColor;
	}
	else if(focus==Lost_Focus)
	{
		m_bgColor = m_firstColor;
	}
}

void MyEngine::cButton::ChangeBountColor(Btn_Status clicked)
{
	if (clicked == Mouse_Down)
	{
		m_BountColor = m_secBountColor;
	}
	else if (clicked == Mouse_Up)
	{
		m_BountColor = m_firstBountColor;
	}
}

void MyEngine::cButton::SetBmpBtn(const LPWSTR & bmpPath)
{
	m_bgBitmap = (HBITMAP)LoadImage(nullptr, bmpPath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	BITMAP bitmap;
	GetObject(m_bgBitmap, sizeof(BITMAP), &bitmap);
	m_width = bitmap.bmWidth;
	m_height = bitmap.bmHeight;
}

void MyEngine::cButton::SetBmpBtn(const HBITMAP & hbitmap)
{
	m_bgBitmap = hbitmap;
	BITMAP bitmap;
	GetObject(m_bgBitmap, sizeof(BITMAP), &bitmap);
	m_width = bitmap.bmWidth;
	m_height = bitmap.bmHeight;
}