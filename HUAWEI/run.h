#pragma once
#include"data.h"
#include"way.h"
class run
{
public:
	run();
	data data_;
	way *way_best;
	int best;
	const int waysum=6;
	std::vector<way *> way_list;
	bool optimize(int i);
	std::vector<bool >way_flag;
	bool main_loop();
	void the_world(int argc, char** argv);
	~run();
};

