#include "stdafx.h"
#include "heap.h"
#include<assert.h>
heap::heap()
{}
void heap::init(int point_n)
{
	sum = point_n;
	heap_size = 0;
	heap_niddle.resize(sum);
	heap_.resize(sum);
	for (int i = 0; i < sum; i++)
		heap_niddle.at(i) = -1;
}
void heap::push(heap_s &ele, int i)
{
	int t = 2 * i + 1;
	if (2 * i + 2 < heap_size)
	{
		if (heap_.at(2 * i + 1).power > heap_.at(2 * i + 2).power)
		{
			t = 2 * i + 2;
		}
	}
	else
	{
		if (2 * i + 1 >= heap_size)
		{
			heap_.at(i) = ele;
			heap_niddle.at(ele.num) = i;
			return;
		}
	}
	if (heap_.at(t).power < ele.power)
	{
		heap_.at(i) = heap_.at(t);
		heap_niddle.at(heap_.at(i).num) = i;
		push(ele, t);
	}
	else
	{
		heap_.at(i) = ele;
		heap_niddle.at(heap_.at(i).num) = i;

		return;
	}
}
void heap::heap_pop(int &power, int &num)
{
	
	power = heap_.at(0).power;
	num = heap_.at(0).num;
	heap_niddle.at(num) = -2;
	--heap_size;
	assert(heap_size >= 0);
	if (heap_size>0)
		push(heap_.at(heap_size), 0);
}

bool heap::heap_push(int power, int num)
{
	int t;
	if (heap_niddle.at(num) == -2)return false;
	if (heap_niddle.at(num) == -1)
	{	
		t = heap_size;
		heap_size++;
	}
	else
	{
		if (power < heap_.at(heap_niddle.at(num)).power)
			t = heap_niddle.at(num);
		else return false;
	}
	int last;
	while (1)
	{
		last = (t - 1) / 2;
		if ((t< 1) || (heap_.at(last).power <= power))
		{
			heap_.at(t).power = power;
			heap_.at(t).num = num;
			heap_niddle.at(num) = t;
			break;
		}
		heap_.at(t) = heap_.at(last);
		heap_niddle.at(heap_.at(t).num) = t;
		t = last;
	}
	return true;
}

heap::~heap()
{
}
