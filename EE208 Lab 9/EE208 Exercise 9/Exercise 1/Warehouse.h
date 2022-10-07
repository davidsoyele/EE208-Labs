#pragma once
#include "book.h"

class Book_shop; 

class Warehouse
{
public:
	Hardback *Hardbacks; 
	Softback *Softbacks; 
	int num_hards;
	int num_softs;
	
	//constructors
	Warehouse();
	Warehouse(int,int);
	~Warehouse();

	//public member functions
	void print_all_books();
	void transfer(Book_shop &, int, int);
};






