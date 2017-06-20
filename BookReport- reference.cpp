#define _CRT_SECURE_NO_WARNINGS

#include "Books.h"
#include "BookSearch.h"
#include "BookReportMenu.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
//enum REPORT { ALL = 1, WHOLESALE, RETAIL, QUANTITY, COST, AGE, MAIN };

int main(){
	const int MAX_BOOKS = 50;
	Books myBooks[MAX_BOOKS];
	int reportType = 0;
	reportType = displayReportMenu();
	switch (reportType)  {
	case ALL:
		inventoryListing(myBooks, MAX_BOOKS);
		break;
	case WHOLESALE:
		wholesaleListing(myBooks, MAX_BOOKS);
		break;
	case RETAIL:
		retailListing(myBooks, MAX_BOOKS);
		break;
	case QUANTITY:
		quantityListing(myBooks, MAX_BOOKS);
		break;
	case COST:
		costListing(myBooks, MAX_BOOKS);
		break;
	case AGE:
		ageListing(myBooks, MAX_BOOKS);
		break;
	case MAIN:
		//display Main Menu();
		break;


	}

}