//edit book's function

#include <iostream>
#include <string>
#include <iomanip>
#include "Books.h"
#include "BookEdit.h"


using namespace std;

void editBook(Books &object){

	
	int changeField = displayChangesMenu();//display option and ask for user option

	//Books object("123ISBN", "My first book", "Emily", "BarnesNoble", "20110123", 23, 10, 15);

	switch (changeField) {
	case ISBN:
		modifyISBN(&object);
		break;

	case TITLE:
		modifyTitle(&object);
		break;

	case AUTHOR:
		modifyAuthor(&object);
		break;

	case PUBLISHER:
		modifyPublisher(&object);
		break;

	case DATEADDED:
		modifyDate(&object);
		break;

	case QUANTITY:
		modifyQuantity(&object);
		break;

	case COST:
		modifyCost(&object);
		break;

	case PRICE:
		modifyPrice(&object);
		break;


	default:
		//9. return to main menu function here?
		break;
	}


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
		<< "9.return to main menu" << endl;

	cin >> optionToEdit;
	while (optionToEdit>9 || optionToEdit<1){
		cout << "Please enter a valid option between 1-9: ";
		cin >> optionToEdit;
	}

	return optionToEdit;

}

void modifyISBN(Books &object){

	string newISBN = "";
	char confirm = '\0';
	cout << "The current ISBN is: " << object.getIsbn() << endl
		<< "Please type in the new ISBN: ";
	cin >> newISBN;
	// atoi OR atof

	cout << "Please confirm the changes is: " << newISBN << endl
		<< " (Y = yes/ N = no ): " << endl;
	cin >> confirm;
	if (confirm == 'y' || confirm == 'Y'){
		object.setIsbn(newISBN);
		//cout << "The updated ISBN is " << object.getISBN() << endl;
	}
	else {
		displayChangesMenu();
	}
}

void modifyTitle(Books &object){
	string newTitle = "";
	char confirm = '\0';
	cout << "The current title is: " << object.getTitle() << endl
		<< "Please type in the new title: ";
	cin >> newTitle;

	cout << "Please confirm the changes is: " << newTitle << endl
		<< "(Y = yes/ N = no ): " << endl;
	cin >> confirm;
	if (confirm == 'y' || confirm == 'Y'){
		object.setTitle(newTitle);
		//cout << "The updated is "<< endl;
	}
	else {
		//return to display menu function "which field do you want to change."
	}

}

void modifyAuthor(Books &object){
	string newAuthor = "";
	char confirm = '\0';
	cout << "The current  is: " << object.getAuthor() << endl
		<< "Please type in the new author: ";
	cin >> newAuthor;

	cout << "Please confirm the changes is: " << newAuthor << endl
		<< "(Y = yes/ N = no ): " << endl;
	cin >> confirm;
	if (confirm == 'y' || confirm == 'Y'){
		object.setAuthor(newAuthor);
		//cout << "The updated is " << object.get() << endl;
	}
	else {
		//return to display menu function "which field do you want to change."
	}

}

void modifyPublisher(Books &object){
	string newPublisher = "";
	char confirm = '\0';
	cout << "The current  is: " << object.getPublisher() << endl
		<< "Please the in the new title: ";
	cin >> newPublisher;

	cout << "Please confirm the changes is: " << newPublisher << endl
		<< "(Y = yes/ N = no ): " << endl;
	cin >> confirm;
	if (confirm == 'y' || confirm == 'Y'){
		object.setPublisher(newPublisher);
		//cout << "The updated is " << object.get() << endl;
	}
	else {
		//return to display menu function "which field do you want to change."
	}

}

void modifyCost(Books &object){
	double newCost = 0.0;
	char confirm = '\0';
	cout << "The current  is: " << object.getCost() << endl
		<< "Please type in the new cost: ";
	cin >> newCost;

	cout << "Please confirm the changes is: " << newCost << endl
		<< "(Y = yes/ N = no ): " << endl;
	cin >> confirm;
	if (confirm == 'y' || confirm == 'Y'){
		object.setCost(newCost);
		//cout << "The updated is " << object.get() << endl;
	}
	else {
		//return to display menu function "which field do you want to change."
	}

}

void modifyQuantity(Books &object){
	int newQuantity = 0;
	char confirm = '\0';
	cout << "The current  is: " << object.getQuantity() << endl
		<< "Please type in the new quantity: ";
	cin >> newQuantity;

	cout << "Please confirm the changes is: " << newQuantity << endl
		<< "(Y = yes/ N = no ): " << endl;
	cin >> confirm;
	if (confirm == 'y' || confirm == 'Y'){
		object.setQuantity(newQuantity);
		//cout << "The updated is " << object.get() << endl;
	}
	else {
		//return to display menu function "which field do you want to change."
	}

}

void modifyPrice(Books &object){
	double newPrice = 0.0;
	char confirm = '\0';
	cout << "The current  is: " << object.getPrice() << endl
		<< "Please type in the new selling price: ";
	cin >> newPrice;

	cout << "Please confirm the changes is: " << newPrice << endl
		<< "(Y = yes/ N = no ): " << endl;
	cin >> confirm;
	if (confirm == 'y' || confirm == 'Y'){
		object.setPrice(newPrice);
		//cout << "The updated is " << object.get() << endl;
	}
	else {
		//return to display menu function "which field do you want to change."
	}

}
