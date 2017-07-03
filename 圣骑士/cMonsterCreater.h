#pragma once
#include"cMonster.h"
#include"cMonsterAma.h"
#include"cMonsterBull.h"
#include"cMonsterQiu.h"
#include"cMonsterStar.h"
#include<cAmination.h>

static class cMonsterCreater
{
public:
	cMonsterCreater();
	~cMonsterCreater();

	/*
	CreateMonsterStar(tagPOINT pt,MyEngine::cAmination corretionAmination);
	�����������
	@Param��
		tagPOINT pt������λ��
		cAmination corretionAmination�����������Ķ�ͼ
	@return cMonster*��
		����Ĺ������ָ��
	*/
	cMonster* CreateMonsterStar(const tagPOINT& pt,MyEngine::cAmination* corretionAmination);

	/*
	CreateMonsterBull(tagPOINT pt, MyEngine::cAmination corretionAmination);
	�������﹫ţ
	@Param��
		tagPOINT pt������λ��
		cAmination corretionAmination�����������Ķ�ͼ
	@return cMonster*��
		����Ĺ������ָ��
	*/
	cMonster* CreateMonsterBull(const tagPOINT& pt, MyEngine::cAmination* corretionAmination);

	/*
	CreateMonsterQiu(const tagPOINT& pt, MyEngine::cAmination* corretionAmination);
	�����������
	@Param��
		tagPOINT pt������λ��
		cAmination corretionAmination�����������Ķ�ͼ
	@return cMonster*��
		����Ĺ������ָ��
	*/
	cMonster* CreateMonsterQiu(const tagPOINT& pt, MyEngine::cAmination* corretionAmination);

	/*
	CreateMonsterAma(const tagPOINT& pt, MyEngine::cAmination* corretionAmination);
	�����������
	@Param��
		tagPOINT pt������λ��
		cAmination corretionAmination�����������Ķ�ͼ
	@return cMonster*��
		����Ĺ������ָ��
	*/
	cMonster* CreateMonsterAma(const tagPOINT& pt, MyEngine::cAmination* corretionAmination);
};

