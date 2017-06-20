#include "BookInformationMenu.h"
#include "Books.h"
#include "BookSearch.h"

#include <iostream>

BookInformationMenu::BookInformationMenu(Books mb[], int nb)
{
	numBooks = nb;
	for (int i; i < nb; i++)
		myBooks[i] = mb[i];
}

void BookInformationMenu::InventoryMenuScreen()
{
	const int MAX_BOOKS = 50;
	Books resultSearchBooks[MAX_BOOKS];
	int resultSearchNumBooks = 0;
	int option;
	cout << endl << "************Inventory Database*************" << endl;
	cout << "1. Look Up a Book" << endl;
	cout << "2. Add a Book" << endl;
	cout << "3. Edit a Book's Record" << endl;
	cout << "4. Delete a Book" << endl;
	cout << "5 Return to the Main Menu" << endl;
	cout << endl << "Enter Your Coice: " << endl;
	cin >> option;
	if (option == 1)
	{
		findBook();
		DisplayBookInformation();
	}//Look up a book.
	if (option == 2)
	{
		findBook();

	} // Add a book.
	if (option == 3)
	{
		findBook();

	} //Edit a Book.
	if (option == 4)
	{
		findBook();

	} //Delete a Book.
	if (option == 5)
	{

	} //Return to main menu.
}

void BookInformationMenu::DisplayBookInformation()
{
	for (int i = 0; i < resultBooksNum; i += 0)
	{
		cout << "**************************************" << endl;
		cout << "ISBN: " << resultBooks[i].getIsbn() << endl;
		cout << "Book title: " << resultBooks[i].getTitle() << endl;
		cout << "Author: " << resultBooks[i].getAuthor() << endl;
		cout << "Publisher: " << resultBooks[i].getPublisher() << endl;
		cout << "Date added: " << resultBooks[i].getDateAdded() << endl;
		cout << "Quantity: " << resultBooks[i].getQuantity() << endl;
		cout << "Wholesale cost: " << resultBooks[i].getCost() << endl;
		cout << "Price: " << resultBooks[i].getPrice() << endl;
	}
};

void BookInformationMenu::findBook()
{
	SearchBy queryType[9] = { SearchByIsbn, SearchByTitle, SearchByAuthor, SearchByPublisher, SearchByDateAdded, SearchByQuantity, SearchByCost, SearchByPrice  };
	string query;
	int menu;
	cout << endl << "How would you like to select your book?" << endl << endl;
	cout << "1. Search by ISBN" << endl <<
		"2. Search by title" << endl <<
		"3. Search by author" << endl <<
		"4. Search by publisher" << endl <<
		"5. Search by date added" << endl <<
		"6. Search by quantity" << endl <<
		"7. Search by wholesale cost" << endl <<
		"8. Search by price" << endl << endl << "Please enter the number of your selection: ";
	cin >> menu;
	cout << endl << "Now enter exactly the the value you want to search for (The search is case sensitive): ";
	cin >> query;
	books = searchBook(resultBooks, resultBooksNum, myBooks, numBooks, queryType[menu - 1], query);
}