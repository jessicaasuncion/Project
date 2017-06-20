#define BOOKINFORMATIONMENU_H
#include <string>
#include <iomanip>
#include <iostream>
#include "Books.h"
#include "BookSearch.h"

using namespace std;

class BooksFound
{
private:
	int indexCount[50], indexFound;
public:
	void setCount(int*);
	void setFound(int);
	int* getCount();
	int getFound();
};
#pragma once
