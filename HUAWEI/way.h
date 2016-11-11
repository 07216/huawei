#pragma once

#include"data.h"
#include"state.h"
//Éñ¾­Íø
class way
{
public:
	way();
	data *data_;
	int getpower();
	int key_n, point_n;
	int o;
	void init(data *dat_);
	std::vector<state> state_list;
	int find();
	std::vector<int > gentic;
	void push_way(int i);
	cross cross_;
	bool is_ok();
	
	std::vector<int > sum_power;
	~way();
};

