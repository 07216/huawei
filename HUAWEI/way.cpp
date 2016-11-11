#include "stdafx.h"
#include"stdio.h"
#include "way.h"
#include"cross.h"
#include<assert.h>
way::way()
{
//	o =  rand();
}
void way::push_way(int i)
{
	int niddle = state_list.at(i).target;
	int end = data_->key2point.at(i);
	while (niddle != end)
	{
		cross_.pop_road(i, niddle);
		niddle = state_list.at(i).now_last.at(niddle);
	}
	gentic.at(i)=state_list.at(i).djstl();
	//sum_power.at(i) = state_list.at(i).powernow;
	niddle = state_list.at(i).target;
	while (niddle != end)
	{
		cross_.push_road(i, niddle);
		niddle = state_list.at(i).now_last.at(niddle);
	}
}
void way::init(data *dat_)
{	
	data_ = dat_;
	cross_.init(data_);
	point_n = data_->point_n;
	key_n = data_->key_n-1;//»•µÙ÷’µ„
	
	state_list.resize(key_n);
	gentic.resize(key_n);

	sum_power.resize(key_n);
	for (int i = 0; i < key_n; i++)
	{
		state_list.at(i).init(i, data_,&cross_);
		state_list.at(i).target=data_->key2point.at(i);
		push_way(i);
	}
}

bool way::is_ok()
{
	std::vector<bool> road_use;
	road_use.resize(key_n);
	for (int i = 0; i < key_n; i++)
	{
		road_use.at(i) =false;
	}
	for (int i = 0; i < key_n; i++)
	{
		if (road_use.at(i) == false)
		{
			int index;
			int niddle = gentic.at(i);
			if (niddle == gentic.size()) niddle = 0;
			road_use.at(i) = true;
			index = 1;
			while ((niddle != i))
			{
				if (index > gentic.size()) 
					return false;
				road_use.at(niddle) = true;
				niddle = gentic.at(niddle);
				if (niddle == gentic.size()) niddle = 0;
				index++;
			}
			if (index == gentic.size())	return true;
			if (index < (gentic.size() + 2) / 2)
			{
				int niddle = gentic.at(i);
				state_list.at(i).again(niddle);
				if (niddle == gentic.size()) niddle = 0;
				//printf("\n%d:",data_->key2point.at(i));
				cross_.power.at(i)++;
				while ((niddle != i))
				{					
					cross_.power.at(niddle)++;
					niddle = gentic.at(niddle);
					
					if (niddle == gentic.size()) niddle = 0;
					state_list.at(niddle).again(gentic.at(niddle));
				//	printf("|%d", data_->key2point.at(niddle));
				}
			}
			
		}
	}
	return false;
}
int way::find()
{
	int max = 0;
	int num = -1; 
	o = rand();
	for (int k=0; k < key_n; k++)
	{
		int i = (o + k) % key_n;
		if (cross_.power.at(i)>max)
		{
			num =i;
			max = cross_.power.at(i) ;
		}
	}
	return num;

	//push_way(num);
	cross_.power.at(num) = 0;
	//assert(cross_.power.at(num) == 0);
	return false;
}



int way::getpower()
{
	int sum = 0;
	for (int niddle_write = 0; niddle_write < state_list.size();niddle_write++)
	{
		int niddle = state_list.at(niddle_write).target;
		int end = data_->key2point.at(niddle_write);
		std::vector<int> copy;
		//printf("%d:", end);
		while (niddle != end)
		{
			copy.push_back(niddle);
			//printf("|%d", niddle);
			niddle = state_list.at(niddle_write).now_last.at(niddle);
		}
		copy.push_back(end);
		for (int i = copy.size() - 1; i > 0; i--)
		{
			std::vector<data::iandi> *niddle = &data_->power_list.at(copy.at(i));
			for (int j = 0; j < niddle->size(); j++)
			{
				if (niddle->at(j).num ==copy.at(i-1))
					sum+= niddle->at(j).power;
			}
			assert(1 != 0);
		}
		//printf("%d\n", end);
	//	niddle_write = gentic.at(niddle_write);
	}
	return sum;
}
way::~way()
{
}
