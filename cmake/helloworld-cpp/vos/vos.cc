/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:44 CST. */
#include <stdio.h>
#include <iostream>
//#include "vos.hxx"
using namespace std;

class cell {
public:
	cell();
	~cell();
	unsigned int get_cellid();
	int set_cellid(unsigned int id);
private:
	unsigned int cellid;
};

cell::cell()
{
	cout<<">>new cell"<<endl;
}
cell::~cell()
{
	cout<<"delete cell"<<endl;
}
unsigned int cell::get_cellid()
{
	return cellid ;
}
int cell::set_cellid(unsigned int id)
{
	cellid = id;
	return id;
}	

template <class T>
T sum(T t1, T t2)
{
	cell *c = new cell();
	c->set_cellid(123);
	cout<<"Cell ID = "<<c->get_cellid()<<endl;
	delete c;
	return t1 + t2;
}

struct cell_struct {
	static int cellid;
};


extern "C" void info()
{
#if 1
	struct cell_struct __attribute__((unused)) cell1;
	struct cell_struct __attribute__((unused)) cell2;
#endif
	//cell1.cellid = 12345;

	cout<<sum(1,2)<<endl;
	cout<<sum(1.2, 3.4)<<endl;
	//printf("vos info cellinfo : %d\n", cell2.cellid);
}



