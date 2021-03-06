#include "Books.h"
#include "BookSearch.h"

void searchBook(Books resultBooks[], int &resultNumBooks, Books inBooks[],
	int inNumBooks, SearchBy field, string toSearch)
{
	int index = 0;
	bool bookFound = false;
	int indexFound = 0;

	for (index = 0; index < inNumBooks; ++index) {
		switch (field)
		{
			case SearchByIsbn:
				if (inBooks[index].getIsbn() == toSearch) 
					bookFound = true;
				break;
			case SearchByTitle:
				if (inBooks[index].getTitle() == toSearch) 
					bookFound = true;
				break;
			case SearchByAuthor:
				if (inBooks[index].getAuthor() == toSearch)
					bookFound = true;
				break;
			case SearchByPublisher:
				if (inBooks[index].getPublisher() == toSearch)
					bookFound = true;
				break;
			case SearchByDateAdded:
				if (inBooks[index].getDateAdded() == toSearch)
					bookFound = true;
				break;
			case SearchByQuantity:
				if (inBooks[index].getQuantity() == stoi(toSearch))
					bookFound = true;
				break;
			case SearchByCost:
				if (fabs(inBooks[index].getCost() - stod(toSearch)) < DBL_EPSILON)
					bookFound = true;
				break;
			case SearchByPrice:
				if (fabs(inBooks[index].getPrice() - stod(toSearch)) < DBL_EPSILON)
					bookFound = true;
				break;
		}

		if (bookFound) {
			resultBooks[indexFound++] = inBooks[index];
		}
		bookFound = false;
	}
	resultNumBooks = indexFound;
}
