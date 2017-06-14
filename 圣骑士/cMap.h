#pragma once
#include<string>

enum Map_type
{
	Type_Null,
	Type_Brick,
	Type_Steel,
	Type_Box,
	Type_Door,
	Type_Born,
	Type_Box1,
	Type_Box2,
	Type_Energy,
};

/*
*cMap
*
*��Ϸ��ͼ�����ڱ����ͼ��Ϣ
*/
class cMap
{
public:
	cMap();

	/*
	*�вι��캯��
	*
	*@Param��
	*	int row����ͼ����
	*	int rank����ͼ����
	*/
	cMap(const int& row, const int& rank);

	virtual ~cMap();

	/*
	*SetMap(const int& row,const int& rank);
	*
	*���õ�ͼ��������
	*
	*@Param��
	*	int row����ͼ����
	*	int rank����ͼ����
	*/
	void SetMap(const int& row, const int& rank);

	/*
	*at(const int& x,const int& y)
	*
	*��ȡ��ͼ��ĳ���е���Ϣ
	*
	*@return int:
	*	�ڸ����еĵ�ͼ��Ϣ
	*/
    Map_type& at(const int& row, const int& rank);

	/*
	*SetMapInfoAt(const int& row,const int& rank,Map_Type type)
	*
	*����ĳ���еĵ�ͼ��Ϣ
	*
	*@Param:
	*	int row:��
	*	int rank����
	*	Map_Type type����ǰ�еĵ�ͼ��Ϣ
	*/
	void SetMapInfoAt(const int& row, const int& rank, Map_type type);

	/*
	*LoadMapFromFile(const LPWSTR& fileName);
	*
	*���ļ��м��ص�ͼ��Ϣ
	*
	*@Param:
	*	LPWSTR fileName:�ļ���
	*@return bool:
	*	true�����سɹ�
	*	false������ʧ��
	*/
	bool LoadMapFromFile(const std::string& fileName);

	/*
	*GetRow()
	*
	*��ȡ��ͼ����
	*
	*@return int:
	*��ͼ����
	*/
	const int& GetRow() const;

	/*
	*GetRank()
	*
	*��ȡ��ͼ����
	*
	*@return int��
	*	��ͼ����
	*/
	const int& GetRank() const;
private:
	/*
	*AllocMemory(const int& row, const int& rank)
	*
	*Ϊ��ͼ��������ڴ�
	*
	*@Param��
	*	int row����ͼ����
	*	int rank����ͼ����
	*/
	void AllocMemory(const int& row, const int& rank) noexcept;

	/*
	*FreeMemory(const int& row,const int& rank);
	*
	*�ͷŵ�ͼ��Դ
	*
	*@Param��
	*	int row����ͼ����
	*	int rank����ͼ����
	*/
	void FreeMemory(const int& row, const int& rank) noexcept;

	Map_type **m_MapInfo;

	int m_row;
	
	int m_rank;
};

