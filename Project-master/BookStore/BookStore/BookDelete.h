/*
deleteBook(Books[], &int);
argument Books[] : pass in the original book array
argument &int: pass in the number of books in the array. DO NOT pass in max size if the array is not full.
this function will modify the numBook in array, so it has to be passed by referenced.

the approach is to find where the deleted book is in the array, assign the location to the one book behind and continue for the rest
the last book will be duplicated, set it as an emptyBook
decrease the numBook

pending: displayMainMenu()
i will need to include this if user choose to return to main menu

*/


#ifndef BOOK_DELETE_H
#define BOOK_DELETE_H

#include "Books.h"
#include "BookEdit.h"
#include <iostream>
#include <string>

void deleteBook(Books listing [], int& size){
	int whichBook = displayBookToChange(listing, size); //from edit menu
	char confirm = '\0';
	cout << "Are you sure you want to delete this book from the inventory: " << listing[whichBook] << endl
		<< "(Y/N): ";

	cin.ignore();
	cin >> confirm;
	while (confirm != 'y'&& confirm != 'Y' && confirm != 'n' && confirm != 'N'){
		cout << "Invalid input. Pease enter Y/N: ";
		cin >> confirm;
	}
	if (confirm == 'Y' || confirm == 'y'){
		for (int i = whichBook; i < size; i++){
			listing[whichBook] = listing[whichBook + 1];
		}
		Books emptyBook;
		listing[size - 1] = emptyBook;
		size--;
		cout << "The book has been deleted!";
		cout << "You will be redirected to main menu soon." << endl;
		//displayMainMenu
	}
	else if (confirm == 'n' || confirm == 'n'){
		cout << "You will be redirected to main menu soon." << endl;
		//displayMainMenu();
	}

}

#endif
