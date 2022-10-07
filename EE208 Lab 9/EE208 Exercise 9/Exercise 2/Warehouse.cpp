#pragma once
#include "Warehouse.h"
#include "Book_shop.h"

//default constructor
Warehouse::Warehouse() 
{
	num_hards = NULL;
	num_softs = NULL;
	num_mags = NULL;
}

//constructor
Warehouse::Warehouse(int Num_soft, int Num_hard, int Num_mag) 
{
	num_hards = Num_hard;
	num_softs = Num_soft;
	num_mags = Num_mag;

	string A,B,C; int D,E,G; float F;

	//create an array of hardbacks
	Hardbacks = new Hardback [Num_hard];
	if(Num_hard>0) cout << "Please enter details of all " << Num_hard << " hardback books in the warehouse:" << endl;
	for(int i = 0; i<Num_hard; i++)
	{
		cout << "For Hardback " << i+1 << endl;

		//input the details for the books
		cout << "Please enter title:     "; cin >> A; 
		cout << "Please enter author:    "; cin >> B;
		cout << "Please enter publisher: "; cin >> C;
		cout << "Please enter edition:   "; cin >> D;
		cout << "Please enter barcode:   "; cin >> E;
		cout << "Please enter price:     "; cin >> F;
		cout << "Please enter number of copies: "; cin >> G;

		//set the values
		Hardbacks[i].Book_set_details(A,B,C,D,E,F,G);
	}

	//create an array of softbacks
	Softbacks = new Softback [Num_soft];
	if(Num_soft>0) cout << endl << "Please enter details of all " << Num_soft << " softback books in the warehouse:" << endl;
	for(int i = 0; i<Num_soft; i++)
	{
		cout << "For Softback " << i+1 << endl;

		//input the details for the books
		cout << "Please enter title:     "; cin >> A; 
		cout << "Please enter author:    "; cin >> B;
		cout << "Please enter publisher: "; cin >> C;
		cout << "Please enter edition:   "; cin >> D;
		cout << "Please enter barcode:   "; cin >> E;
		cout << "Please enter price:     "; cin >> F;
		cout << "Please enter number of copies: "; cin >> G;

		//set the values
		Softbacks[i].Book_set_details(A,B,C,D,E,F,G);
	}

	//create an array of magazines
	Magazines = new Magazine[Num_mag];
	if (Num_mag > 0) cout << endl << "Please enter details of all " << Num_mag << " magazines in the warehouse:" << endl;
	for (int i = 0; i < Num_mag; i++) 
	{
		cout << "For Magazine " << i + 1 << endl;

		//input the details for the books
		cout << "Please enter title:     "; cin >> A;
		cout << "Please enter author:    "; cin >> B;
		cout << "Please enter publisher: "; cin >> C;
		cout << "Please enter edition:   "; cin >> D;
		cout << "Please enter barcode:   "; cin >> E;
		cout << "Please enter price:     "; cin >> F;
		cout << "Please enter number of copies: "; cin >> G;

		//set the values
		Magazines[i].Book_set_details(A, B, C, D, E, F, G);
	}
}
//destructor
Warehouse::~Warehouse()
{

}
//print the details of the books
void Warehouse::print_all_books()
{
	cout << endl << "LIST OF HARDBACKS:" << endl;
	for(int i = 0; i<num_hards;i++)
	{
		Hardbacks[i].Book_print();
		cout<<endl;
	}
	cout << endl << "LIST OF SOFTBACKS:" << endl;
	for(int j = 0; j<num_softs;j++)
	{
		Softbacks[j].Book_print();
		cout << endl;
	}
	cout << endl << "LIST OF MAGAZINES:" << endl;
	for (int j = 0; j < num_mags; j++) 
	{
		Magazines[j].Book_print();
		cout << endl;
	}
}

void Warehouse::transfer(Book_shop &A, int bar, int amount)
{
	
	int i = 0;
	bool found = false; 

	while((i < num_hards)&&(found == false))
	{
		if(Hardbacks[i].details->Barcode == bar)
		{
			for(int j = 0; j < A.num_hards; j++)
			{
				if(A.Hardbacks[i].details->Barcode == bar)
				{
					while(amount < 0)
					{
						cout << endl << "negative transfer not allowed. Reenter amount to transfer: " << endl; cin >> amount; 
					}
					if(Hardbacks[i].details->num_copies>=amount)
					{
						Hardbacks[i].details->num_copies -= amount;
						A.Hardbacks[i].details->num_copies += amount;
					}
					else
					{
						cout << endl << "Not enough stock to transfer." << endl;
					}
				}
			}
			found = true;
		}
		i++;
	}
	i=0;
	while((i < num_softs)&&(found == false))
	{
		if(Softbacks[i].details->Barcode == bar)
		{
			for(int j = 0; j < A.num_softs; j++)
			{
				if(A.Softbacks[i].details->Barcode == bar)
				{
					while (amount < 0)
					{
						cout << endl << "negative transfer not allowed. Reenter amount to transfer: " << endl; cin >> amount; 
					}
					if(Softbacks[i].details->num_copies>=amount)
					{
						Softbacks[i].details->num_copies -= amount;
						A.Softbacks[i].details->num_copies += amount;
					}
					else
					{
						cout << endl << "Not enough stock to transfer." << endl;
					}
				}
			}
			found = true;
		}
		i++;
	}
	i = 0;
	while ((i < num_mags) && (found == false)) 
	{
		if (Magazines[i].details->Barcode == bar) 
		{
			for (int j = 0; j < A.num_mags; j++) 
			{
				if (A.Magazines[i].details->Barcode == bar) 
				{
					while (amount < 0) 
					{
						cout << endl << "negative transfer not allowed. Reenter amount to transfer: " << endl; cin >> amount;
					}
					if (Magazines[i].details->num_copies >= amount) 
					{
						Magazines[i].details->num_copies -= amount;
						A.Magazines[i].details->num_copies += amount;
					}
					else 
					{
						cout << endl << "Not enough stock to transfer." << endl;
					}
				}
			}
			found = true;
		}
		i++;
	}
	if(found==false)
	{
		cout << endl << "No such book exists in the warehouse." << endl;
	}
}





