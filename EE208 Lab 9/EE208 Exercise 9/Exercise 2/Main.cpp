#include "Book_details.h"
#include "Book.h"
#include "Warehouse.h"
#include "Book_shop.h"

int main(void)
{
	int hard_copies, soft_copies, mag_copies; 
	cout << "Enter number of different hardbacks in warehouse: "; cin >> hard_copies;
	cout << "Enter number of different softbacks in warehouse: "; cin >> soft_copies;
	cout << "Enter number of different softbacks in warehouse: "; cin >> mag_copies;
	cout << endl;

	Warehouse Kildare_Warehouse(soft_copies,hard_copies, mag_copies);
	Book_shop Maynooth(Kildare_Warehouse);
	
	cout << "-----------------------------------------------------" << endl;
	cout << "Kildare Warehouse stock" << endl;
	Dublin_Warehouse.print_all_books();

	cout << "-----------------------------------------------------" << endl;
	cout << "Maynooth store stock" << endl;
	Mullingar.print_all_books();

	int barcode, copies;
	cout << "-----------------------------------------------------" << endl;
	cout << "Transfer books from Kildare to Maynooth:" << endl;
	cout << "Enter barcode to transfer:          "; cin >> barcode;
	cout << "Enter number of copies to transfer: "; cin >> copies;
	
	Kildare_Warehouse.transfer(Maynooth, barcode, copies);

	cout << "-----------------------------------------------------" << endl;
	cout << endl << "Kildare Warehouse stock" << endl;
	Kildare_Warehouse.print_all_books();

	cout << "-----------------------------------------------------" << endl;
	cout << "Maynooth store stock" << endl;
	Maynooth.print_all_books();
	
	cout << "-----------------------------------------------------" << endl;
	cout << "Maynooth just sold 1 book, barcode: "<< barcode << ":" << endl;
	Maynooth.sell(barcode,1);
	Maynooth.print_all_books();

	return(0);
}





