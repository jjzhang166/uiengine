#pragma once

namespace MyEngine
{

	class cBaseUI
	{
	public:
		cBaseUI();
		/*
		�вι��캯��
		@Param :
			int x��ui�ؼ�x����
			int y : ui�ؼ�y����
		*/
		explicit cBaseUI(const int& x, const int& y);
		virtual ~cBaseUI();

		/*
		SetX(const int& x);
		����ui�ؼ�x����
		@Param ��
			int x���µ�x����
		*/
		void SetX(const int& x);

		/*
		GetX()
		��ȡui�ؼ�x����
		@return const int&:
			ui�ؼ���ǰx����
		*/
		const int& GetX() const;

		/*
		SetY(const int& y)
		����ui�ؼ�y����
		@Param ��
			int y:�µ�y����
		*/
		void SetY(const int& y);

		/*
		GetY()
		��ȡui�ؼ���ǰy����
		@return int��
			��ǰy����
		*/
		const int& GetY() const;

		/*
		GetRect()
		��ȡui�ؼ�һ����������
		@return RECT��
			ui�ؼ��ľ�������
		*/
		virtual const RECT&& GetRect() const=0;

		/*
		Draw(HDC hDc)
		����ui�ؼ�
		@Param:
			HDC hDc:�豸DC
		*/
		virtual bool Draw(HDC hDc) = 0;
	private:
		int m_x;
		int m_y;
	};
}