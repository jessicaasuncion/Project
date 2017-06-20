#define _CRT_SECURE_NO_WARNINGS

#ifndef BOOK_REPORT_MENU_H
#define BOOK_REPORT_MENU_H

#include <iostream>
#include <iomanip>

#include "Books.h"

int displayReportMenu();// get user to pick which report listing to display
//functions for all listings
void inventoryListing(Books[], int); //sort by title
void wholesaleListing( Books[], int); //sort by unit wholesale value
void retailListing( Books[], int);//sort by unit retail value
void quantityListing( Books[], int);//sort by quantity on hand
void costListing(Books[], int);//sort by unit cost
void ageListing( Books[], int);//sort by age

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


//Sort listing
void inventoryListing( Books listing[], int size){

	//create a Book array to store sorted information
	Books * newBookArray = new Books[size];

	//first copy from origninal array 
	for (int i = 0; i < size; i++){
		newBookArray[i] = listing[i];
	}
	//sort by title
	for (int i = 0; i < size - 1; i++)
	{
		Books temp;
		for (int j = 0; j < size - 1; j++)
		{
			if (newBookArray[j].getTitle()> newBookArray[j + 1].getTitle())
			{
				temp = newBookArray[j];
				newBookArray[j]=newBookArray[j + 1] ;
				newBookArray[j + 1]=temp;
			}
		}
	}
	//display
	for (int i = 0; i < size; i++){
		displayInventoryListing(newBookArray[i]);
	}
	//delete dynamic allocation
	delete[] newBookArray;
	newBookArray = nullptr;
}

void wholesaleListing(Books listing[], int size){

	Books * newBookArray = new Books[size];

	for (int i = 0; i < size; i++){
		newBookArray[i] = listing[i];
	}

	for (int i = 0; i < size - 1; i++)
	{
		Books temp ;
		for (int j = 0; j < size - 1; j++)
		{
			//get the total wholesale value of each title by cost*quantity
			double totalWholesale1 = newBookArray[j].getCost() * newBookArray[j].getQuantity();
			double totalWholesale2 = newBookArray[j + 1].getCost() * newBookArray[j + 1].getQuantity();
			if (totalWholesale1> totalWholesale1)
			{
				temp = newBookArray[j];
				newBookArray[j]=newBookArray[j + 1];
				newBookArray[j + 1]=temp;
			}
		}
	}
	double totalWholesaleValue = 0.0;
	for (int i = 0; i < size; i++){
		displayWholesale(newBookArray[i]);
		totalWholesaleValue += (newBookArray[i].getCost() * newBookArray[i].getQuantity());
		
	}
	cout << setprecision(2) << fixed << "Total Wholesale value of the inventory is: $" << totalWholesaleValue << endl;
	

	delete[] newBookArray;
	newBookArray = nullptr;
}

void retailListing(Books listing[], int size){

	Books * newBookArray = new Books[size];

	for (int i = 0; i < size; i++){
		newBookArray[i] = listing[i];
	}

	for (int i = 0; i < size - 1; i++)
	{
		Books temp;
		for (int j = 0; j < size - 1; j++)
		{
			if (newBookArray[j].getPrice()> newBookArray[j + 1].getPrice())
			{
				temp = newBookArray[j];
				newBookArray[j] = newBookArray[j + 1];
				newBookArray[j + 1] = temp;
			}
		}
	}
	double totalRetailValue = 0.0;
	for (int i = 0; i < size; i++){
		displayRetail(newBookArray[i]);
		totalRetailValue += (newBookArray[i].getPrice() * newBookArray[i].getQuantity());
	}
	cout << setprecision(2) << fixed << "Total Wholesale value of the inventory is: $" << totalRetailValue << endl;
	delete[] newBookArray;
	newBookArray = nullptr;
}

void quantityListing(Books listing[], int size){

	Books * newBookArray = new Books[size];

	for (int i = 0; i < size; i++){
		newBookArray[i] = listing[i];
	}

	for (int i = 0; i < size - 1; i++)
	{
		Books temp;
		for (int j = 0; j < size - 1; j++)
		{
			if (newBookArray[j].getQuantity()< newBookArray[j + 1].getQuantity())
			{
				temp = newBookArray[j];
				newBookArray[j] = newBookArray[j + 1];
				newBookArray[j + 1] = temp ;
			}
		}
	}

	for (int i = 0; i < size; i++){
		displayQuantity(newBookArray[i]);
	}
	

	delete[] newBookArray;
	newBookArray = nullptr;
}

void costListing(Books listing[], int size){

	Books * newBookArray = new Books[size];

	for (int i = 0; i < size; i++){
		newBookArray[i] = listing[i];
	}

	for (int i = 0; i < size - 1; i++)
	{
		Books temp;
		for (int j = 0; j < size - 1; j++)
		{
			if (newBookArray[j].getCost()< newBookArray[j + 1].getCost())
			{
				temp = newBookArray[j];
				newBookArray[j] = newBookArray[j + 1];
				newBookArray[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < size; i++){
		displayCost(newBookArray[i]);
	}

	delete[] newBookArray;
	newBookArray = nullptr;
}

void ageListing(Books listing[], int size){

	Books * newBookArray = new Books[size];

	for (int i = 0; i < size; i++){
		newBookArray[i] = listing[i];
	}

	for (int i = 0; i < size - 1; i++)
	{
		Books temp ;
		for (int j = 0; j < size - 1; j++)
		{
			if (newBookArray[j].getDateAdded()< newBookArray[j + 1].getDateAdded())
			{
				temp = newBookArray[j];
				newBookArray[j] = newBookArray[j + 1];
				newBookArray[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < size; i++){
		displayAge(newBookArray[i]);
	}

	delete[] newBookArray;
	newBookArray = nullptr;
}

//display listing
void displayInventoryListing(Books oneBook){
	//yet to decide display format.
	cout << setw(15) << left << oneBook.getIsbn();
	cout << setw(20) << left << oneBook.getTitle();
	cout << setw(20) << left << oneBook.getAuthor();
	cout << setw(20) << left << oneBook.getPublisher();
	cout<< setw(8) << left << oneBook.getQuantity() << endl;
}

void displayWholesale(Books oneBook)
{
	cout << setw(15) << left << oneBook.getIsbn();
	cout << setw(20) << left << oneBook.getTitle();
	cout << setw(20) << left << oneBook.getAuthor();
	cout << setw(20) << left << oneBook.getPublisher();
	cout << setw(20) << left << oneBook.getCost();
}

void displayRetail(Books oneBook)
{
	cout << setw(15) << left << oneBook.getIsbn();
	cout << setw(20) << left << oneBook.getTitle();
	cout << setw(20) << left << oneBook.getAuthor();
	cout << setw(20) << left << oneBook.getPublisher();
	cout << setw(20) << left << oneBook.getPrice() << endl;
}

void displayQuantity(Books oneBook)
{
	cout << setw(15) << left << oneBook.getIsbn();
	cout << setw(20) << left << oneBook.getTitle();
	cout << setw(20) << left << oneBook.getAuthor();
	cout << setw(20) << left << oneBook.getPublisher();
	cout << setw(20) << left << oneBook.getQuantity() << endl;
};

void displayCost(Books oneBook)
{
	cout << setw(15) << left << oneBook.getIsbn();
	cout << setw(20) << left << oneBook.getTitle();
	cout << setw(20) << left << oneBook.getAuthor();
	cout << setw(20) << left << oneBook.getPublisher();
	cout << setw(20) << left << oneBook.getCost()*oneBook.getQuantity() << endl;
};

void displayAge(Books oneBook)
{
	cout << setw(15) << left << oneBook.getIsbn();
	cout << setw(20) << left << oneBook.getTitle();
	cout << setw(20) << left << oneBook.getAuthor();
	cout << setw(20) << left << oneBook.getPublisher();

	cout << setw(20) << left << oneBook.getDateAdded() << endl;
}

#endif