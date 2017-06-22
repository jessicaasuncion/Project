/* Book Store (Final Project)

Description: 

Authors:	

Date:

IDE Used: Visual Studio 2013
*/
#define _CRT_SECURE_NO_WARNINGS

#include "Cashier.h"
#include "Books.h"
#include "BookReportMenu.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;


//*****************************************************************
// Function main
// Psuedocode:
// Open file, read, then store data in myBooks array
// Display main menu, ask user to select an item to continue
// Save myBooks array to file
// Exit
//*****************************************************************

int main()
{
	const string DATA_FILE = "Books.txt";		// Constant file name

	int numBooks = 0;
	int userChoice = 0;
	Books myBooks[MAX_BOOKS];

	numBooks = readDataFile(myBooks, DATA_FILE);	// Read the data file and load to the main book array

	while (userChoice != EXIT_PROGRAM)				// Keep looping until user wishes to exit
	{
		userChoice = displayMainMenu();
		switch (userChoice)
		{
			case CASHIER_MOD:
				cashier(myBooks, numBooks);
				break;
			case INVENTORY_MOD:
			
				break;
			case REPORT_MOD:
				reportMenu(myBooks, numBooks);
				break;
			case EXIT_PROGRAM:
				writeDataFile(myBooks, DATA_FILE, numBooks);
				cout << "\nThank you for using the Serendipity Book Software.  Goodbye!" << endl;
				break;
		}
	}




	/******************************************* Remove after test */

	/*
	for (int i = 0; i < numBooks; ++i) {
		cout << myBooks[i].getIsbn() << "|" << myBooks[i].getTitle() << "|" << myBooks[i].getAuthor() << "|" <<
			myBooks[i].getPublisher() << "|" << myBooks[i].getDateAdded() << "|" << myBooks[i].getQuantity() << "|" <<
			myBooks[i].getCost() << "|" << myBooks[i].getPrice() << endl;
	}
	myBooks[2].setAuthor("John Vu"); 


	Books resultSearchBooks[MAX_BOOKS];
	int resultSearchNumBooks = 0;
	int indexFound = 0;
	indexFound = searchBook(resultSearchBooks, resultSearchNumBooks, myBooks, numBooks, SearchByAuthor, "John Vu");
	cout << "*************\n";
	cout << "indexFound = " << indexFound;
	for (int i = 0; i < resultSearchNumBooks; ++i) {
		cout << resultSearchBooks[i].getIsbn() << "|" << resultSearchBooks[i].getTitle() << "|" << resultSearchBooks[i].getAuthor() << "|" <<
			resultSearchBooks[i].getPublisher() << "|" << resultSearchBooks[i].getDateAdded() << "|" << resultSearchBooks[i].getQuantity() << "|" <<
			resultSearchBooks[i].getCost() << "|" << resultSearchBooks[i].getPrice() << endl;
	}

	resultSearchNumBooks = 0;
	indexFound = searchBook(resultSearchBooks, resultSearchNumBooks, myBooks, numBooks, SearchByIsbn, "7352864938");
	cout << "*************\n";
	cout << "indexFound = " << indexFound;
	for (int i = 0; i < resultSearchNumBooks; ++i) {
		cout << resultSearchBooks[i].getIsbn() << "|" << resultSearchBooks[i].getTitle() << "|" << resultSearchBooks[i].getAuthor() << "|" <<
			resultSearchBooks[i].getPublisher() << "|" << resultSearchBooks[i].getDateAdded() << "|" << resultSearchBooks[i].getQuantity() << "|" <<
			resultSearchBooks[i].getCost() << "|" << resultSearchBooks[i].getPrice() << endl;
	}

	resultSearchNumBooks = 0;
	indexFound = searchBook(resultSearchBooks, resultSearchNumBooks, myBooks, numBooks, SearchByPrice, "8.99");
	cout << "*************\n";
	cout << "indexFound = " << indexFound;
	for (int i = 0; i < resultSearchNumBooks; ++i) {
		cout << resultSearchBooks[i].getIsbn() << "|" << resultSearchBooks[i].getTitle() << "|" << resultSearchBooks[i].getAuthor() << "|" <<
			resultSearchBooks[i].getPublisher() << "|" << resultSearchBooks[i].getDateAdded() << "|" << resultSearchBooks[i].getQuantity() << "|" <<
			resultSearchBooks[i].getCost() << "|" << resultSearchBooks[i].getPrice() << endl;
	}
	
	/***************************************************************/

	
	return 0;
}
