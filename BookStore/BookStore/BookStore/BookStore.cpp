/* Book Store (Final Project)

Description: 

Authors:	

Date:

IDE Used: Visual Studio 2013
*/
#define _CRT_SECURE_NO_WARNINGS

#include "Books.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Global constants
const char DELIMITOR = '|';

// Function prototype
int readDataFile(Books[], string);
int writeDataFile(Books[], string, int);


//*****************************************************************
// Function main
// Psuedocode:
//
//
// Exit
//*****************************************************************

int main()
{
	const int MAX_BOOKS = 100;
	const string DATA_FILE = "Books.txt";		// Constant file name

	int numBooks = 0;
	Books myBooks[MAX_BOOKS];
	numBooks = readDataFile(myBooks, DATA_FILE);
	/******************************************* Remove after test */
	for (int i = 0; i < numBooks; ++i) {
		cout << myBooks[i].getIsbn() << "|" << myBooks[i].getTitle() << "|" << myBooks[i].getAuthor() <<
			myBooks[i].getPublisher() << "|" << myBooks[i].getDateAdded() << "|" << myBooks[i].getQuantity() << "|" <<
			myBooks[i].getCost() << "|" << myBooks[i].getPrice() << endl;
	}
	myBooks[2].setAuthor("John Vu");
	/***************************************************************/
	writeDataFile(myBooks, DATA_FILE, numBooks);
	
	return 0;
}

int readDataFile(Books books[], string fileName)
{
	const int OPEN_ERROR = -1;			// Constant cannot open file error code

	ifstream inputFile;					// Create an object for input file stream
	string inputStr;
	string token;
	string tmpStr[8];					// Temporary hold eight fields for each book 
	int index = 0;
	int counter = 0;

	// Open file for input
	inputFile.open(fileName);
	// Check to see if file opens successfully, if not return OPEN_ERROR code
	if (inputFile.fail()) {
		return OPEN_ERROR;
	}

	// Read data from the input file
	while (getline(inputFile, inputStr)) {
		index = 0;
		istringstream strStream(inputStr);
		while (getline(strStream, token, DELIMITOR)) {
			tmpStr[index++] = token;
		}
		books[counter].setIsbn(tmpStr[0]);
		books[counter].setTitle(tmpStr[1]);
		books[counter].setAuthor(tmpStr[2]);
		books[counter].setPublisher(tmpStr[3]);
		books[counter].setDateAdded(tmpStr[4]);
		books[counter].setQuantity(stoi(tmpStr[5]));
		books[counter].setCost(stod(tmpStr[6]));
		books[counter].setPrice(stod(tmpStr[7]));
		++counter;
	}
	// Close the input file
	inputFile.close();
	return counter;
}

int writeDataFile(Books books[], string fileName, int numBooks)
{
	const int OPEN_ERROR = -1;		// Constant cannot open file error code
	const int OPEN_OK = 1;			// Constant open and save file ok

	// Variable declaration
	int index = 0;
	string bookString;
	ofstream outfile;

	// Open file for output
	outfile.open(fileName);
	// Check to see if file opens successfully, if not return OPEN_ERROR code
	if (outfile.fail()) {
		return OPEN_ERROR;
	}

	// Save data to the file outfile
	for (index = 0; index < numBooks; ++index) {
		bookString = books[index].getIsbn() + DELIMITOR;
		bookString += books[index].getTitle() + DELIMITOR;
		bookString += books[index].getAuthor() + DELIMITOR;
		bookString += books[index].getPublisher() + DELIMITOR;
		bookString += books[index].getDateAdded() + DELIMITOR;
		bookString += to_string(books[index].getQuantity()) + DELIMITOR;
		bookString += to_string(books[index].getCost()) + DELIMITOR;
		bookString += to_string(books[index].getPrice());
		outfile << bookString << endl;
	}
	// Close the outfile
	outfile.close();
}