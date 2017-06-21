/*
how to use:
editBook(Books[],int)
argument Books[] : pass in the original book array
argument int: pass in the number of books in the array. DO NOT pass in max size if the array is not full.

pending: displayMainMenu() 
i will need to include this if user choose to return to main menu 

*/


#ifndef BOOK_EDIT_H
#define BOOK_EDIT_H

#include "Books.h"
#include <iostream>
#include <string>
int displayBookToChange(Books[], int);
int displayChangesMenu(Books[], int);
void modifyISBN(Books[], int);
void modifyTitle(Books[], int);
void modifyAuthor(Books[], int);
void modifyPublisher(Books[], int);
void modifyDate(Books[], int);
void modifyQuantity(Books[], int);
void modifyCost(Books[], int);
void modifyPrice(Books[], int);

void editBook(Books);
int returnTo();

enum FIELD { ISBN = 1, TITLE, AUTHOR, PUBLISHER, DATEADDED, QUANTITYONHAND, COSTVALUE, PRICE, BACKTOMAIN };
using namespace std;
int displayBookToChange(Books listing[], int size ){
	int bookToChange = 0;
	cout << "List of Books: " << endl;
	for (int i = 0; i < size; i++){
		cout << i+1 <<". " << listing[i] << endl;
	}
	cout << "Which book do you want to modify (1-" << size << "): " ;
	cin >> bookToChange;
	while ((bookToChange) >= size || (bookToChange) <=0 ){
		cout << "Please enter from 1-" << size << ": ";
		cin >> bookToChange;
	}
	return bookToChange - 1;
}

int displayChangesMenu(){
	cout << "Please enter the number of the field you want to modify for this book." << endl;
	int optionToEdit;
	//(display everything , ?exclude date added )
	cout << "1. ISBN " << endl
		<< "2. Title " << endl
		<< "3. Author " << endl
		<< "4. Publisher " << endl
		<< "5. Date Added" << endl
		<< "6. Quantity in hand " << endl
		<< "7. Cost Price " << endl
		<< "8. Sales Price " << endl
		<< "9.return to main menu" << endl
		<< "Your option here: " ;

	cin >> optionToEdit;
	while (optionToEdit>9 || optionToEdit<1){
		cout << "Please enter a valid option between 1-9: ";
		cin >> optionToEdit;
	}

	return optionToEdit;

}

void editBook(Books listing[],int size){

	int whichBook = displayBookToChange(listing,size);
	int changeField = displayChangesMenu();//display option and ask for user option


	switch (changeField) {
	case ISBN:
		modifyISBN(listing,whichBook);
		break;

	case TITLE:
		modifyTitle(listing,whichBook);
		break;

	case AUTHOR:
		modifyAuthor(listing, whichBook);
		break;

	case PUBLISHER:
		modifyPublisher(listing, whichBook);
		break;

	case DATEADDED:
		//modifyDate(object);
		break;

	case QUANTITYONHAND:
		modifyQuantity(listing, whichBook);
		break;

	case COSTVALUE:
		modifyCost(listing, whichBook);
		break;

	case PRICE:
		modifyPrice(listing, whichBook);
		break;


	case BACKTOMAIN:
		//displayMainMenu();
		break;
	}
	//displayMainMenu() once user finish edit.

}



void modifyISBN(Books listing[], int location){

	string newISBN = "";
	char confirm = '\0';
	cout << "The current ISBN is: " << listing[location].getIsbn() << endl
		<< "Please type in the new ISBN: ";
	cin.ignore();
	getline(cin, newISBN);
	// atoi OR atof

	cout << "Please confirm the changes is: " << newISBN << endl
		<< " (Y = yes/ N = no ): " << endl;
	cin >> confirm;
	if (confirm == 'y' || confirm == 'Y'){
		listing[location].setIsbn(newISBN);
		cout << "The updated ISBN is " << listing[location].getIsbn() << endl;
	}
	else if (confirm == 'n'|| confirm == 'N'){
		cout << "You will be redirected to main menu soon." << endl;
		//displayMainMenu()
		
	}
}

void modifyTitle(Books listing[], int location){
	string newTitle = "";
	char confirm = '\0';
	cout << "The current title is: " << listing[location].getTitle() << endl
		<< "Please type in the new title: ";
	cin.ignore();
	getline(cin,newTitle);

	cout << "Please confirm the changes is: " << newTitle << endl
		<< "(Y = yes/ N = no ): " << endl;
	cin >> confirm;
	if (confirm == 'y' || confirm == 'Y'){
		listing[location].setTitle(newTitle);
		cout << "The updated title is " << listing[location].getTitle()<< endl;
	}
	else if (confirm == 'n' || confirm == 'N'){
		cout << "You will be redirected to main menu soon." << endl;
		//displayMainMenu()

	}

}

void modifyAuthor(Books listing[], int location){
	string newAuthor = "";
	char confirm = '\0';
	cout << "The current Author is: " << listing[location].getAuthor() << endl
		<< "Please type in the new author: ";
	cin.ignore();
	getline(cin,newAuthor);

	cout << "Please confirm the changes is: " << newAuthor << endl
		<< "(Y = yes/ N = no ): " << endl;
	cin >> confirm;
	if (confirm == 'y' || confirm == 'Y'){
		listing[location].setAuthor(newAuthor);
		cout << "The updated is author is " << listing[location].getAuthor() << endl;
	}
	else if (confirm == 'n' || confirm == 'N'){
		cout << "You will be redirected to main menu soon." << endl;
		//displayMainMenu()

	}

}

void modifyPublisher(Books listing[], int location){
	string newPublisher = "";
	char confirm = '\0';
	cout << "The current publisher is: " << listing[location].getPublisher() << endl
		<< "Please the in the new publisher: ";
	cin.ignore();
	getline(cin,newPublisher);

	cout << "Please confirm the changes is: " << newPublisher << endl
		<< "(Y = yes/ N = no ): " << endl;
	cin >> confirm;
	if (confirm == 'y' || confirm == 'Y'){
		listing[location].setPublisher(newPublisher);
		cout << "The updated publisher is " << listing[location].getPublisher() << endl;
	}
	else if (confirm == 'n' || confirm == 'N'){
		cout << "You will be redirected to main menu soon." << endl;
		//displayMainMenu()

	}

}

void modifyCost(Books listing[], int location){
	double newCost = 0.0;
	char confirm = '\0';
	cout << "The current cost is: $" << listing[location].getCost() << endl
		<< "Please type in the new cost: $";
	cin.ignore();
	cin >> newCost;

	cout << "Please confirm the changes is: $" << newCost << endl
		<< "(Y = yes/ N = no ): " << endl;
	cin >> confirm;
	if (confirm == 'y' || confirm == 'Y'){
		listing[location].setCost(newCost);
		cout << "The updated cost is $" << listing[location].getCost() << endl;
	}
	else if (confirm == 'n' || confirm == 'N'){
		cout << "You will be redirected to main menu soon." << endl;
		//displayMainMenu()

	}

}

void modifyQuantity(Books listing[], int location){
	int newQuantity = 0;
	char confirm = '\0';
	cout << "The current quantity is: " << listing[location].getQuantity() << endl
		<< "Please type in the new quantity: ";
	cin.ignore();
	cin >> newQuantity;

	cout << "Please confirm the changes is: " << newQuantity << endl
		<< "(Y = yes/ N = no ): " << endl;
	cin >> confirm;
	if (confirm == 'y' || confirm == 'Y'){
		listing[location].setQuantity(newQuantity);
		cout << "The updated quantity is " << listing[location].getQuantity() << endl;
	}
	else if (confirm == 'n' || confirm == 'N'){
		cout << "You will be redirected to main menu soon." << endl;
		//displayMainMenu()

	}

}

void modifyPrice(Books listing[], int location){
	double newPrice = 0.0;
	char confirm = '\0';
	cout << "The current price is: $" << listing[location].getPrice() << endl
		<< "Please type in the new selling price: $";
	cin.ignore();
	cin >> newPrice;

	cout << "Please confirm the changes is: $" << newPrice << endl
		<< "(Y = yes/ N = no ): " << endl;
	cin >> confirm;
	if (confirm == 'y' || confirm == 'Y'){
		listing[location].setPrice(newPrice);
		cout << "The updated price is $" << listing[location].getPrice() << endl;
	}
	else if (confirm == 'n' || confirm == 'N'){
		cout << "You will be redirected to main menu soon." << endl;
		//displayMainMenu()

	}

}




#endif