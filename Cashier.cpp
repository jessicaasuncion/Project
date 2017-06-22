#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iomanip>
#include <iostream>
#include <cstring>
#include "Cashier.h"
#include "Books.h"

using namespace std;

const double TAX_RATE = 0.09;			// tax sales


//*****************************************************************
// Function cashier is to ask user for the ISBN, and the quantity
// of book to purchase.
//
// Parameters:
//		original array of books
//		original number of books in the array
//
// Returns:
//		None
//
//*****************************************************************
void cashier(Books myBooks[], int numBooks)
{		
	Books resultSearchBooks[MAX_BOOKS];
	int resultSearchNumBooks = 0;
	string userInput = "";	
	int inputIndex[MAX_BOOKS];		// user inputs book's ISBN
	int inputQty[MAX_BOOKS];		// user inputs quantity of books wanted
	int indexFound = 0;

	int index = 0;					// look counter

	do
	{
		cout << "Enter the IBSN you would like to purchase: ";
		cin >> userInput;

		// search for the book with the isbn then display title and price
		indexFound = searchBook(resultSearchBooks, resultSearchNumBooks, myBooks, numBooks, SearchByIsbn, userInput);
		if (indexFound != -999) {		// There should be only one book matched 
			inputIndex[index] = indexFound;
			cout << "\nISBN: " << myBooks[indexFound].getIsbn() << endl;
			cout << "Title: " << myBooks[indexFound].getTitle() << endl;
			cout << setprecision(2) << fixed << "Price: $" << myBooks[indexFound].getPrice() << endl << endl;

			int quantityOnHand = myBooks[indexFound].getQuantity();
			// if the quantity wanted is less than the quantity in inventory, ask user to input another quantity
			if (quantityOnHand > 0)
			{
				cout << "We have " << quantityOnHand << " in our inventory." << endl;
				cout << "Enter the quantity: ";
				cin >> inputQty[index];
				do
				{
					if (cin.fail() || inputQty[index] > quantityOnHand || inputQty[index] < 1)
					{
						cout << "The quantity must be less than or equal to " << quantityOnHand << " and greater 0. Please reenter: ";
						cin.clear();
						cin.ignore();
						cin >> inputQty[index];
					}
				} while (inputQty[index] > quantityOnHand);
				// Update quantity on hand
				myBooks[indexFound].setQuantity(myBooks[indexFound].getQuantity() - inputQty[index]);
				++index;
			}
			// if out of stock, display out of stock
			else if (quantityOnHand == 0)
			{
				cout << "Out of stock." << endl << endl;
			}
		}
		else				// No matching ISBN found
		{
			cout << "The ISBN you entered: " << userInput << " is not found" << endl;
		}

		cout << "Would you like to purchase another book (Y or N): ";
		cin >> userInput;
	} while (userInput != "N" && userInput != "n");

	if (inputQty[0] > 0)		// Call displayTotal only if there's at least one book in the basket
		displayTotal(myBooks, inputIndex, inputQty);
}


//*****************************************************************
// Function displayTotal is to display each book being purchased,
// and the total price.
//
// Parameters:
//		original array of books
//		an array of index for books being purchased
//		an array of quantity of books being purchased
//
// Returns:
//		None
//
//*****************************************************************
void displayTotal(Books myBooks[], int indexArray[], int quantityArray[])
{		
	double totalPerBook[MAX_BOOKS];
	double subtotal = 0.0;
	double total = 0.0;
	double tax = 0.0;
	int index = 0;
	//subtotal + tax;

	cout << endl;
	cout << "Serendipity Book Sellers" << endl << endl;
	cout << "Date: 06/22/2017" << endl << endl;

	cout << setw(5) << left << "Qty" << setw(12)
		<< "IBSN" << setw(30)
		<< "Title" << setw(6)
		<< "Price" << setw(6)
		<< "Total\n";

	cout << "____________________________________________________________\n";

	while (quantityArray[index] > 0)
	{
		totalPerBook[index] = quantityArray[index] * myBooks[indexArray[index]].getPrice();
		subtotal += totalPerBook[index];

		cout << setw(5) << left << quantityArray[index] << setw(12)
			<< myBooks[indexArray[index]].getIsbn() << setw(30)
			<< myBooks[indexArray[index]].getTitle() << "$" << setw(6)
			<< myBooks[indexArray[index]].getPrice() << "$" << setw(6)
			<< totalPerBook[index] << endl;
		++index;
	}

	tax = subtotal * TAX_RATE;

	cout << endl << endl << endl;
	cout << setw(12) << right << "Subtotal:" << setw(8)  << "$" << subtotal << endl;
	cout << setw(12) << "Tax:" << setw(8) << "$" << tax << endl;
	cout << setw(12) << "Total:" << setw(8) << "$" << subtotal + tax << endl;
	cout << endl << endl << endl;

	cout << "Thank You for Shopping at Serendipity!" << endl << endl;
	system("pause");
}


//*****************************************************************
// Function searchBook is to search the main book array by the 
// search criteria. If there's one match, it returns the index
// of the matching boook in the main array. If there's more than
// one matching books, it returns the index = -999, and the 
// resultBook array holds all the matching books.
//
// Parameters:
//		by reference array of matching books
//		by reference number of matching books
//		original array of books to search
//		original number of books in the array
//		search by field
//		string to search
//
// Returns:
//		if there's only one match, returns the array index
//		if there's more than one match or no match, returns -999
//
// Example of how to call:
// 	indexFound = searchBook(resultSearchBooks, resultSearchNumBooks, myBooks, numBooks, SearchByPrice, "8.99");
//
//*****************************************************************
int searchBook(Books resultBooks[], int &resultNumBooks, Books inBooks[],
	int inNumBooks, SearchBy field, string toSearch)
{
	int index = 0;
	int indexBookFound = -999;
	bool bookFound = false;
	int indexFound = 0;

	for (index = 0; index < inNumBooks; ++index) {
		switch (field)
		{
		case SearchByIsbn:
			if (inBooks[index].getIsbn() == toSearch)
				bookFound = true;
			break;
		case SearchByTitle:
			if (inBooks[index].getTitle() == toSearch)
				bookFound = true;
			break;
		case SearchByAuthor:
			if (inBooks[index].getAuthor() == toSearch)
				bookFound = true;
			break;
		case SearchByPublisher:
			if (inBooks[index].getPublisher() == toSearch)
				bookFound = true;
			break;
		case SearchByDateAdded:
			if (inBooks[index].getDateAdded() == toSearch)
				bookFound = true;
			break;
		case SearchByQuantity:
			if (inBooks[index].getQuantity() == stoi(toSearch))
				bookFound = true;
			break;
		case SearchByCost:
			if (fabs(inBooks[index].getCost() - stod(toSearch)) < DBL_EPSILON)
				bookFound = true;
			break;
		case SearchByPrice:
			if (fabs(inBooks[index].getPrice() - stod(toSearch)) < DBL_EPSILON)
				bookFound = true;
			break;
		}

		if (bookFound) {
			resultBooks[indexFound++] = inBooks[index];
			indexBookFound = index;
		}
		bookFound = false;
	}
	resultNumBooks = indexFound;
	if (indexFound == 1)
		return indexBookFound;		// There's only one book found
	else
		return -999;
}
