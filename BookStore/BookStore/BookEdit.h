#ifndef BOOK_EDIT_H
#define BOOK_EDIT_H

#include "Books.h"


void modifyISBN(Books*);
void modifyTitle(Books*);
void modifyAuthor(Books*);
void modifyPublisher(Books*);
void modifyDate(Books*);
void modifyQuantity(Books*);
void modifyCost(Books*);
void modifyPrice(Books*);
int displayChangesMenu();
void editBook(Books*);

enum FIELD { ISBN = 1, TITLE, AUTHOR, PUBLISHER, DATEADDED, QUANTITY, COST, PRICE, BACKTOMAIN };

#endif