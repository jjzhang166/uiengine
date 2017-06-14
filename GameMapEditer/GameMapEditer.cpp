// GameMapEditer.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "GameMapEditer.h"
#include"cSelectRowRank.h"
#include<commdlg.h>
#include"cMapEditer.h"
#include"../UIEngine/Tool.h"

#define MAX_LOADSTRING 100

// ȫ�ֱ���: 
HINSTANCE hInst;                                // ��ǰʵ��
WCHAR szTitle[MAX_LOADSTRING];                  // �������ı�
WCHAR szWindowClass[MAX_LOADSTRING];            // ����������
cMapEditer *g_pMapEditer;

// �˴���ģ���а����ĺ�����ǰ������: 
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: �ڴ˷��ô��롣

    // ��ʼ��ȫ���ַ���
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_GAMEMAPEDITER, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ִ��Ӧ�ó����ʼ��: 
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GAMEMAPEDITER));

    MSG msg;

    // ����Ϣѭ��: 
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

	delete g_pMapEditer;
	g_pMapEditer = nullptr;
    return (int) msg.wParam;
}



//
//  ����: MyRegisterClass()
//
//  Ŀ��: ע�ᴰ���ࡣ
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GAMEMAPEDITER));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_GAMEMAPEDITER);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ����: InitInstance(HINSTANCE, int)
//
//   Ŀ��: ����ʵ�����������������
//
//   ע��: 
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
	   0,0,800,600, nullptr, nullptr, hInstance, nullptr);
   
   if (!hWnd)
   {
	   return FALSE;
   }
   g_pMapEditer = new cMapEditer(hWnd);
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ����: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��:    ���������ڵ���Ϣ��
//
//  WM_COMMAND  - ����Ӧ�ó���˵�
//  WM_PAINT    - ����������
//  WM_DESTROY  - �����˳���Ϣ������
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_LBUTTONDOWN:
		g_pMapEditer->MouseDown();
		break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // �����˵�ѡ��: 
            switch (wmId)
            {
			case IDM_IMPORT:
			{
				OPENFILENAME ofn = { 0 };
				TCHAR strFilename[MAX_PATH] = { 0 };    //���ڽ����ļ���  
				ofn.lStructSize = sizeof(OPENFILENAME);   //�ṹ���С  
				ofn.hwndOwner = NULL;   //ӵ���Ŵ��ھ����ΪNULL��ʾ�Ի����Ƿ�ģ̬�ģ�ʵ��Ӧ����һ�㶼Ҫ��������  
				ofn.lpstrFilter = TEXT("�����ļ�\0*.*\0txt�ļ�\0*.txt\0\0");//���ù���  
				ofn.nFilterIndex = 1;   //����������  
				ofn.lpstrFile = strFilename;   //���շ��ص��ļ�����ע���һ���ַ���ҪΪNULL  
				ofn.nMaxFile = sizeof(strFilename);   //����������  
				ofn.lpstrInitialDir = NULL;  //��ʼĿ¼ΪĬ��  
				ofn.lpstrTitle = TEXT("��ѡ��һ���ļ�");  //ʹ��ϵͳĬ�ϱ������ռ���  
				ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;//�ļ���
				if (GetOpenFileName(&ofn))
				{
					g_pMapEditer->FromFileLoadMapConfig(strFilename);
				}
			}
				break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
			case IDM_SAVE:
			{
				OPENFILENAME ofn = { 0 };
				TCHAR strFilename[MAX_PATH] = { 0 };//���ڽ����ļ���  
				ofn.lStructSize = sizeof(OPENFILENAME);//�ṹ���С  
				ofn.hwndOwner = NULL;//ӵ���Ŵ��ھ����ΪNULL��ʾ�Ի����Ƿ�ģ̬�ģ�ʵ��Ӧ����һ�㶼Ҫ��������  
				ofn.lpstrFilter = TEXT("�����ļ�\0*.*\0txt�ļ�\0*.txt\0\0");//���ù���  
				ofn.nFilterIndex = 1;//����������  
				ofn.lpstrFile = strFilename;//���շ��ص��ļ�����ע���һ���ַ���ҪΪNULL  
				ofn.nMaxFile = sizeof(strFilename);//����������  
				ofn.lpstrInitialDir = NULL;//��ʼĿ¼ΪĬ��  
				ofn.Flags = OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;//Ŀ¼������ڣ������ļ�ǰ��������  
				ofn.lpstrTitle = TEXT("���浽");//ʹ��ϵͳĬ�ϱ������ռ���  
				ofn.lpstrDefExt = TEXT("txt");//Ĭ��׷�ӵ���չ��  
				if (GetSaveFileName(&ofn))
				{
					MessageBox(NULL, L"����ɹ�",L"", MB_OK);
					g_pMapEditer->SaveMapFile(strFilename);
				}
				else
				{
					MessageBox(NULL, L"����ʧ��", L"", MB_OK);
				}
			}
				break;
			case IDM_OPEN:
			{
				OPENFILENAME ofn = { 0 };
				TCHAR strFilename[MAX_PATH] = { 0 };    //���ڽ����ļ���  
				ofn.lStructSize = sizeof(OPENFILENAME);   //�ṹ���С  
				ofn.hwndOwner = NULL;   //ӵ���Ŵ��ھ����ΪNULL��ʾ�Ի����Ƿ�ģ̬�ģ�ʵ��Ӧ����һ�㶼Ҫ��������  
				ofn.lpstrFilter = TEXT("bmp�ļ�\0*.bmp\0\0");//���ù���  
				ofn.nFilterIndex = 1;   //����������  
				ofn.lpstrFile = strFilename;   //���շ��ص��ļ�����ע���һ���ַ���ҪΪNULL  
				ofn.nMaxFile = sizeof(strFilename);   //����������  
				ofn.lpstrInitialDir = NULL;  //��ʼĿ¼ΪĬ��  
				ofn.lpstrTitle = TEXT("��ѡ��һ���ļ�");  //ʹ��ϵͳĬ�ϱ������ռ���  
				ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;//�ļ���
				if (GetOpenFileName(&ofn))
				{
					if (lstrcmpW(strFilename, L"") != 0)
					{
						g_pMapEditer->LoadMapResource(strFilename);
					}
				}
			}
				break;
			case IDM_SROWANDRANK:
			{
				cSelectRowRank dia(IDD_SROWANDRANK, hInst, hWnd);
				dia.Show();
				if (dia.GetStatus() == Quit_OK)
				{
					g_pMapEditer->SetRowAndRabk(dia.GetRow(), dia.GetRank(), dia.GetTerrianSpecies());
				}
			}
				break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: �ڴ˴����ʹ�� hdc ���κλ�ͼ����...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// �����ڡ������Ϣ�������
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}