#pragma once

class cIDDialogBase
{
public:
	cIDDialogBase();

	cIDDialogBase(const UINT& IDD, HINSTANCE hInst = NULL, HWND hPWnd=NULL);

	virtual ~cIDDialogBase();

	virtual void Show() = 0;

	/*
	*initDialog(const HWND& hWnd)
	*
	*��ʼ������״̬��Ϣ
	*
	*@Param��
	*	HWND hWnd�����ھ��
	*@return bool��
	*	true����ʼ���ɹ�
	*	false����ʼ��ʧ��
	*/
	virtual bool initDialog(HWND hWnd);
protected:
	UINT m_IDD;

	HINSTANCE m_hInst;

	HWND m_PhWnd;

	HWND m_hWnd;
};

