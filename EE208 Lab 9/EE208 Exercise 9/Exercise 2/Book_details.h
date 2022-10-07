#pragma once
#include <string>
#include <iostream>
using namespace std;

//class declaration
class Book_details 
{
public:

	//public member varables
	string Author;
	string Title;
	string Publisher;
	int Edition;
	int Barcode;
	int num_copies;

	//constructors
	Book_details();
	Book_details(string, string, string, int, int, int);
	~Book_details();

	//public member functions
	void set_details(string, string, string, int, int, int);
	void print_details(void);
};


