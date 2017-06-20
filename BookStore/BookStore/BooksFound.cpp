#include "BookInformationMenu.h"
#include "Books.h"
#include "BookSearch.h"
#include "BooksFound.h"

#include <iostream>

void BooksFound::setCount(int count[])
{
	for (int i = 0; i < indexFound; i ++)
	indexCount[i] = count[i];
};

void BooksFound::setFound(int found)
{
	indexFound = found;
};

int* BooksFound::getCount()
{
	return indexCount;
};

int BooksFound::getFound()
{
	return indexFound;
};