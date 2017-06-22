#ifndef CASHIER_H
#define CASHIER_H
#include "Books.h"

using namespace std;

const double TAXRATE = 0.09;

class Cashier 
{
private:
	Books *book;
	int numBooks;			// quantity of book being purchased

public:
	Cashier(Books *);				// constructors
	Cashier(Books *, int);

	void setBook(Books *);
	void setNumBooks() const;
	void updateQuantity();			// update in books.h 

	int getNumBooks() const;		// get number of books wanted
	double getPrice() const;		// from books.h, price of each book
	double getQandP() const;		// qty * book = total for each book
	double getSubtotal() const;		// get subtotal 
	double getTax() const;			// tax rate * subtotal
	double getTotal() const;		// tax + subtotal 
	

};
#endif

