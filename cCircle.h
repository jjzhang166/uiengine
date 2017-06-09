#pragma once
#include"cBaseUI.h"

namespace MyEngine
{

	class cCircle:public cBaseUI
	{
	public:
		cCircle();

		/*
		
		*/
		explicit cCircle(const int& startx,const int& starty,const int& endx,const int& endy);

		/*
		
		*/
		cCircle(const RECT& rect);
		~cCircle();

		/*
		
		*/
		void SetCircleArea(const RECT& rect);

		/*
		
		*/
		void SetCircleArea(const int& startx, const int& starty, const int& endx, const int& endy);

		/*

		*/
		void SetHeight(const int& height);

		/*
		
		*/
		const int& GetHeight() const;

		/*
		
		*/
		void SetWidth(const int& w);

		/*
		
		*/
		const int& GetWidth() const;

		/*
		
		*/
		void SetLineColor(const UINT& rgb);

		/*
		
		*/
		const UINT& GetLineColor() const;

		/*
		
		*/
		void SetIsFill(bool&& ok);

		/*
		
		*/
		void SetIsFill(const bool& ok);

		/*
		
		*/
		const bool& GetIsFill() const;

		/*
		
		*/
		void SetFillColor(const UINT& rgb);

		/*
		
		*/
		const UINT& GetFillColor() const;

		/*
		
		*/
		void SetLineStyle(const UINT& style);

		/*
		
		*/
		const UINT& GetLineStyle(const UINT& style);

		/*
		GetRect()
		��ȡui�ؼ�һ����������
		@return RECT��
		ui�ؼ��ľ�������
		*/
		virtual const RECT&& GetRect() const override;

		/*
		Draw(HDC hDc)
		����ui�ؼ�
		@Param:
		HDC hDc:�豸DC
		*/
		virtual bool Draw(HDC hDc) override;
	private:
		int m_height;

		int m_width;

		UINT m_LineColor;

		bool m_isFill;

		UINT m_fillColor;

		UINT m_lineStyle;
	};
}

