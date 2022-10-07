#include "Warehouse.h"
#include "Book_shop.h"
#include "vector"

//default constructor
Book_shop::Book_shop() 
{
	num_hards = NULL;
	num_softs = NULL;
	num_mags = NULL;
}

//constructor
Book_shop::Book_shop(Warehouse W) 
{
	num_hards = W.num_hards;
	num_softs = W.num_softs;
	num_mags = W.num_mags;

	string A, B, C; int D, E; float F;

	vector<Hardback>Hardbacksb (Hardbacks.begin(),W.Hardbacks.end());

	//create an array of softbacks
	Softbacks = new Softback [W.num_softs];
	for(int i = 0; i<W.num_softs; i++){
		A = W.Softbacks[i].details->Author;
		B = W.Softbacks[i].details->Title;
		C = W.Softbacks[i].details->Publisher;
		D = W.Softbacks[i].details->Edition;
		E = W.Softbacks[i].details->Barcode;
		F = W.Softbacks[i].Price;
		Softbacks[i].Book_set_details(A,B,C,D,E,F,0); 
	}

	//create an array of magazines
	Magazines = new Magazine[W.num_mags];
	for (int i = 0; i < W.num_softs; i++) 
	{
		A = W.Magazines[i].details->Author;
		B = W.Magazines[i].details->Title;
		C = W.Magazines[i].details->Publisher;
		D = W.Magazines[i].details->Edition;
		E = W.Magazines[i].details->Barcode;
		F = W.Magazines[i].Price;
		Magazines[i].Book_set_details(A, B, C, D, E, F, 0); 
	}
}

//destructor
Book_shop::~Book_shop() 
{
	delete[] Hardbacks;
	delete[] Softbacks;
	delete[] Magazines;
}

//public member functions
void Book_shop::sell(int barcode, int amount)
{
	int i = 0;
	bool found = false; 

	while((i < num_hards)&&(found == false))
	{

		if(Hardbacks[i].details->Barcode == barcode)
		{
			if(Hardbacks[i].details->num_copies >= amount)
			{
				Hardbacks[i].details->num_copies = Hardbacks[i].details->num_copies - amount;
			}
			else
			{
				cout << endl << "Not enough stock." << endl;
			}
			found = true;
		}
		i++;
	}
	i=0;
	while((i < num_softs)&&(found == false))
	{
		if(Softbacks[i].details->Barcode == barcode)
		{
			if(Softbacks[i].details->num_copies >= amount)
			{
				Softbacks[i].details->num_copies = Softbacks[i].details->num_copies - amount;
			}
			else
			{
				cout << endl << "Not enough stock." << endl;
			}
			found = true;
		}
		i++;
	}
	i = 0;

	while ((i < num_mags) && (found == false)) 
	{
		if (Magazines[i].details->Barcode == barcode) 
		{
			if (Magazines[i].details->num_copies >= amount)
			{
				Magazines[i].details->num_copies = Magazines[i].details->num_copies - amount;
			}
			else {
				cout << endl << "Not enough stock." << endl;
			}
			found = true;
		}
		i++;
	}

	if(found == false)
	{
		cout<<endl<< "No such book in database";
	}

}





