#pragma once
#include"cBaseUI.h"

namespace MyEngine
{
	//��ť״̬ö��
	enum Btn_Status
	{
		Get_Focus,   //�õ�����
		Lost_Focus,   //ʧȥ����
		Mouse_Up,   //��갴��
		Mouse_Down,   //��굯��
	};

	/*
	cButton
	��ť
	*/
	class cButton :public cBaseUI
	{
	public:
		cButton();

		/*
		�вι��캯������ʼ����ť���ƺͿ���
		@Param:
			LPWSTR Name:��ť����
			int width:��ť����
			int height����ť�߶�
		*/
		explicit cButton(const LPWSTR& Name,const int& width,const int& height);

		/*
		�вι��캯������ͼƬ��ʼ����ť
		@Param LPWSTR��
			LPWSTR bmpPath:ͼƬ·��
		*/
		explicit cButton(const LPWSTR& bmpPath);

		/*
		�вι��캯������ͼƬ��ʼ����ť
		@Param LPWSTR��
			HBITMAP hbitmap:λͼ���
		*/
		explicit cButton(const HBITMAP& hbitmap);

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
		���ð�ť����
		@Param��
			int width����ť����
		*/
		void SetWidth(const int& width);

		/*
		GetWidth()
		��ȡ��ť����
		@return int��
			��ť����
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
		���ð�ť�߿����
		@Param��
			int n����ť�߿����
		*/
		void SetnBount(const int& n);

		/*
		GetBount()
		��ȡ��ť�߿����
		@return int��
			��ť�߿����
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
		virtual const RECT GetRect() const override;

		/*
		Draw(HDC hDc)
		����ui�ؼ�
		@Param:
			HDC hDc:�豸DC
		*/
		virtual bool Draw(HDC hDc) override;

		/*
		DrawNormal(HDC hDc)
		�����ޱ���ͼƬ�İ�ť
		@Param��
			HDC hDc�������豸DC
		*/
		bool DrawNormal(HDC hDc);

		/*
		DrawBitmapBtn
		���Ʊ���ͼƬ��ť
		@Param��
			HDC hDc�������豸DC
		*/
		bool DrawBitmapBtn(HDC hDc);

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

		/*
		ChangeColor()
		�ı䰴ť����ɫ,����ť�õ���ʧȥ����ʱ��ı䱳��ɫ
		@Param:
			BtnFocus focus����ť�õ���ʧȥ����
		*/
		void ChangeColor(Btn_Status focus);

		/*
		ChangeBountColor()
		����갴�º͵���ʱ�ı䰴ť�߿���ɫ
		@param��
			Btn_Status clicked:����Ƿ���
		*/
		void ChangeBountColor(Btn_Status clicked);

		/*
		SetBmpBtn(const LPWSTR& bmpPath)
		���ð�ť����ͼƬ
		@Param��
			LPWSTR bmpPath��ͼƬ·��
		*/
		void SetBmpBtn(const LPWSTR& bmpPath);

		/*
		SetBmpBtn(const HBITMAP& hbitmap)
		���ð�ť����ͼƬ
		@Param��
			HBITMAP hbitmap��λͼ���
		*/
		void SetBmpBtn(const HBITMAP& hbitmap);
	private:
		LPWSTR m_Name;

		int m_width;

		int m_height;

		//�߿����
		int m_nBount;

		UINT m_BountColor;

		UINT m_firstBountColor;

		UINT m_secBountColor;

		//��ťΪδ��ȡ�ý���ʱ�ı���ɫ
		UINT m_firstColor;

		//��ť��ȡ����ʱ�ı���ɫ
		UINT m_secondColor;

		LPWSTR m_font;

		UINT m_fontColor;

		UINT m_bgColor;

		HBITMAP m_bgBitmap;

		HFONT m_hFont;

		HPEN m_hPen;

		HBRUSH m_hBrush;
	};
}