#include "stdafx.h"
#include "run.h"
#include"time.h"
#include"view.h"
run::run()
{

}

void run::the_world(int argc, char** argv)
{
//	printf("\n");
#ifdef window
	//argv[1]= "topo.csv";
	//argv[2] = "demand.csv";
	//argv[3] = "result2.csv";
#endif
	clock_t start, finish;
	double duration;

	start = clock();

	data_.read_topo( argv[1]);
	data_.read_demand(argv[2]);
	way_list.resize(waysum);
	for (int i = 0; i < waysum; i++)
	{
		
		way_list.at(i) = new way;
		way_list.at(i)->init(&data_);
	}
	
	best = 1000000;
	way_best = NULL;
	//way_.print();
	while(main_loop())
	{
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		if (duration > 9)//����5����Ϊ�޽�
		{
			break;
		}
	};
	//printf("step1:end");
	//way_.print();
	//way_.printway();
	//getchar();
	if (way_best == NULL)
	{
		printf("\n NULLL\n");
		view view_;
		view_.way_ = way_list.at(0);
		view_.write_false(argv[3]);
	}
	else
	{
		printf("\n%d \n", way_best->getpower());
		view view_;
		view_.way_ = way_best;
		view_.write(argv[3]);
	}	//
}

bool run::optimize(int i)
{
	int num = way_list.at(i)->find();
	if (num == -1)
	{
		if (way_list.at(i)->is_ok()) return true;
		else{
			//		way_.print();
			//	way_.printway();
			return false;
		}
	}
	way_list.at(i)->push_way(num);
	way_list.at(i)->cross_.power.at(num) = 0;
	return false;
}
bool run::main_loop()
{
	for (int i = 0; i < waysum; i++)
	{
		if (optimize(i))
		{
			int now = way_list.at(i)->getpower();
			printf("%d ", now);
			if (now == best)
				return false;
			if (now < best)
			{
				best = now;
				way_best = way_list.at(i);
			}
			way_list.at(i) = new way;
			way_list.at(i)->init(&data_);
		}
	}
	return true;
}
run::~run()
{
}
