#include "stdafx.h"
#include "data.h"


data::data()
{
}
void data::read_topo(char *filename)
{
	FILE *fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Fail to open file %s.\n", filename);
	}
	printf("Open file %s OK.\n", filename);

	int data_z[5000][4];
	line_n = 0;
	point_n = -1;
	while (fscanf(fp, "%d,%d,%d,%d", &data_z[line_n][0], &data_z[line_n][1], &data_z[line_n][2], &data_z[line_n][3]) != EOF)
	{
		if (data_z[line_n][1] > point_n) point_n = data_z[line_n][1];
		if (data_z[line_n][2] > point_n) point_n = data_z[line_n][2];
		line_n++;
	}
	point_n++;
	fclose(fp);
	printf("There are %d lines in file %s.\n", line_n, filename);
	/*power = new int[point_n*point_n];
	
	for (int i = 0; i < point_n*point_n; i++)
	{
		power[i] = -1;
	}
	for (int i = 0; i < line_n; i++)
	{
		if ((power[(data_z[i][1] )*point_n + data_z[i][2]] == -1) || (power[(data_z[i][1] )*point_n + data_z[i][2]]>data_z[i][3]))
			power[(data_z[i][1] )*point_n + data_z[i][2]] = data_z[i][3];
	}*/
	power_list.resize(point_n);
	for (int i = 0; i < line_n; i++)
	{
		int j;
		for (j = 0; j < power_list.at(data_z[i][1]).size(); j++)
		{
			if ((power_list.at(data_z[i][1]).at(j).num == data_z[i][2]) && (power_list.at(data_z[i][1]).at(j).num >data_z[i][3]))
			{
				power_list.at(data_z[i][1]).at(j).num = data_z[i][3];
			}
		}
		if (j == power_list.at(data_z[i][1]).size())
		{
			iandi ele;
			ele.num = data_z[i][2]; ele.power = data_z[i][3];
			ele.code = data_z[i][0];
			power_list.at(data_z[i][1]).push_back(ele);
		}
	}
}
void data::read_demand(char *filename)
{
	FILE *fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Fail to open file %s.\n", filename);
	}
	printf("Open file %s OK.\n", filename);
	fscanf(fp, "%d,%d,", &road_begin, &road_end);
	int keypoint[60];
	char c;
	key_n = 1;
	keypoint[0] = road_begin;
	while (fscanf(fp, "%d%c", &keypoint[key_n],&c)!=EOF)
	{
		key_n++;
	}
	fclose(fp);
	keypoint[key_n++] = road_end;
	key2point.resize(key_n);
	point2key.resize(line_n);
	for (int i = 0; i < line_n; i++)
		point2key.at(i) = -1;
	for (int i = 0; i < key_n; i++)
	{
		key2point.at(i) = keypoint[i];
		point2key.at(keypoint[i]) = i;
	}
	
	printf("%d",key_n);
	
}
data::~data()
{
}
