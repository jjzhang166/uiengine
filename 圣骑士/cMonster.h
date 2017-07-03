#pragma once
#include"cEyes.h"
#include"../UIEngine/cAmination.h"

class cMonster:public cEyes 
{
public:
	cMonster();

	~cMonster();
	
	/*
	SetSpeed(const int& speed);
	���ù����ٶ�
	@Param��
		int speed:�����ٶ�
	*/
	void SetSpeed(const int& speed);

	/*
	GetSpeed();
	��ȡ�����ٶ�
	@return int��
		�����ٶ�
	*/
	const int& GetSpeed() const;

	/*
	Move(Dir_Type dir,bool b)
	�ƶ�����
	@Param
		Dir_Type dir���ƶ�����
		bool b���Ƿ��ƶ�
	*/
	virtual int move(Dir_Type dir, bool b)  override;
private:
	int m_speed;
};

