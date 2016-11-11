// HUAWEI.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include"data.h"
#include"run.h"

//#ifdef is_window

//#else
	//#include"stdio.h"
//#endif


int main(int argc, char** argv)
{
	//print_time("Begin");
/*#ifdef window
	char** arg;
	arg = new char*[4];

	char arg1[100] = "E:/HWdata/case0/topo.csv";
	char arg2[100] = "E:/HWdata/case0/demand.csv";
	char arg3[100] = "E:/HWdata/case0/result.csv";
	arg[1] = arg1; arg[2] = arg2; arg[3] = arg3;



	for (int i = 0; i < 10; i++)
	{
		arg1[14] = i + 48;
		arg2[14] = i + 48;
		arg3[14] = i + 48;

		run run_;
		run_.the_world(argc, arg);

	}
	getchar();
#else*/
	run run_;
	run_.the_world(argc, argv);
//#endif
	return 0;
}

