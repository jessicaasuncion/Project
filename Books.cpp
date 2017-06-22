#include "Books.h"

Books::Books()
{
	isbn = "";
	title = "";
	author = "";
	publisher = "";
	dateAdded = "";		// Format YYYYMMDD
	quantity = 0;
	cost = 0.0;
	price = 0.0;
}
Books::Books(string inIsbn, string inTitle, string inAuthor, string inPublisher, string inDate,
	int inQuantity, double inCost, double inPrice)
{
	isbn = inIsbn;
	title = inTitle;
	author = inAuthor;
	publisher = inPublisher;
	dateAdded = inDate;		// Format YYYYMMDD
	quantity = inQuantity;
	cost = inCost;
	price = inPrice;
}
void Books::setIsbn(string inIsbn)
{
	isbn = inIsbn;
}
void Books::setTitle(string inTitle)
{
	title = inTitle;
}
void Books::setAuthor(string inAuthor)
{
	author = inAuthor;
}
void Books::setPublisher(string inPublisher)
{
	publisher = inPublisher;
}
void Books::setDateAdded(string inDate)
{
	dateAdded = inDate;
}
void Books::setQuantity(int inQuantity)
{
	quantity = inQuantity;
}
void Books::setCost(double inCost)
{
	cost = inCost;
}
void Books::setPrice(double inPrice)
{
	price = inPrice;
}

string Books::getIsbn()
{
	return isbn;
}
string Books::getTitle()
{
	return title;
}
string Books::getAuthor()
{
	return author;
}
string Books::getPublisher()
{
	return publisher;
}
string Books::getDateAdded()
{
	return dateAdded;
}
int Books::getQuantity()
{
	return quantity;
}
double Books::getCost()
{
	return cost;
}
double Books::getPrice()
{
	return price;
}



//*****************************************************************
// Function displayMainMenu is to display the main menu, and wait
// for user to select a number (1 - 4).
//
// Parameters:
//		None
//
// Returns:
//		The integer the user selects
//
//*****************************************************************
int displayMainMenu() 
{
	int userChoice = 0;		// Menu choice from user's input

	cout << "\n\tSerendipity Booksellers" << endl
		<< "\t\tMain Menu" << endl << endl;
	cout << " 1. Cashier Module" << endl;
	cout << " 2. Inventory Database Module" << endl;
	cout << " 3. Report Module" << endl;
	cout << " 4. Exit" << endl << endl;
	cout << "Please enter a number of choice (1, 2, 3, or 4): ";
	cin >> userChoice;
	
	do
	{
		if (cin.fail() || (userChoice < 1 || userChoice > 4))
		{
			cout << "Invalid entry. Please reenter: ";
			cin.clear();
			cin.ignore();
			cin >> userChoice;
		}
	} while (userChoice < 1 || userChoice > 4);

	return userChoice;
}

//*****************************************************************
// Function readDataFile is to open a text file, read in the data,
// split each field on a record, then load the data into the myBooks
// array.
//
// Parameters:
//		Pointer to the myBooks array
//		String file name
//
// Returns:
//		Error code -1 if cannot open file
//		Number of records read in
//
//*****************************************************************
int readDataFile(Books books[], string fileName)
{
	const int OPEN_ERROR = -1;			// Constant cannot open file error code
	const int MAX_FIELD = 8;

	ifstream inputFile;					// Create an object for input file stream
	string inputStr;
	string token;
	string tmpStr[MAX_FIELD];			// Temporary hold eight fields for each book 
	int index = 0;
	int counter = 0;

	try
	{
		// Open file for input
		inputFile.open(fileName);
		// Check to see if file opens successfully, if not throw OPEN_ERROR code
		if (inputFile.fail()) {
			throw OPEN_ERROR;
		}

		// Read data from the input file
		while (getline(inputFile, inputStr)) {
			index = 0;
			istringstream strStream(inputStr);
			while (getline(strStream, token, DELIMITOR)) {
				tmpStr[index++] = token;		// Split the fields on each line by DELIMITOR
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
	}
	catch (int eCode)
	{
		return eCode;
	}

	return counter;
}

//*****************************************************************
// Function writeDataFile is to open or create a text file, write
// the data from myBooks array to the file.
//
// Parameters:
//		Pointer to the myBooks array
//		String file name
//		int number of books
//
// Returns:
//		Error code -1 if cannot open file
//		Code 1 if open and save successfully
//
//*****************************************************************
int writeDataFile(Books books[], string fileName, int numBooks)
{
	const int OPEN_ERROR = -1;		// Constant cannot open file error code
	const int OPEN_OK = 1;			// Constant open and save file ok

	// Variable declaration
	int index = 0;
	string bookString;
	ofstream outfile;

	try
	{
		// Open file for output
		outfile.open(fileName);
		// Check to see if file opens successfully, if not throw OPEN_ERROR code
		if (outfile.fail()) {
			throw OPEN_ERROR;
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
	catch (int eCode)
	{
		return eCode;
	}

	return OPEN_OK;
}