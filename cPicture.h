#pragma once
#include<string>
#include"cBaseUI.h"

namespace MyEngine
{

	class cPicture:public cBaseUI
	{
	public:
		cPicture();

		/*
		*�вι��캯��
		@Param:
			HBITMAP hBitmap:λͼ���
		*/
		explicit cPicture(const HBITMAP& hBitmap);

		/*
		�вι��캯��
		@Param��
			LPWSTR name��ͼƬ·����
			int w��ָ��ͼƬ���,w=0Ϊԭͼ���
			int h���ƶ�ͼƬ�߶ȣ�h=0ԭͼ�߶�
		*/
		explicit cPicture(const LPWSTR& name,int w=0,int h=0);
		
		~cPicture();

		/*
		GetRect()
		��ȡui�ؼ�һ����������
		@return RECT��
		ui�ؼ��ľ�������
		*/
		virtual const RECT&& GetRect() const  override;

		/*
		Draw(HDC hDc)
		����ui�ؼ�
		@Param:
		HDC hDc:�豸DC
		*/
		virtual bool Draw(HDC hDc) override;

		/*
		SetBitmap(const HBITMAP& hBitmap)
		ָ��һ��λͼ���
		@Param��
			HBITMAP hBitmap��Ϊͼ���
		*/
		void SetBitmap(const HBITMAP& hBitmap);

		/*
		SetBitmap(const LPWSTR& name,int w,int y)
		ͨ��һ��·������һ��λͼ
		@Param��
			LPWSTR name:ͼƬ·����
			int w��ָ��ͼƬ��ȣ�w=0ԭͼ���
			int h���ƶ�ͼƬ�߶ȣ�h=0ԭͼ�߶�
		*/
		void SetBitmap(const LPWSTR& name, int  w = 0, int  h = 0);

		/*
		GetBitmap()
		��ȡͼƬ���
		@return
			ͼƬ���
		*/
		const HBITMAP& GetBitmap() const;
	private:
		/*
		SetPicConfig()
		����ͼƬ��Ϣ
		*/
		void SetPicConfig();

		HBITMAP m_hBitmap;

		BOOL m_isLucency;

		UINT m_licencyRgb;

		BITMAP m_bmpConfig;
	};
}

