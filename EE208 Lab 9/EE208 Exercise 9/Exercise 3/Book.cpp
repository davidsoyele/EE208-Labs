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
	delete details;
}

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
	cout << "Price:     " << Price << endl;
}

//function to increase the number of copies
void Book::Add(int N) 
{
	details->num_copies = details->num_copies + N;
}

//function to reduce the number of copies
void Book::Subtract(int N) 
{
	details->num_copies = details->num_copies - N;
}

Hardback::Hardback(){};
Hardback::Hardback(string A, string B, string C, int D, int E, float F, int G) :Book(A, B, C, D, E, F, G) {};

Softback::Softback(){};
Softback::Softback(string A, string B, string C, int D, int E, float F, int G) :Book(A, B, C, D, E, F, G) {};

Magazine::Magazine() {};
Magazine::Magazine(string A, string B, string C, int D, int E, float F, int G) :Book(A, B, C, D, E, F, G) {};
