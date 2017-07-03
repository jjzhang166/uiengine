#pragma once
#include"cEyes.h"
#include<cAmination.h>


class cPlayer :public cEyes
{
public:
	cPlayer();
	
	/*
	�вι��캯������ʼ����������
	@Param��
		cAmination* correlationAmnation:������������Ķ���
	*/
	cPlayer(MyEngine::cAmination* correlationAmnation);

	virtual ~cPlayer();

	/*
	*Move()
	*
	*��������ƶ�����
	*
	*@return int��
	*/
	virtual int move(Dir_Type dir,bool b) override;

	/*
	SetSpeed()
	������������ٶ�
	@Param:
		int speed:��ҵ��ٶ�
	*/
	void SetSpeed(const int& speed);

	/*
	GetSpeed()
	��ȡ����ٶ�
	@return:
		����ٶ�
	*/
	const int& GetSpeed() const;
	
	/*
	SetcorrelationAmnation(cAmination* ami);
	�������ﶯ��
	@Param��
		cAmination* ami�������������
	*/
	void SetcorrelationAmnation(MyEngine::cAmination* ami);

	/*
	GetDir()
	��ȡ����
	@return Dir_Type��
		���﷽��
	*/
	const Dir_Type& GetDir() const override;
private:
	/*
	SetDir(Dir_Type dir)
	���÷���
	@Param��
	Dir_Type dir:����
	*/
	void SetDir(const Dir_Type& dir);

	int m_speed;

	MyEngine::cAmination* m_correlationAmnation;
};

