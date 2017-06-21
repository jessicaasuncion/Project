/*
how to use:
reportMenu(Books[] , int);
argument Books[] : pass in the original book array
argumment int: pass in the number of the book in the array. DO NOT pass in max size if the array is not full.

pending: displayMainMenu()
i will need to include this if user choose to return to main menu

*/

#define _CRT_SECURE_NO_WARNINGS

#ifndef BOOK_REPORT_MENU_H
#define BOOK_REPORT_MENU_H

#include <iostream>
#include <iomanip>

#include "Books.h"

void reportMenu(Books[], int);
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

template <class T1, class T2>
double productOf(T1 num1, T2 num2){

	return (num1*num2);
}

template <class T1>
bool toSwap(T1 input1, T1 input2){
	if (input1 > input2){
		return true;
	}
	return false;
}

void reportMenu(Books myBooks[], int size){
	int reportType = displayReportMenu();


	switch (reportType)  {
	case ALL:

		inventoryListing(myBooks, size);
		break;
	case WHOLESALE:
		wholesaleListing(myBooks, size);
		break;
	case RETAIL:
		retailListing(myBooks, size);
		break;
	case QUANTITY:
		quantityListing(myBooks, size);
		break;
	case COST:
		costListing(myBooks, size);
		break;
	case AGE:
		ageListing(myBooks, size);
		break;
	case MAIN:
		//display Main Menu();
		break;


	}
}

int displayReportMenu(){
	int selectReport = 0;
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

	while (selectReport <= ALL && selectReport >= MAIN){
		cout << "Your input is invalid. Please select between 1-7: ";
		cin >>selectReport;
	}

	return selectReport;

}


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
			if (toSwap(newBookArray[j].getTitle(), newBookArray[j + 1].getTitle()))
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
			if (toSwap(totalWholesale1, totalWholesale1))
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
		totalWholesaleValue += productOf(newBookArray[i].getCost(),newBookArray[i].getQuantity());
		
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
			if (toSwap(newBookArray[j].getPrice(), newBookArray[j + 1].getPrice()))
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
		totalRetailValue += productOf(newBookArray[i].getPrice() , newBookArray[i].getQuantity());
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
			if (toSwap(newBookArray[j+1].getQuantity(), newBookArray[j ].getQuantity()))
			{
				temp = newBookArray[j];
				newBookArray[j] = newBookArray[j + 1];
				newBookArray[j + 1] = temp ;
			}
		}
	}
	int totalQuantity = 0;
	for (int i = 0; i < size; i++){
		displayQuantity(newBookArray[i]);
		totalQuantity = (int)productOf(newBookArray[i].getQuantity(), 1);
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
			if (toSwap(newBookArray[j+1].getCost(), newBookArray[j ].getCost()))
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
			if (toSwap(newBookArray[j+1].getDateAdded(), newBookArray[j].getDateAdded()))
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