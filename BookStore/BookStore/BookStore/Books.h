#ifndef BOOKS_H
#define BOOKS_H
#include <string>
using namespace std;

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
};
#endif 