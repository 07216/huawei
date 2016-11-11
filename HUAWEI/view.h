#pragma once
#include"way.h"
class view
{
public:
	view();
	way *way_;
	void print();
	void printway();
	int find_road(int begin, int end);
	void write(char *filename);
	void write_false(char *filename);
	~view();
};

