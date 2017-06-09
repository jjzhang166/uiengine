#pragma once
#include<vector>
#include<initializer_list>
#include<string>
#include"cBaseUI.h"

namespace MyEngine
{

	class cAmination:public cBaseUI
	{
	public:
		cAmination();

		/*
		
		*/
		explicit cAmination(const std::initializer_list<LPWSTR>& initlist,int x=0,int y=0);
		
		~cAmination();

		/*
		
		*/
		void SetAmination(const std::initializer_list<PWSTR>& initlist,int x=0,int y=0);

		/*
		
		*/
		const std::vector<HBITMAP>& GetAmination() const;

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
		virtual bool Draw(HDC hDc)  override;
	private:
		void SetAmiConfig();
		std::vector<HBITMAP> m_Amination;
		BOOL m_isLucency;
		UINT m_lucencyRgb;
		BITMAP m_amiConfig;
	};
}

