#pragma once
#include"cEyes.h"
#include<cAmination.h>

class cPlayer :public cEyes
{
public:
	cPlayer();
	virtual ~cPlayer();

	/*
	*Move()
	*
	*��������ƶ�����
	*
	*@return int��
	*/
	virtual int move() override;
private:

};

