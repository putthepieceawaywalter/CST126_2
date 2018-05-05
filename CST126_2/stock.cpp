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

void printMe(stock s, string symbol, string name, double price, double earnings)
{
	cout << s.getSymbol() << " " << s.getName() << " " << s.getPrice() << " " << s.getEarnings() << '\n';
}

void print(stock s)
{
	{ cout << s.getSymbol() << " " << s.getName() << " " << s.getPrice() << " " << s.getEarnings() << endl; };

}
