#include "BookInformationMenu.h"
#include "Books.h"
#include "BookSearch.h"
#include "BookEdit.h"
#include "BookDelete.h"

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
		cout << endl << "*********************************************" << endl;
		cout << endl << "Do you wish to. . ." << endl <<
			" 1. Edit the above book(s)" << end <<
			" 2. Delete the above books(s)" << endl <<
			" 3. Return to the Inventory Database" << endl <<
			" 4. Return to Main Menu" << endl;
		cin >> option;
		if (option == 1)
		{
			for (int i = 0; i < books.getFound; i++)
			{
				enum FIELD { ISBN = 1, TITLE, AUTHOR, PUBLISHER, DATEADDED, QUANTITYONHAND, COSTVALUE, PRICE, BACKTOMAIN };
				int changeField = displayChangesMenu();//display option and ask for user option
				int bookIndex = books.getCount(i);

				switch (changeField) {
				case ISBN:
					modifyISBN(myBooks, bookIndex);
					break;

				case TITLE:
					modifyTitle(myBooks, bookIndex);
					break;

				case AUTHOR:
					modifyAuthor(myBooks, bookIndex);
					break;

				case PUBLISHER:
					modifyPublisher(myBooks, bookIndex);
					break;

				case DATEADDED:
					//modifyDate(object);
					break;

				case QUANTITYONHAND:
					modifyQuantity(myBooks, bookIndex);
					break;

				case COSTVALUE:
					modifyCost(myBooks, bookIndex);
					break;

				case PRICE:
					modifyPrice(myBooks, bookIndex);
					break;


				case BACKTOMAIN:
					//displayMainMenu();
					break;
				}
			}
		}
		if (option == 2)
		{
			for (int i; i < books.getFound; i++)
			{
				int bookIndex = books.getCount(i);
				char confirm = '\0';
				cout << "Are you sure you want to delete this book from the inventory: " << endl
					<< "(Y/N): ";

				cin.ignore();
				cin >> confirm;
				while (confirm != 'y'&& confirm != 'Y' && confirm != 'n' && confirm != 'N') {
					cout << "Invalid input. Pease enter Y/N: ";
					cin >> confirm;
				}
				if (confirm == 'Y' || confirm == 'y') {
					for (int i = bookIndex; i < numBooks; i++) {
						myBooks[bookIndex] = myBooks[bookIndex + 1];
					}
					Books emptyBook;
					myBooks[numBooks - 1] = emptyBook;
					numBooks--;
					cout << "The book has been deleted!";
					cout << "You will be redirected to main menu soon." << endl;
					//displayMainMenu
				}
				else if (confirm == 'n' || confirm == 'n') {
					cout << "You will be redirected to main menu soon." << endl;
					//displayMainMenu();
				}
			}
		}

		}if (option == 3)
		{
			new BookInformationMenu(myBooks, numBooks);
			delete this;
		}
		
		if (option == 4)
		{
			//Go to main menu
			//delete this;
		}
		if (option != 1 && option != 2 && option != 3 && option != 4)
		{
			cout << endl << endl << "Try again. . ." << endl;
			cin >> option;
		}
	}//Look up a book.
	if (option == 2)
	{
		findBook();

	} // Add a book.

	if (option == 3)
	{
		editBook(myBooks, numBooks);
	} //Edit a Book.

	if (option == 4)
	{
		deleteBook(myBooks, numBooks);
	} //Delete a Book.

	if (option == 5)
	{

	} //Return to main menu.
}

void BookInformationMenu::DisplayBookInformation()
{
	resultBooksNum = books.getFound;
	for (int i = 0; i < resultBooksNum; i += 0)
	{
		resultBooks[i] = myBooks[(int)books.getCount(i)];
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