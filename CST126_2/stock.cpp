//--------------------------------------------------------------------
// stock.cpp
//--------------------------------------------------------------------
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include "stock.h"
#include <string>
#include <iomanip>

using namespace std;


string stock::getSymbol()
{
	return symbol;
};

double stock::getPrice()
{
	return price;
}

double stock::getEarnings()
{
	return earnings;
}

string stock::getName()
{
	return name_with_quotes;
}

double stock::appreciation()
{
	// formula to calculate appreciation
	return 0.0;
}

double stock::pOverE()
{
	return price / earnings;
}

void stock::print()
{

	

	double a = getPrice();
	double b = getEarnings();
	double pOverE = a / b;
	cout << setw(4);
	cout << left << getSymbol() << '\t';
	cout << setw(25);
	cout << left << getName();
	cout << setw(8);
	cout << "Price: ";
	cout << setw(12);
	cout << getPrice();
	cout << setw(10);
	cout << "Earnings: ";
	cout << setw(12);
	cout << getEarnings();
	cout << setw(10);
	cout << "Price over Earnings: " << pOverE << endl;

}
