#pragma once
#include<vector>

class heap
{
public:
	heap();
	void init(int point_n);
	int sum;
	struct heap_s
	{
		int power;
		int num;
	};
	std::vector<heap_s> heap_;
	std::vector<int> heap_niddle;
	int heap_size;
	bool heap_push(int power, int num);
	void heap_pop(int &power, int &num);

	void push(heap_s &ele, int num);
	
	~heap();
};

