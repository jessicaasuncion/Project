#ifndef BOOK_SEARCH_H
#define BOOK_SEARCH_H

#include "Books.h"

enum SearchBy { SearchByIsbn, SearchByTitle, SearchByAuthor, SearchByPublisher, 
	SearchByDateAdded, SearchByQuantity, SearchByCost, SearchByPrice };

BooksFound searchBook(Books[], int &, Books[], int, SearchBy, string);

#endif