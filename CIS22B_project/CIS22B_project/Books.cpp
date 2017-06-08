Books.cpp
DETAILS
ACTIVITY
Books.cpp
Sharing Info
J

General Info
Type
Text
Size
1 KB(1, 458 bytes)
Storage used
0 bytesOwned by someone else
Location
BookProject
Owner
John Vu
Modified
2:47 PM by John Vu
Created
2 : 47 PM
Description
Add a description
Download permissions
Viewers can download


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