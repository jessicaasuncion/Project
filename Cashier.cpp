#include "Cashier.h"

using namespace std;

Cashier::Cashier(Books *b)
{
	book = b;
	numBooks = 0;
}

Cashier::Cashier(Books *b, int n)
{
	book = b;
	numBooks = n;
}

double Cashier::getQandP() const
{
	double qp;
	qp = numBooks * getPrice();
	return qp;
}
double Cashier::getSubtotal() const
{
	double subtotal;
	// subtotal = ?
	return subtotal;
}
double Cashier::getTax() const
{
	double tax;
	tax = getSubtotal() * tax;
	return tax;
}
double Cashier::getTotal() const
{
	double total;
	total = getSubtotal() + getTax();
	return total;
}