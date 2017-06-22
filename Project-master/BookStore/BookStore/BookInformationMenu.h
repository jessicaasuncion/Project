#ifndef BOOKINFORMATIONMENU_H
#define BOOKINFORMATIONMENU_H
#include <string>
#include <iomanip>
#include <iostream>
#include "Books.h"
#include "BookSearch.h"
#include "BooksFound.h"

using namespace std;

class BookInformationMenu
{
private:
	Books myBooks[50], resultBooks[50];
	int numBooks, resultBooksNum, index[50], indexFound;
	BooksFound books;

public:
	BookInformationMenu(Books mb[], int nb);
	void InventoryMenuScreen();
	void DisplayBookInformation();
	void findBook();
};
#endif 

