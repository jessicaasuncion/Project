#define _CRT_SECURE_NO_WARNINGS

#ifndef BOOK_REPORT_MENU_H
#define BOOK_REPORT_MENU_H

#include <iostream>
#include <iomanip>

#include "Books.h"

int displayReportMenu();// also get user to pick which report listing to display
//functions for all listings
void inventoryListing(int, Books[], int); //sort by title
void wholeSaleListing(int, Books[], int); //sort by unit wholesale value
void retailListing(int, Books[], int);//sort by unit retail value
void quantityListing(int, Books[], int);//sort by quantity on hand
void costListing(int, Books[], int);//sort by unit cost
void ageListing(int, Books[], int);//sort by age


//functions for display listings
void displayInventoryListing(Books);//A list of information on all books in the inventory.
void displayWholesale(Books);//A list of the wholesale value of all books in the inventory and the total wholesale value of the inventory.
void displayRetail(Books); //A list of the retail value of all books in the inventory and the total retail value of the inventory.
void displayQuantity(Books); //  A list of all books in the inventory sorted by quantity on hand.
void displayCost(Books); // A list of all books in the inventory, sorted by wholesale cost
void displayAge(Books); //A list of all books in the inventory, sorted by purchase date.



enum REPORT {ALL=1, WHOLESALE, RETAIL, QUANTITY, COST, AGE, MAIN };

int displayReportMenu(){
	string selectReport = "";
	cout << "REPORTS BLA BLA SHOP NAME BLA BLA: " << endl;
	cout << "1. Inventory Listing " << endl
		<< "2. Inventory Wholesale Value" << endl
		<< "3. Inventory Retail Value" << endl
		<< "4. Listing by Quantity" << endl
		<< "5. Listing by Cost" << endl
		<< "6. Listing by Age" << endl
		<< "7. Return to Main Menu" << endl << endl
		<< "Enter Your Choice: ";
	cin >> selectReport;

	while (!(stoi(selectReport) >= ALL && stoi(selectReport) <= MAIN)){
		cout << "Your input is invalid. Please select between 1-9: ";
		cin >>selectReport;
	}

	return stoi(selectReport) - 48; //make ascii value of 1-9 (48-57) into 1-9

}// also get user to pick which report listing to display



//inventory listing default sort by title
void inventoryListing(int sortby, Books listing[], int size){


	Books * newBookArray = new Books[size];

	//copy array 
	for (int i = 0; i < size; i++){
		newBookArray[i] = listing[i];
	}

	for (int i = 0; i < size - 1; i++)
	{
		string temp = { '\0' };
		for (int j = 0; j < size - 1; j++)
		{
			if (newBookArray[j].getTitle()> newBookArray[j + 1].getTitle())
			{
				temp = newBookArray[j].getTitle();
				newBookArray[j].setTitle(newBookArray[j + 1].getTitle()) ;
				newBookArray[j + 1].setTitle(temp);
			}
		}
	}

	for (int i = 0; i < size; i++){
		displayInventoryListing(newBookArray[i]);
	}

	delete[] newBookArray;
	newBookArray = nullptr;
}

void displayInventoryListing(Books oneBook){
	//yet to decide display format.
	cout << setw(15) << left << oneBook.getIsbn();
	cout << setw(20) << left << oneBook.getTitle();
	cout << setw(20) << left << oneBook.getAuthor();
	cout << setw(20) << left << oneBook.getPublisher() << endl;
}


/*
void setIsbn(string);
void setTitle(string);
void setAuthor(string);
void setPublisher(string);
void setDateAdded(string);
void setQuantity(int);
void setCost(double);
void setPrice(double);

string getIsbn();
string getTitle();
string getAuthor();
string getPublisher();
string getDateAdded();
int getQuantity();
double getCost();
double getPrice();

*/

/*

<< "1. Inventory Listing " << endl
<< "2. Inventory Wholesale Value" << endl
<< "3. Inventory Retail Value" << endl
<< "4. Listing by Quantity" << endl
<< "5. Listing by Cost" << endl
<< "6. Listing by Age" << endl
<< "7. Return to Main Menu
*/

#endif