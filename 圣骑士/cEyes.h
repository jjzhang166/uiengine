#pragma once

enum Eyes_Type
{
	Type_Eyes,
	Type_Player,
	Type_Npc,
	Tyep_Monster,
};

enum Dir_Type
{
	Dir_Left,
	Dir_Right,
	Dir_Up,
	Dir_Down,
};


class cEyes
{
public:
	cEyes();
	virtual ~cEyes();

	/*
	*SetPos(const tagPOINT& pos)
	*
	*���õ�ǰλ��
	*
	*@Param:
	*	tagPOINT pos�����õĵ�ǰλ��
	*/
	virtual void SetPos(const tagPOINT& pos);

	/*
	*SetPos(const tagPOINT&& pos)
	*
	*�ƶ������SetPos()
	*/
	virtual void SetPos(const tagPOINT&& pos);

	/*
	*GetPos()
	*
	*��ȡ��ǰλ��
	*
	*@return tagPOINT��
	* ��ǰλ��
	*/
	virtual const tagPOINT& GetPos() const;

	/*
	*Move()
	*
	*��������ƶ�
	*
	*@return int:
	* ��������������η���
	*/
	virtual int move(Dir_Type dir,bool b) = 0;

	/*
	*SetLife(const int& life);
	*
	*��������ֵ
	*
	*@Param��
	*	int life���µ�����ֵ
	*/
	virtual void SetLife(const int& life);

	/*
	*SetLife(const int&& life);
	*
	*�ƶ������SetLife()
	*
	*@Param��
	* int life:�µ�����ֵ
	*/
	virtual void SetLife(const int&& life);

	/*
	*GetLife()
	*
	*��ȡ��ǰ����ֵ
	*
	*@return int��
	*	��ǰ������ֵ
	*/
	virtual const int& GetLife() const;

	/*
	*SetFps(const unsigned& fps);
	*
	*����֡��
	*
	*@Param��
	*	unsigned fps��֡��
	*/
	virtual void SetFps(const unsigned& fps);

	/*
	*SetFps(const unsigned&& fps);
	*
	*�ƶ������SetFps����
	*/
	virtual void SetFps(const unsigned&& fps);

	/*
	*GetFps() 
	*
	*��ȡ֡��
	*
	*@return unsigned��
	*	֡��
	*/
	virtual const unsigned& GetFps() const;

	/*
	*SetMaxFps(const unsigned& fps);
	*
	*�������֡��
	*
	*@Param��
	*	unsigned fps�����֡��
	*/
	virtual void SetMaxFps(const unsigned& fps);

	/*
	*SetMaxFps(const unsigned&& fps);
	*
	*�ƶ������SetMaxFps����
	*/
	virtual void SetMaxFps(const unsigned&& fps);

	/*
	*GetMaxFps()
	*
	*��ȡ���֡��
	*
	*@return unsigned��
	*	���֡��
	*/
	virtual const unsigned& GetMaxFps() const;

	/*
	*GetType()
	*
	*��ȡ��������
	*
	*@return Eyes_Type:
	*	��������
	*/
	virtual const Eyes_Type& GetType();

	/*
	GetDir()
	��ȡ����
	@return Dir_Type��
		���巽��
	*/
	virtual const Dir_Type& GetDir() const;
protected:
	//��ǰλ��
	tagPOINT m_pos;

	//����ֵ
	int m_life;

	//֡��
	unsigned m_fps;

	//���֡��
	unsigned m_maxFps;

	Eyes_Type m_type;

	Dir_Type m_dir;
};

