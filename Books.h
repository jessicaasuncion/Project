#ifndef BOOKS_H
#define BOOKS_H
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

// Global constants
const char DELIMITOR = '|';
const int MAX_BOOKS = 50;

enum MAIN_MENU_CHOICE { CASHIER_MOD = 1, INVENTORY_MOD, REPORT_MOD, EXIT_PROGRAM };

class Books
{
private:
	string isbn;
	string title;
	string author;
	string publisher;
	string dateAdded;		// Format YYYYMMDD
	int quantity;
	double cost;
	double price;

public:
	Books();
	Books(string, string, string, string, string, int, double, double);
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

	friend ostream &operator << (ostream &output, const Books &B) {
		output << B.title;
		return output;
	}
};

// Function prototype
int displayMainMenu();
int readDataFile(Books[], string);
int writeDataFile(Books[], string, int);

#endif 