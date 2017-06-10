#pragma once
#include<list>
#include<vector>
#include"cMyTimer.h"
#include"cText.h"
#include"cButton.h"
#include"cPicture.h"
#include"cAmination.h"
#include"cTriangle.h"
#include"cLine.h"
#include"cRectangle.h"
#include"cCircle.h"
#include"cPolygon.h"

namespace MyEngine
{
	typedef void(*CallEeventBack)(void *param);

	typedef struct _UI_Event
	{
		cBaseUI* controller;
	 	UINT_PTR EventId;
		CallEeventBack CallProc;
	}UI_Event;

	class cGameEngine :public cMyTimer
	{
	public:
		explicit cGameEngine(HWND hWnd);
		~cGameEngine();

		/*
		OnTimer(int id,int iParam,string str)
		����ʱ����Ϣ�ص�����
		@Param
			int id:�ص���ʱ��id
			int iParam:��ʱ�����Ӳ���
			string str����ʱ������
		@return int��
			0����ʾ�ö�ʱ������ɾ��
		*/
		virtual int OnTimer(int id, int iParam, string str);

		/*
		CenterWindow()
		���ͻ����ھ���
		@return int��
			0���ɹ�����
			-1������ʧ��
		*/
		int CenterWindow();

		/*
		GetLastError()
		��ȡ��һ�δ�����Ϣ
		@return const LPWSTR&:
			������Ϣ��
		*/
		const LPWSTR& GetLastError() const;

		/*
		CreateText(const LPWSTR& text,const int& x,const int& y)
		����һ��Text�ı�
		@Param
			LPWSTR text:�ı�����
			int x:�ı�x����
			int y:�ı�y����
		@return cText��
			�ɹ��򷵻ش������ı�ָ�룬ʧ���򷵻�nullptr
		*/
		cText* CreateText(const LPWSTR& text, const int& x , const int& y );

		/*
		CreateLine(const POINT& start,const POINT& end)
		����һ��ֱ��
		@Param��
			POINT start��ֱ�����
			POINT end��ֱ���յ�
		@return cLine*:
			������ֱ�߶���ָ��
		*/
		cLine* CreateLine(const POINT& start, const POINT& end);

		/*
		CreateButton(const LPWSTR& Name,cosnt int& x,const int& y)
		����һ����ť
		@Param��
			LPWSTR Name:��ť��
			int x:��ťx����
			int y����ťy����
		@return cButton*��
			�����İ�ť����ָ��
		*/
		cButton* CreateButton(const LPWSTR& Name, const int& x, const int& y);

		/*
		CreateBitmapButton(const LPWSTR& bmpPath,const int& x,const int& y)
		����ͼƬ��ť
		@Param:
			LPWSTR bmpPath��λͼ��Դ·��
			int x:��ťx����
			int y:��ťy����
		@return��
			�����İ�ť����ָ��
		*/
		cButton* CreateBitmapButton(const LPWSTR& bmpPath,const int& x,const int& y);

		/*
		CreateBitmapButton(const HBITMAP& hbitmap,const int& x,const int& y)
		����ͼƬ��ť
		@Param:
			HBITMAP hbitmap��λͼ��Դ���
			int x:��ťx����
			int y:��ťy����
		@return��
			�����İ�ť����ָ��
		*/
		cButton* CreateBitmapButton(const HBITMAP& bitmap,const int& x,const int& y);

		/*
		CreateCircle(const RECT& rect)
		����һ��Բ
		@Param��
			RECT rect����Բ����Ӿ���
		@return cCircle*��
			������Բ����ָ��
		*/
		cCircle* CreateCircle(const RECT& rect);

		/*
		CreatePicture(const LPWSTR& name,const int& x,const int& y)
		����һ��ͼƬ
		@Param:
			LPWSTR Name��ͼƬ·����
			int x��ͼƬx����
			int y��ͼƬy����
		@return cPicture*��
			������ͼƬ����ָ��
		*/
		cPicture* CreatePicture(const LPWSTR& name, const int& x, const int& y);

		/*
		CreatePicture(const HBITMAP& bitmap,const int& x,const int& y)
		����һ��ͼƬ
		@Param:
			HBITMAP bitmap��λͼ���
			int x��ͼƬx����
			int y��ͼƬy����
		@return cPicture*��
			������ͼƬ����ָ��
		*/
		cPicture* CreatePicture(const HBITMAP& bitmap,const int& x,const int& y);

		/*
		CreateRectangle(const RECT& rect)
		����һ������
		@Param��
			RECT rect�������ľ�������
		@return cRectangle*��
			�����ľ��ζ���ָ��
		*/
		cRectangle* CreateRectangle(const RECT& rect);

		/*
		CreateTriangle(const POINT& p1,const POINT& p2,const POINT p3)
		����һ��������
		@Param��
			POINT p1:���������еĵ�һ����
			POINT p2�����������εĵڶ�����
			POINT p3�����������εĵ�������
		@return cTriangle*��
			�����������ζ���ָ��
		*/
		cTriangle* CreateTriangle(const POINT& p1, const POINT& p2, const POINT& p3);

		/*
		CreatePolygon(std::initializer_list<POINT> pointList)
		����һ�������
		@Param��
			initializer_list<POINT> pointList:���ɶ���εĻ������б�
		@return cPolygon*��
			�����Ķ���ζ���ָ��
		*/
		cPolygon* CreatePolygon(std::initializer_list<POINT> pointList);

		/*
		CreateAmination(const std::initializer_list<LPWSTR>& pathList,const int& x,const int& y)
		����������Դ
		@Param��
			std::initializer_list pathList��������Դ·�����б�
			int x������x����
			int y������y����
		@return cAmination*:
			��������ָ��
		*/
		cAmination *CreateAmination(const std::initializer_list<LPWSTR>& pathList, const int &x, const int& y);

		/*
		AddEventToUI(const cBaseUI* ui,UINT_PTR eventIdCallEventBack callBack)
		ΪUI�ؼ�����¼�������
		@Param��
			cBaseUI* ui����Ҫ����¼������ui�ؼ�
			CallEventBack callBack:�¼�����ص�����
		*/
		void AddEventToUi(cBaseUI* ui,UINT_PTR eventId, CallEeventBack callBack);

		/*
		int DeleteUI(cBaseUI *pDel);
		ɾ��ָ��ui�ؼ�
		@Param :
			pDel��ָ��Ҫɾ����ui�ؼ���ָ��
		@return int��
			0��δ�ҵ�ɾ����
			1��ɾ���ɹ�
		*/
		int DeleteUI(cBaseUI* pDel);

		/*
		DrawUI();
		 ����UI����
		*/
		void DrawUI();

		/*
		DoMouseMsg()
		���������Ϣ
		@Param��
			WPARAM wParam�������Ϣ��ϸ��Ϣ
		*/
		void DoMouseMsg(WPARAM wParam);

		/*
		DoKeyDownMsg(LPARAM lParam)
		������̰���������Ϣ
		@Param��
			LPARAM lParam����Ϣ����ϸ��Ϣ
		*/
		void DoKeyDownMsg(LPARAM lParam);

		/*
		DoKeyDownMsg(LPARAM lParam)
		������̰���������Ϣ
		@Param��
			LPARAM lParam����Ϣ����ϸ��Ϣ
		*/
		void DoKeyUpMsg(LPARAM lParam);

		/*
		CheckButtonGetOrLostFocus()
		��ⰴťʧȥ��õ�����
		*/
		void CheckButtonGetOrLostFocus();

		/*
		CheckButtonClick(const Btn_Status clicked)
		��ⰴť�Ƿ񱻵��
		@Param��
			Btn_Status clicked����ť�Ƿ񱻵��
		*/
		void CheckButtonClick(const Btn_Status& clicked);

		/*
		DoUiKeyEvent(const UINT_PTR& eventId)
		����ui�ؼ������¼�
		@Param��
			UINT_PTR eventId���¼�id
		*/
		void DoUiKeyEvent(const UINT_PTR& eventId);

		/*
		DoUiMouseEvent(const UINT_PTR& eventId)
		����ui�ؼ�����¼�
		@Param:
			UINT_PTR eventId���¼�id
		*/
		void DoUiMouseEvent(const UINT_PTR& eventId);

		/*
		GethWnd()
		��ȡ�󶨵Ĵ��ھ��
		@return HWND��
			���ھ��
		*/
		HWND GethWnd() const;

		void SethWnd(HWND hWnd);
	private:
		HWND m_hWnd;

		//������Ϣ
		LPWSTR m_wError;

		//����UI�ؼ��б�
		std::list<cBaseUI*> m_uiList;

		std::vector<cButton*> m_buttonList;

		std::list<UI_Event> m_evnetList;
	};
}