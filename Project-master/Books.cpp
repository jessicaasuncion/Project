#define _CRT_SECURE_NO_WARNINGS
#include "Books.h"

Books::Books()
{
	isbn = "";
	title = "";
	author = "";
	publisher = "";
	dateAdded = "";		// Format YYYYMMDD
	quantity = 0;
	wholesale = 0.0;
	price = 0.0;
}
Books::Books(string inIsbn, string inTitle, string inAuthor, string inPublisher, string inDate,
	int inQuantity, double inWholesale, double inPrice)
{
	isbn = inIsbn;
	title = inTitle;
	author = inAuthor;
	publisher = inPublisher;
	dateAdded = inDate;		// Format YYYYMMDD
	quantity = inQuantity;
	wholesale = inWholesale;
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
void Books::setSold(int s)			// cashier
{
	sold = s;
}
void Books::setWholesale(double inWholesale)
{
	wholesale = inWholesale;
}
void Books::setPrice(double inPrice)
{
	price = inPrice;
}
void Books::record(int s)			// for cashier
{
	sold += s;
	quantity -= s;
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
double Books::getWholesale()
{
	return wholesale;
}
double Books::getPrice()
{
	return price;
}
