#pragma once
//���ڴ���·�������ֵĳ�ͻ���
#include"data.h"
class cross
{
public:
	cross();
	int add;
	void init(data *dat_);
	data *data_;
	struct  cross_s
	{
	//	int num;
		int key;
		cross_s *next;
	};
	std::vector<int> power;//��ǰ��ͻ����
	std::vector<int> temperature;//ÿ�㸽����
	void push_road(int key, int niddle);
	void pop_road(int key, int niddle);
	std::vector<cross_s*> cross_list;
	~cross();
	
};

