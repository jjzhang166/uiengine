#pragma once
#include"cBaseUI.h"

namespace MyEngine
{

	class cButton :public cBaseUI
	{
	public:
		cButton();

		/*
		�вι��캯��
		@Param:
			int width:��ť���
			int height����ť�߶�
		*/
		explicit cButton(const LPWSTR& Name,const int& width,const int& height);

		virtual ~cButton();

		/*
		SetName()
		���ð�ť����
		@Param��
			LPWSTR name:��ť��
		*/
		void SetName(const LPWSTR& Name);

		/*
		GetName()
		��ȡ��ť��
		@return LPWSTR��
			��ť��
		*/
		const LPWSTR& GetName() const;

		/*
		SetWidth(const int& width)
		���ð�ť���
		@Param��
			int width����ť���
		*/
		void SetWidth(const int& width);

		/*
		GetWidth()
		��ȡ��ť���
		@return int��
			��ť���
		*/
		const int& GetWidth() const;

		/*
		SetHeight(const int& height)
		���ð�ť�߶�
		@Param��
			int height����ť�߶�
		*/
		void SetHeight(const int& Height);

		/*
		GetHeight()
		��ȡ��ť�߶�
		@return int��
			��ť�߶�
		*/
		const int& GetHeight() const;

		/*
		SetBount(const int& n)
		���ð�ť�߿���
		@Param��
			int n����ť�߿���
		*/
		void SetnBount(const int& n);

		/*
		GetBount()
		��ȡ��ť�߿���
		@return int��
			��ť�߿���
		*/
		const int& GetBount() const;

		/*
		SetBountColor(const UINT& rgb)
		���ñ߿���ɫ
		@Param��
			UINT rgb���߿���ɫ
		*/
		void SetBountColor(const UINT& rgb);

		/*
		GetBountColor()
		��ȡ��ť�߿���ɫ
		@return UINT��
			��ť�߿���ɫ
		*/
		const UINT& GetBountColor() const;

		/*
		SetFirstColor(const UINT& rgb)
		���ð�ť��һ��ɫ
		@Param:
			UINT rgb:RGBɫ
		*/
		void SetfirstColor(const UINT& rgb);

		/*
		GetFirstColor()
		��ȡ��ť��һ��ɫ
		@return UINT:
			��ť��һ��ɫ
		*/
		const UINT& GetfirstColor() const;

		/*
		SetSecondColor(const UINT& rgb)
		���õڶ���ɫ
		@Param��
			UINT rgb��RGBɫ
		*/
		void SetsecondColor(const UINT& rgb);

		/*
		GetsecondColor()
		��ȡ��ť�ڶ���ɫ
		@return UINT��
			��ť�ڶ���ɫ
		*/
		const UINT& GetsecondColor() const;

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

		/*
		SetFont(const LPWSTR& font);
		��������
		@Param��
			LPWSTR font������
		*/
		void SetFont(const LPWSTR& font);

		/*
		GetFont()
		��ȡ��ť�ı�����
		@return LPWSTR��
			��ť�ı�����
		*/
		const LPWSTR& GetFont() const;

		/*
		SetFontColor()
		����������ɫ
		@Param��
			UINT rgb��rgbɫ
		*/
		void SetFontColor(const UINT& rgb);

		/*
		GetFontColor()
		��ȡ������ɫ
		@return UINT��
			������ɫ
		*/
		const UINT& GetFontColor() const;
	private:
		LPWSTR m_Name;

		int m_width;

		int m_height;

		//�߿���
		int m_nBount;

		UINT m_BountColor;

		//��һǰ��ɫ
		UINT m_firstColor;

		//�ڶ�ǰ��ɫ
		UINT m_secondColor;

		LPWSTR m_font;

		UINT m_fontColor;
	};
}

