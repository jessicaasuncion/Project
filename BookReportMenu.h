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
#include <fstream>
#include <iostream>
#include <iomanip>

#include "Books.h"
//Main Report Screen
void reportMenu(Books[], int);
int displayReportMenu();// get user to pick which report listing to display

//functions for all listings sort
void inventoryListing(Books[], int); //sort by title
void wholesaleListing(Books[], int); //sort by unit wholesale value
void retailListing(Books[], int);//sort by unit retail value
void quantityListing(Books[], int);//sort by quantity on hand
void costListing(Books[], int);//sort by unit cost
void ageListing(Books[], int);//sort by age

//functions for display listings
void listingTitle(int);
void displayInventoryListing(Books);//A list of information on all books in the inventory.
void displayWholesale(Books);//A list of the wholesale value of all books in the inventory and the total wholesale value of the inventory.
void displayRetail(Books); //A list of the retail value of all books in the inventory and the total retail value of the inventory.
void displayQuantity(Books); //  A list of all books in the inventory sorted by quantity on hand.
void displayCost(Books); // A list of all books in the inventory, sorted by wholesale cost
void displayAge(Books); //A list of all books in the inventory, sorted by purchase date.

//function for saving individual listing to output file
void saveOutput(int, Books[], int);

enum REPORT { ALL = 1, WHOLESALE, RETAIL, QUANTITY, COST, AGE, MAIN };

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
		cout << "You will be redirected to Main Menu soon.";
		system("pause");
		break;
	}

}

int displayReportMenu(){
	int selectReport = 0;
	cout << "Serendipity Booksellers Report Listing: " << endl;
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
		cin >> selectReport;
	}

	return selectReport;

}


//Sort listing
void inventoryListing(Books listing[], int size){

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
				newBookArray[j] = newBookArray[j + 1];
				newBookArray[j + 1] = temp;
			}
		}
	}
	//display
	listingTitle(ALL);
	for (int i = 0; i < size; i++){
		displayInventoryListing(listing[i]);
	}
	// ask user if to save report to output file
	saveOutput(ALL, newBookArray, size);
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
		Books temp;
		for (int j = 0; j < size - 1; j++)
		{
			//get the total wholesale value of each title by cost*quantity
			double totalWholesale1 = newBookArray[j].getCost() * newBookArray[j].getQuantity();
			double totalWholesale2 = newBookArray[j + 1].getCost() * newBookArray[j + 1].getQuantity();
			if (toSwap(totalWholesale1, totalWholesale1))
			{
				temp = newBookArray[j];
				newBookArray[j] = newBookArray[j + 1];
				newBookArray[j + 1] = temp;
			}
		}
	}
	listingTitle(WHOLESALE);
	double totalWholesaleValue = 0.0;
	for (int i = 0; i < size; i++){
		displayWholesale(newBookArray[i]);
		totalWholesaleValue += productOf(newBookArray[i].getCost(), newBookArray[i].getQuantity());

	}
	cout << endl<< setprecision(2) << fixed << "\nTotal Wholesale value of the inventory is: $" << totalWholesaleValue << endl;

	saveOutput(WHOLESALE, newBookArray, size);
	
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
	listingTitle(RETAIL);
	double totalRetailValue = 0.0;
	for (int i = 0; i < size; i++){
		displayRetail(newBookArray[i]);
		totalRetailValue += productOf(newBookArray[i].getPrice(), newBookArray[i].getQuantity());
	}
	cout << setprecision(2) << fixed << "\nTotal Retail value of the inventory is: $" << totalRetailValue << endl;

	saveOutput(RETAIL, newBookArray, size);

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
			if (toSwap(newBookArray[j + 1].getQuantity(), newBookArray[j].getQuantity()))
			{
				temp = newBookArray[j];
				newBookArray[j] = newBookArray[j + 1];
				newBookArray[j + 1] = temp;
			}
		}
	}
	listingTitle(QUANTITY);
	int totalQuantity = 0;
	for (int i = 0; i < size; i++){
		displayQuantity(newBookArray[i]);
		totalQuantity = (int)productOf(newBookArray[i].getQuantity(), 1);
	}

	saveOutput(QUANTITY, newBookArray, size);

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
			if (toSwap(newBookArray[j + 1].getCost(), newBookArray[j].getCost()))
			{
				temp = newBookArray[j];
				newBookArray[j] = newBookArray[j + 1];
				newBookArray[j + 1] = temp;
			}
		}
	}
	listingTitle(COST);
	for (int i = 0; i < size; i++){
		displayCost(newBookArray[i]);
	}

	saveOutput(COST, newBookArray, size);

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
		Books temp;
		for (int j = 0; j < size - 1; j++)
		{
			if (toSwap(newBookArray[j ].getDateAdded(), newBookArray[j+1].getDateAdded()))
			{
				temp = newBookArray[j];
				newBookArray[j] = newBookArray[j + 1];
				newBookArray[j + 1] = temp;
			}
		}
	}
	listingTitle(AGE);
	for (int i = 0; i < size; i++){
		displayAge(newBookArray[i]);
	}

	saveOutput(AGE, newBookArray, size);

	delete[] newBookArray;
	newBookArray = nullptr;
}

//display listing
//ALL = 1, WHOLESALE, RETAIL, QUANTITY, COST, AGE,
void listingTitle(int titleStyle) {
	switch (titleStyle){
	case ALL:
		cout << setw(12) << left << "ISBN" << setw(4) << "";
		cout << setw(40) << left << "Title" << setw(4) << "";
		cout << setw(20) << left << "Author" << setw(4) << "";
		cout << setw(20) << left << "Publisher" << setw(4) << "";
		cout << setw(10) << left << "Quantity" << setw(4) << "";
		cout << setw(10) << left << "Cost" << setw(4) << "";
		cout << setw(10) << left << "Price" << setw(4) << "";
		cout << setw(10) << left << "Date Added (YYYYMMDD)" << "";
		cout << endl;
		break;

	case WHOLESALE:
		cout << setw(12) << left << "ISBN" << setw(4) << "";
		cout << setw(40) << left << "Title" << setw(4) << "";
		cout << setw(20) << left << "Author" << setw(4) << "";
		cout << setw(20) << left << "Publisher" << setw(4) << "";
		cout << setw(10) << left << "Quantity" << setw(4) << "";
		cout << setw(10) << left << "Cost" << setw(4) << "";
		cout << endl;
		break;

	case QUANTITY:
		cout << setw(12) << left << "ISBN" << setw(4) << "";
		cout << setw(40) << left << "Title" << setw(4) << "";
		cout << setw(20) << left << "Author" << setw(4) << "";
		cout << setw(20) << left << "Publisher" << setw(4) << "";
		cout << setw(10) << left << "Quantity" << setw(4) << "";
		cout << endl;
		break;

	case AGE:
		cout << setw(12) << left << "ISBN" << setw(4) << "";
		cout << setw(40) << left << "Title" << setw(4) << "";
		cout << setw(20) << left << "Author" << setw(4) << "";
		cout << setw(20) << left << "Publisher" << setw(4) << "";
		cout << setw(10) << left << "Quantity" << setw(4) << "";
		cout << setw(10) << left << "Date Added (YYYYMMDD)" << setw(4) << "";
		cout << endl;
		break;
	case RETAIL:
		cout << setw(12) << left << "ISBN" << setw(4) << "";
		cout << setw(40) << left << "Title" << setw(4) << "";
		cout << setw(20) << left << "Author" << setw(4) << "";
		cout << setw(20) << left << "Publisher" << setw(4) << "";
		cout << setw(10) << left << "Quantity" << setw(4) << "";
		cout << setw(10) << left << "Price" << setw(4) << "";
		cout << endl;
		break;

	case COST: 
		cout << setw(12) << left << "ISBN" << setw(4) << "";
		cout << setw(40) << left << "Title" << setw(4) << "";
		cout << setw(20) << left << "Author" << setw(4) << "";
		cout << setw(20) << left << "Publisher" << setw(4) << "";
		cout << setw(10) << left << "Quantity" << setw(4) << "";
		cout << setw(10) << left << "Cost" << setw(4) << "";
		cout << endl;
		break;
	}

}

void displayInventoryListing(Books oneBook){
	//yet to decide display format.
	cout << setw(12) << left << oneBook.getIsbn() << setw(4) << "";
	cout << setw(40) << left << oneBook.getTitle() << setw(4) << "";
	cout << setw(20) << left << oneBook.getAuthor() << setw(4) << "";
	cout << setw(20) << left << oneBook.getPublisher() << setw(4) << "";
	cout << setw(10) << left << oneBook.getQuantity() << setw(4) << ""; 
	cout << setw(10) << left << oneBook.getCost() << setw(4) << "";
	cout << setw(10) << left << oneBook.getPrice() << setw(4) << ""; 
	cout << setw(10) << left << oneBook.getDateAdded() << setw(4) << "";
	cout << endl;
}

void displayWholesale(Books oneBook)
{
	cout << setw(12) << left << oneBook.getIsbn() << setw(4) << "";
	cout << setw(40) << left << oneBook.getTitle() << setw(4) << "";
	cout << setw(20) << left << oneBook.getAuthor() << setw(4) << "";
	cout << setw(20) << left << oneBook.getPublisher() << setw(4) << "";
	cout << setw(10) << left << oneBook.getQuantity() << setw(4) << "";
	cout << setw(10) << left << oneBook.getCost() << setw(4) << "";
	cout << endl;
}

void displayRetail(Books oneBook)
{
	cout << setw(12) << left << oneBook.getIsbn() << setw(4) << "";
	cout << setw(40) << left << oneBook.getTitle() << setw(4) << "";
	cout << setw(20) << left << oneBook.getAuthor() << setw(4) << "";
	cout << setw(20) << left << oneBook.getPublisher() << setw(4) << "";
	cout << setw(10) << left << oneBook.getQuantity() << setw(4) << "";
	cout << setw(10) << left << oneBook.getPrice() << setw(4) << "";
	cout << endl;
}

void displayQuantity(Books oneBook)
{
	cout << setw(12) << left << oneBook.getIsbn() << setw(4) << "";
	cout << setw(40) << left << oneBook.getTitle() << setw(4) << "";
	cout << setw(20) << left << oneBook.getAuthor() << setw(4) << "";
	cout << setw(20) << left << oneBook.getPublisher() << setw(4) << "";
	cout << setw(10) << left << oneBook.getQuantity() << setw(4) << "";
	cout << endl;
};

void displayCost(Books oneBook)
{
	cout << setw(12) << left << oneBook.getIsbn() << setw(4) << "";
	cout << setw(40) << left << oneBook.getTitle() << setw(4) << "";
	cout << setw(20) << left << oneBook.getAuthor() << setw(4) << "";
	cout << setw(20) << left << oneBook.getPublisher() << setw(4) << "";
	cout << setw(10) << left << oneBook.getQuantity() << setw(4) << "";
	cout << setw(10) << left << oneBook.getCost() << setw(4) << "";
	cout << endl;
};

void displayAge(Books oneBook)
{
	cout << setw(12) << left << oneBook.getIsbn() << setw(4) << "";
	cout << setw(40) << left << oneBook.getTitle() << setw(4) << "";
	cout << setw(20) << left << oneBook.getAuthor() << setw(4) << "";
	cout << setw(20) << left << oneBook.getPublisher() << setw(4) << "";
	cout << setw(10) << left << oneBook.getQuantity() << setw(4) << "";
	cout << setw(10) << left << oneBook.getDateAdded() << setw(4) << "";
	cout << endl;
}

void saveOutput(int listingOption, Books listing[], int size){
	char confirm = '\0';
	cout << "Do you want to save this listing to a file? (Y/N): ";
	cin >> confirm;
	while (confirm != 'n' && confirm != 'N' && confirm != 'y' && confirm != 'Y'){
		cout << "Invalid input, please enter Y/N: ";
		cin >> confirm;
	}

	if (confirm == 'y' || confirm == 'Y'){
		ofstream reportOutput;
		string fileName = "";
		double totalValue = 0;
		switch (listingOption){
		case ALL:
			fileName = "InventoryListing.txt";
			reportOutput.open(fileName);
			reportOutput << setw(12) << left << "ISBN" << setw(4) << "";
			reportOutput << setw(40) << left << "Title" << setw(4) << "";
			reportOutput << setw(20) << left << "Author" << setw(4) << "";
			reportOutput << setw(20) << left << "Publisher" << setw(4) << "";
			reportOutput << setw(10) << left << "Quantity" << setw(4) << "";
			reportOutput << setw(10) << left << "Cost" << setw(4) << "";
			reportOutput << setw(10) << left << "Price" << setw(4) << "";
			reportOutput << setw(10) << left << "Date Added (YYYYMMDD)" << "";
			reportOutput << endl;
			for (int i = 0; i < size; i++){
				reportOutput << setw(12) << left << listing[i].getIsbn() << setw(4) << "";
				reportOutput << setw(40) << left << listing[i].getTitle() << setw(4) << "";
				reportOutput << setw(20) << left << listing[i].getAuthor() << setw(4) << "";
				reportOutput << setw(20) << left << listing[i].getPublisher() << setw(4) << "";
				reportOutput << setw(10) << left << listing[i].getQuantity() << setw(4) << "";
				reportOutput << setw(10) << left << listing[i].getCost() << setw(4) << "";
				reportOutput << setw(10) << left << listing[i].getPrice() << setw(4) << "";
				reportOutput << setw(10) << left << listing[i].getDateAdded() << setw(4) << "";
				reportOutput << endl;
			}
			
			break;

		case WHOLESALE:
			
			fileName = "InventoryWholesaleValue.txt";
			reportOutput.open(fileName);
			reportOutput << setw(12) << left << "ISBN" << setw(4) << "";
			reportOutput << setw(40) << left << "Title" << setw(4) << "";
			reportOutput << setw(20) << left << "Author" << setw(4) << "";
			reportOutput << setw(20) << left << "Publisher" << setw(4) << "";
			reportOutput << setw(10) << left << "Quantity" << setw(4) << "";
			reportOutput << setw(10) << left << "Cost" << setw(4) << "";
			reportOutput << endl;
			for (int i = 0; i < size; i++){
				totalValue += productOf(listing[i].getQuantity(), listing[i].getCost());
				reportOutput << setw(12) << left << listing[i].getIsbn() << setw(4) << "";
				reportOutput << setw(40) << left << listing[i].getTitle() << setw(4) << "";
				reportOutput << setw(20) << left << listing[i].getAuthor() << setw(4) << "";
				reportOutput << setw(20) << left << listing[i].getPublisher() << setw(4) << "";
				reportOutput << setw(10) << left << listing[i].getQuantity() << setw(4) << "";
				reportOutput << setw(10) << left << listing[i].getCost() << setw(4) << "";
				reportOutput << endl;
			}
			reportOutput << endl << setprecision(2) << fixed << "\nTotal Wholesale value of the inventory is: $" << totalValue << endl;
			break;
		case RETAIL:

			fileName = "InventoryRetailValue.txt";
			reportOutput.open(fileName);
			reportOutput << setw(12) << left << "ISBN" << setw(4) << "";
			reportOutput << setw(40) << left << "Title" << setw(4) << "";
			reportOutput << setw(20) << left << "Author" << setw(4) << "";
			reportOutput << setw(20) << left << "Publisher" << setw(4) << "";
			reportOutput << setw(10) << left << "Quantity" << setw(4) << "";
			reportOutput << setw(10) << left << "Price" << setw(4) << "";
			reportOutput << endl;
			totalValue = 0.0;
			for (int i = 0; i < size; i++){
				reportOutput << setw(12) << left << listing[i].getIsbn() << setw(4) << "";
				reportOutput << setw(40) << left << listing[i].getTitle() << setw(4) << "";
				reportOutput << setw(20) << left << listing[i].getAuthor() << setw(4) << "";
				reportOutput << setw(20) << left << listing[i].getPublisher() << setw(4) << "";
				reportOutput << setw(10) << left << listing[i].getQuantity() << setw(4) << "";
				reportOutput << setw(10) << left << listing[i].getPrice() << setw(4) << "";
				reportOutput << endl;
				totalValue += productOf(listing[i].getPrice(), listing[i].getQuantity());
			}
			reportOutput << setprecision(2) << fixed << "\nTotal Retail value of the inventory is: $" << totalValue << endl;
			break;
		case AGE:
			fileName = "ListByAge.txt";
			reportOutput.open(fileName);
			reportOutput << setw(12) << left << "ISBN" << setw(4) << "";
			reportOutput << setw(40) << left << "Title" << setw(4) << "";
			reportOutput << setw(20) << left << "Author" << setw(4) << "";
			reportOutput << setw(20) << left << "Publisher" << setw(4) << "";
			reportOutput << setw(10) << left << "Quantity" << setw(4) << "";
			reportOutput << setw(10) << left << "Date Added (YYYYMMDD)" << setw(4) << "";
			reportOutput << endl;
			for (int i = 0; i < size; i++){
				reportOutput << setw(12) << left << listing[i].getIsbn() << setw(4) << "";
				reportOutput << setw(40) << left << listing[i].getTitle() << setw(4) << "";
				reportOutput << setw(20) << left << listing[i].getAuthor() << setw(4) << "";
				reportOutput << setw(20) << left << listing[i].getPublisher() << setw(4) << "";
				reportOutput << setw(10) << left << listing[i].getQuantity() << setw(4) << "";
				reportOutput << setw(10) << left << listing[i].getDateAdded() << setw(4) << "";
				reportOutput << endl;
			}
			break;
		case COST:
			fileName = "ListByCost.txt";
			reportOutput.open(fileName);
			reportOutput << setw(12) << left << "ISBN" << setw(4) << "";
			reportOutput << setw(40) << left << "Title" << setw(4) << "";
			reportOutput << setw(20) << left << "Author" << setw(4) << "";
			reportOutput << setw(20) << left << "Publisher" << setw(4) << "";
			reportOutput << setw(10) << left << "Quantity" << setw(4) << "";
			reportOutput << setw(10) << left << "Cost" << setw(4) << "";
			reportOutput << endl;
			for (int i = 0; i < size; i++){
				reportOutput << setw(12) << left << listing[i].getIsbn() << setw(4) << "";
				reportOutput << setw(40) << left << listing[i].getTitle() << setw(4) << "";
				reportOutput << setw(20) << left << listing[i].getAuthor() << setw(4) << "";
				reportOutput << setw(20) << left << listing[i].getPublisher() << setw(4) << "";
				reportOutput << setw(10) << left << listing[i].getQuantity() << setw(4) << "";
				reportOutput << setw(10) << left << listing[i].getCost() << setw(4) << "";
				reportOutput << endl;
			}
			break;
		case QUANTITY:
			fileName = "ListByQuantity.txt";
			reportOutput.open(fileName);
			reportOutput << setw(12) << left << "ISBN" << setw(4) << "";
			reportOutput << setw(40) << left << "Title" << setw(4) << "";
			reportOutput << setw(20) << left << "Author" << setw(4) << "";
			reportOutput << setw(20) << left << "Publisher" << setw(4) << "";
			reportOutput << setw(10) << left << "Quantity" << setw(4) << "";
			reportOutput << endl;
			for (int i = 0; i < size; i++){
				reportOutput << setw(12) << left << listing[i].getIsbn() << setw(4) << "";
				reportOutput << setw(40) << left << listing[i].getTitle() << setw(4) << "";
				reportOutput << setw(20) << left << listing[i].getAuthor() << setw(4) << "";
				reportOutput << setw(20) << left << listing[i].getPublisher() << setw(4) << "";
				reportOutput << setw(10) << left << listing[i].getQuantity() << setw(4) << "";
				reportOutput << endl;
			}
			
			break;
		}
		cout << "The file has been saved as " << fileName << endl;
		reportOutput.close();
		cout << "You will be redirected back to Main Menu soon." << endl;
		system("pause");
	}
	else if (confirm == 'n' || confirm == 'N'){
		cout << "You will be redirected back to Main Menu soon." << endl;
		system("pause");
		
	}
}


#endif

//inventory retail value - total value line add endl
//isbn setw