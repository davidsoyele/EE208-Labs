#include "Book.h"

//default constructor
Book::Book() 
{
	details = new Book_details;
	Price = 0.0;
}

//constructor
Book::Book(string A, string B, string C, int D, int E, float F, int G)
{
	details = new Book_details;
	details->set_details(A, B, C, D, E, G);
	Price = F;
}
Book::~Book() 
{

}

//public member functions
//set values of the book
void Book::Book_set_details(string A, string B, string C, int D, int E, float F, int G) 
{
	details->set_details(A, B, C, D, E, G);
	Price = F;
}

//print the book details
void Book::Book_print() 
{
	details->print_details();
	cout << "Price: " << Price << endl;
}

Hardback::Hardback(){};
Hardback::Hardback(string A, string B, string C, int D, int E, float F, int G) :Book(A, B, C, D, E, F, G) {};

Softback::Softback(){};
Softback::Softback(string A, string B, string C, int D, int E, float F, int G) :Book(A, B, C, D, E, F, G) {};
