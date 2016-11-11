#pragma once
#include"data.h"
//Éñ¾­Ôª
#include"cross.h"
#include"heap.h"
class state
{
public:
	state();
	void again(int niddle);
	int key, point;
	int point_n;
	heap heap_;
	int powernow;
	int target;
	std::vector<int> ring_list;
	void init(int key_n, data *dat_,cross *cros_);
	cross *cross_;
	data *data_;
	std::vector<int> now_last;
	
	int djstl();
	~state();
};

