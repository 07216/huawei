#include "stdafx.h"
#include "state.h"


state::state()
{
}
void state::init(int key_, data *dat_, cross *cros_)
{
	
	cross_ = cros_;
	data_ = dat_;
	key = key_;
	ring_list.resize(data_->key_n);
	for (int i = 0; i < data_->key_n;i++)
		ring_list.at(i)=0;
	point_n = data_->point_n;
	point = data_->key2point.at(key);
	now_last.resize(point_n);
	now_last.at(data_->key2point.at(key_)) = data_->key2point.at(key_);
	
	//heap_.heap_push(0, point);
}

int state::djstl()
{
	int power=0, num=point,ring_add;
	heap_.init(point_n);
	while (1)
	{
		std::vector<data::iandi> *copy = &data_->power_list.at(num);
		for (int i = 0; i < copy->size(); i++)
		{
			ring_add = data_->point2key.at(copy->at(i).num);
			if (ring_add != -1)
				ring_add = ring_list.at(ring_add);
			else
				ring_add = 0;
			if(heap_.heap_push(ring_add+power + copy->at(i).power + cross_->temperature.at(copy->at(i).num), copy->at(i).num))
				now_last.at(copy->at(i).num)=num;
		
		}
		heap_.heap_pop(power, num);
		if (data_->point2key.at(num) != -1) 
		{
			if ((data_->point2key.at(num) == 0) || num == point)
			{
				heap_.heap_pop(power, num);
				continue;//不能是起点
			}
			target = num;
			//now_last.at(target) = num;
			return data_->point2key.at(num);
		}		
	}
}
void state::again(int niddle)
{
	ring_list.at(niddle)++;

}
state::~state()
{
}
