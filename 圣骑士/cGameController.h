#pragma once
#include"cMusicPlayer.h"
#include"../UIEngine/cGameEngine.h"
#include"cMap.h"
#include<map>

using namespace MyEngine;

enum EntryStatus
{
	Null_Entry,
	Menu_Entry,
	ReadFile_Entry,
	Game_Entry
};

enum MapScene
{
	Map_Censorship1,
	Map_Censorship2,
	Map_Censorship3,
	Map_Censorship4,
};

typedef struct RowRankInfo
{
	int row;
	int rank;

	bool operator <(const RowRankInfo& info) const
	{
		return row *rank < info.row*info.rank;
	}
}tagRowRankInfo;

class cGameController :public cMyTimer
{
	const int CLIENTX = 900;
	const int CLIENTY = 600;
	const int PANESIZE = 50;

public:
	enum  Time_Type
	{
		Time_Draw,
	};

public:
	cGameController();

	virtual ~cGameController();

	/*
	*OnTimer(int id,int iParam,string str);
	*
	*��cMyTimer�̳ж����Ķ�ʱ��������ص�����
	*
	*@Param :
	*	int id:��ʱ��id
	*	int iParam����ʱ��Ԥ������
	*	string str����ʱ������
	*
	*@return int��
	*	����ֵΪ0ʱ��ʾɾ���ö�ʱ��
	*/
	virtual int OnTimer(int id, int iParam, string str) override;

	/*
	*StartGame(HWND hWnd);
	*
	*��ʼ��Ϸ
	*
	*@Param��
	*	HWND hWnd����Ϸ���ھ��
	*/
	void StartGame(const HWND& hWnd);

	/*
	*LButtonDown()
	*
	*������갴��
	*/
	void LButtonDown();

	/*
	*LButtonUp()
	*
	*����������
	*/
	void LButtonUp();

	/*
	*RButtonDown()
	*
	*����Ҽ�����
	*/
	void RButtonDown();

	/*
	*RButtonUp()
	*
	*����Ҽ�����
	*/
	void RButtonUp();

	/*
	*KeyDown(LPARAM lParam)
	*
	*���̰�����Ϣ
	*@Param:
	*	LPARAM lParam:�¼���ϸ��Ϣ
	*/
	void KeyDown(LPARAM lParam);

	/*
	*KeyUp(LPARAM wParam)
	*
	*���̵�����Ϣ
	*
	*@Param��
	*	LPARAM lParam���¼���ϸ��Ϣ
	*/
	void KeyUp(LPARAM lParam);

	/*
	GetUIEngine()
	��ȡUI�������ָ��
	@return cGameEngine*��
		UI�������ָ��
	*/
	cGameEngine* GetUIEngine();

	/*
	EntryGame(EntryStatus entry)
	��ʽ������Ϸ
	@Param:
		EntryStatus entry�������ҳ�����һ��ҳ��
	*/
	void EntryGame(EntryStatus entry);

	/*
	EntrySelectView()
	����ѡ����ͼ
	@Param:
		EntryStatus entry�������ҳ�����һ��ҳ��
	*/
	void EntrySelectView(EntryStatus entry);

	/*
	EntryReadFileView
	�����ȡ�浵����
	@Param:
		EntryStatus entry�������ҳ�����һ��ҳ��
	*/
	void EntryReadFileView(const EntryStatus& entry);

	/*
	LoadMap(MapScene scene)
	���ص�ͼ
	@Param:
		MapScene scene��Ҫ���صĵ�ͼ����
	*/
	bool LoadMap(MapScene scene);
private:
	/*
	ReleaseLastViewResource(const EntryStatus& status);
	�ͷ���һ���������Դ
	@Param��
		EntryStatus status����ʶ��һ������
	@return BOOL��
		TRUE���ͷųɹ�
		FALSE���ͷ�ʧ��
	*/
    bool ReleaseLastViewResource(const EntryStatus& status);

	/*
	CreateMapResource();
	������ͼ��Դ
	*/
	void CreateMapResource();

	/*
	ReleaseMapResource()
	�ͷŵ�ͼ��Դ
	@return BOOL��
		TRUE���ͷųɹ�
		FALSE���ͷ�ʧ��
	*/
	bool ReleaseMapResource();

	cMusicPlayer m_GameMusic;

	bool m_IsOpenMusic;

	unsigned m_gameVolume;

    cGameEngine* m_pUI;

	cMap m_mapInfo;

	cPicture* m_mapBg;

	std::list<cBaseUI*> m_MenuList;

	std::list<cBaseUI*> m_ReadFileList;

	//�����ͼ��Դ�б�
	std::map<RowRankInfo, cBaseUI*> m_MapResource;
};

