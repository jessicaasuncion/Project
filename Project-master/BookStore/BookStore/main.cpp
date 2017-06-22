#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

}

void displayCashier()
{
	cout << endl;
	cout << "Serendipity Book Sellers" << endl << endl;
	cout << "Date: 06/22/2017" << endl << endl;
	cout << "____________________________________________________________\n";

		cout << "Qty" << setw(6)
			<< "IBSN" << setw(15)
		<< "Title" << setw(25)
		<< "Price" << setw(10)
		<< "Total\n";

	cout << "____________________________________________________________\n";
	

	cout << endl << endl << endl;
	cout << setw(20) << "Subtotal" << setw(10) << endl;
	cout << setw(20) << "Tax" << setw(15) << endl;
	cout << setw(20) << "Total" << setw(13) << endl;
	cout << endl << endl << endl;

	cout << "Thank You for Shopping at Serendipity!" << endl << endl;
}


