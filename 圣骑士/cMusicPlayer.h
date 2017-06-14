#pragma once
#include<list>

class cMusicPlayer
{
	enum Time_Type
	{
		Time_Check,
	};

public:
	cMusicPlayer();
	virtual ~cMusicPlayer();

	/*
	*PlayBgSound(const LPWSTR& path)
	*
	*�������ֱ�������
	*
	*@param��
	*	LPWSTR path����Ƶ·��
	*@return int��
	*	0�����ųɹ�
	*	-1������ʧ��
	*/
    int PlayBgSound(const LPWSTR& path);

	/*
	*StopBgSound()
	*
	*ֹͣ���ű�������
	*
	*@return int��
	*	0��ֹͣ�ɹ�
	*	-1��ֹͣʧ��
	*/
	int StopBgSound();

	/*
	*PauseBgSound()
	*
	*��ͣ���ű�������
	*
	*@return int��
	*	0����ͣ�ɹ�
	*	-1����ͣʧ��
	*/
	int PauseBgSound();

	/*
	*RePlayBgSound()
	*
	*���²��ű�������
	*
	*@return int��
	*	0�����²��ųɹ�
	*	-1�����²���ʧ��
	*/
	int RePlayBgSound();

	/*
	*AddEffectsSound()
	*
	*�����Ч����
	*
	*@Param:
	*	LPWSTR path:����·��
	*/
	void AddEffectsSound(const LPWSTR& path);

	/*
	*PlayEffectsSound()
	*
	*������Ч����
	*/
	void PlayEffectsSound();

	/*
	*StopEffectsSound()
	*
	*�ر���Ч����
	*/
	void StopEffectsSound();

	/*
	*SetMusicVolume(const UINT& value)
	*
	*������������
	*
	*@Param��
	*	UINT value��������С����ֵӦ��0~1000֮��
	*@return int:
	*	0:���óɹ�
	*	-1������ʧ��
	*/
	int SetMusicVolume(UINT value);

	/*
	*GetBgMusicAllTime()
	*
	*��ȡ���������ܵĲ���ʱ��
	*
	*@return DWORD
	*	����������ʱ��������
	*/
	DWORD GetBgMusicAllTime();

	/*
	*GetBgMusicCurTime();
	*
	*��ȡ�������ֵ�ǰ����ʱ��
	*
	*@return DWORD��
	*	��ǰ����ʱ��
	*/
	DWORD GetBgMusicCurTime();

	/*
	*bool JumpBgMusicTo(const UINT& percent)
	*
	*��������������ָ���ٷֱ�������
	*
	*@Param��
	*	UINT percent��ָ���İٷֱ�,��ֵӦΪ0~100
	*/
	bool JumpBgMusicTo(const UINT& percent);

	/*
	*isPlaying()
	*
	*�ж��Ƿ��������ڲ���
	*
	*@return bool��
	*	true�����������ڲ���
	*	false��û���������ڲ���
	*/
	bool isPlaying();
private:
	DWORD m_BgSoundId;

	std::list<LPWSTR> m_listEffectsMusic;

	std::list<DWORD> m_listEffectsId;
};

