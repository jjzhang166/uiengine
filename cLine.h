#pragma once
#include"cBaseUI.h"

namespace MyEngine
{

	class cLine:public cBaseUI
	{
	public:
		cLine();

		/*

		*/
		explicit cLine(const POINT& start, const POINT& end);

		/*

		*/
		cLine(const int& startx, const int& starty, const int& endx, const int& endy);
		~cLine();

		/*

		*/
		void SetStartPoint(const POINT& start);

		/*

		*/
		void SetEndPoint(const POINT& end);

		/*

		*/
		const POINT& GetStartPoint() const;

		/*

		*/
		const POINT& GetEndPoint() const;

		/*

		*/
		void SetStartPoint(const int& x, const int& y);

		/*

		*/
		void SetEndPoint(const int& x, const int& y);

		/*

		*/
		void SetWidth(const int& w);

		/*

		*/
		const int& GetWidth() const;

		/*

		*/
		void SetColor(const UINT& rgb);

		/*

		*/
		const UINT& GetColor() const;

		/*
		
		*/
		void SetStyle(const UINT& style);

		/*
		
		*/
		const UINT& GetStyle() const;

	   /*
		Draw(HDC hDc)
		����ui�ؼ�
		@Param:
			HDC hDc:�豸DC
		*/
		virtual bool Draw(HDC hDc) override;


		/*
		GetRect()
		��ȡui�ؼ�һ����������
		@return RECT��
		ui�ؼ��ľ�������
		*/
		virtual const RECT&& GetRect() const override;
	private:
		POINT m_startPoint;

		POINT m_endSPoint;

		int m_width;

		UINT m_color;

		UINT m_style;
	};
}