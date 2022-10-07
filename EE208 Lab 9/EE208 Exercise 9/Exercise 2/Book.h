#pragma once
#include "Book_details.h"

//class declaration
class Book 
{
public:
	//public member variables
	Book_details *details;
	float Price;
	
	//constructors
	Book();
	Book(string, string, string, int, int, float, int);
	~Book();

	//public member functions
	void Book_set_details(string, string, string, int, int, float, int);
	void Book_print(void);
	void Add(int);
	void Subtract(int);
};

//class Hardback inherits from Book
class Hardback : public Book 
{
public:
	//constructors
	Hardback();
	Hardback(string, string, string, int, int, float, int);
};


//class Softback inherits from Book
class Softback : public Book
 {
public:
	//constructors
	Softback();
	Softback(string, string, string, int, int, float, int);
};

//class Magazine inherits from Book
class Magazine : public Book 
{
public:
	//constructors
	Magazine();
	Magazine(string, string, string, int, int, float, int);
};