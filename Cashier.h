#ifndef CASHIER_H
#define CASHIER_H
#include "Books.h"

enum SearchBy {
	SearchByIsbn, SearchByTitle, SearchByAuthor, SearchByPublisher,
	SearchByDateAdded, SearchByQuantity, SearchByCost, SearchByPrice
};


// Function Prototype
int searchBook(Books[], int &, Books[], int, SearchBy, string);
void cashier(Books[],int);
void displayTotal(Books[], int[], int[]);

#endif
