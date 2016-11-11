#pragma once
//用于处理路径各部分的冲突情况
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
	std::vector<int> power;//当前冲突能量
	std::vector<int> temperature;//每点附加势
	void push_road(int key, int niddle);
	void pop_road(int key, int niddle);
	std::vector<cross_s*> cross_list;
	~cross();
	
};

