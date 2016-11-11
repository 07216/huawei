#include "stdafx.h"
#include "view.h"
#include<assert.h>

view::view()
{
}
void view::print()
{
	printf("\n");
	for (int i = 0; i < way_->point_n; i++)
	{
		if (way_->cross_.temperature.at(i) != 0)
		{
			printf("%d:%d|", i, way_->cross_.temperature.at(i));
		}
	}
	printf("\n");
	int max = 0;
	int num=-1;
	for (int i = 0; i < way_->key_n; i++)
	{
		if (way_->cross_.power.at(i) != 0)
		{
			printf("%d:%d|", way_->data_->key2point.at(i), way_->cross_.power.at(i));
		}
		if (way_->cross_.power.at(i)>max)
		{
			num = i;
			max = way_->cross_.power.at(i);
		}
	}
	printf("\n");
	if (num!=-1)
	printf("%d\n", way_->data_->key2point.at(num));
	for (int i = 0; i < way_->key_n; i++)
	{
		int niddle = way_->state_list.at(i).target;
		int end = way_->data_->key2point.at(i);
		printf("%d:", end);
		while (niddle != end)
		{
			printf("%d ", niddle);
			niddle = way_->state_list.at(i).now_last.at(niddle);
		}
		printf("%d\n",end);
	}
	
}
void view::write(char *filename)
{
	FILE *fp = fopen(filename, "w");
	if (fp == NULL)
	{
		printf("Fail to open file %s.\n", filename);
	}
	printf("Open file %s OK.\n", filename);
	int niddle_write = 0;
	//printf("%d:", way_->data_->key2point.at(0));
	bool flag = true;
	while (niddle_write!=way_->state_list.size())
	{
		int niddle = way_->state_list.at(niddle_write).target;
		int end = way_->data_->key2point.at(niddle_write);
		std::vector<int> copy;
		//printf("%d:", end);
		while (niddle != end)
		{
			copy.push_back(niddle);
			//printf("|%d", niddle);
			niddle = way_->state_list.at(niddle_write).now_last.at(niddle);
		}
		copy.push_back(end);
		for (int i = copy.size() - 1; i > 0; i--)
		{
			if (flag == true)
			{
				flag = false;
				fprintf(fp,"%d", find_road(copy.at(i), copy.at(i - 1)));
			}
			else
			{
				fprintf(fp,"|%d", find_road(copy.at(i), copy.at(i - 1)));

			}
		}
		//printf("%d\n", end);
		niddle_write = way_->gentic.at(niddle_write);
	}
	fclose(fp);
}
int view::find_road(int begin, int end)
{
	std::vector<data::iandi> *niddle = &way_->data_->power_list.at(begin);
	for (int i = 0; i < niddle->size(); i++)
	{
		if (niddle->at(i).num == end)
			return niddle->at(i).code;
	}
	assert(1 == 0);
}
void view::write_false(char *filename)
{
	FILE *fp = fopen(filename, "w");
	if (fp == NULL)
	{
		printf("Fail to open file %s.\n", filename);
	}
	printf("Open file %s OK.\n", filename);
	fprintf(fp,"NA");
	fclose(fp);
}
void view::printway()
{
	int i = 0;
	int niddle = way_->gentic.at(i);
	if (niddle == way_->gentic.size()) niddle = 0;
	printf("\n%d:", way_->data_->key2point.at(i));
	while ((niddle != i))
	{
		printf("|%d", way_->data_->key2point.at(niddle));
		niddle = way_->gentic.at(niddle);
		if (niddle == way_->gentic.size()) niddle = 0;
		
	}
}

view::~view()
{
}
