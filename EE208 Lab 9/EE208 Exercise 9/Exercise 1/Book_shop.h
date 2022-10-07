#pragma once
#include "Warehouse.h"

class Book_shop:public Warehouse
{
public:
	//constructors
	Book_shop();
	Book_shop(Warehouse);
	~Book_shop();

	//public member function
	void sell(int,int);
};