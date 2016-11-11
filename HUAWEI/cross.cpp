

#include "stdafx.h"
//#ifdef is_window

//#else
//#include"stdio.h"
//#endif
#include "cross.h"
#include<assert.h>

cross::cross()
{
}

void cross::init(data *dat_)
{
	data_ = dat_;
	cross_list.resize(data_->point_n);
	temperature.resize(data_->point_n);
	power.resize(data_->key_n);
	for (int i = 0; i < data_->point_n; i++)
	{
		cross_s* ele = new cross_s;
		ele->key = 0;
		ele->next = NULL;
		cross_list.at(i) = ele;
		temperature.at(i) = 0;
	}
	
	
}
void cross::push_road(int key,int niddle)
{
	cross_s* ele=new cross_s;
	ele->key =key;
	ele->next = cross_list.at(niddle)->next;
	cross_list.at(niddle)->next = ele;
	cross_list.at(niddle)->key++;
	if (cross_list.at(niddle)->key > 1)
	{
		temperature.at(niddle)++;
		cross_s* ele2 = cross_list.at(niddle);

		while (ele2->next != NULL)
		{
			power.at(ele2->next->key)++;

			ele2 = ele2->next;
		}
	}
}
void cross::pop_road(int key,int niddle)
{
	//power.at(key)= 0;
	cross_s* ele = cross_list.at(niddle);
	/*if (cross_list.at(niddle)->key > 1)
	{
		//temperature.at(niddle)--;
		//power.at(key)--;
		cross_s* ele2 = cross_list.at(niddle);
	//	while (ele2->next != NULL)
		{
		//	power.at(ele2->next->key)--;
		}
	}*/
	cross_list.at(niddle)->key--;

	while (ele->next!=NULL)
	{
		if (ele->next->key == key)
		{
			cross_s* ele2 = ele->next;
			ele->next = ele->next->next;
			delete ele2;
			return;
		}
		ele = ele->next;
	}
	assert(1 == 0);
}
cross::~cross()
{
}
