
#pragma once
#include<vector>
class data
{
public:
	data();
	void read_topo(char* c);
	void read_demand(char*);
	void write_result(char* c);
	int line_n;
	int point_n,key_n;
	int road_begin, road_end;
	std::vector<int> key2point,point2key;
	
	struct iandi
	{
		int num;
		int power;
		int code;
	};
	std::vector<std::vector<iandi>> power_list;

	~data();
};

