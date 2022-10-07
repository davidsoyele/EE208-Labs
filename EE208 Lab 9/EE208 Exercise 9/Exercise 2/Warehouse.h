#pragma once
#include "book.h"

class Book_shop; 

//class declaration
class Warehouse 
{
public:
	//public member variables
	Hardback *Hardbacks; 
	Softback *Softbacks; 
	Magazine* Magazines;
	int num_hards;
	int num_softs;
	int num_mags;
	
	//constructors
	Warehouse();
	Warehouse(int,int,int);
	~Warehouse();

	//public member functions
	void print_all_books();
	void transfer(Book_shop &, int, int);
};






