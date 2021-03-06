// CST126_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include "stock.h"

using namespace std;

// 2. format the output to match the answer key


int main(void)
{
	int count = 0;
	int * stock_ptr = &count;

	cout.setf(ios::fixed);   // this sets all doubles and floats to be shown in fixed point notation
	cout.setf(ios::showpoint); // This makes sure the decimal point is shown
	cout.precision(2);  // This sets the amount of places after the decimal to two

	stock stockArray[4];
	ifstream stock_file;
	cout << "Welcome to the Stock Picker" << endl << endl;

	if (OpenFile(stock_file)) {
		while (!stock_file.eof()) {
			fill_stock_from_file(stockArray, stock_file, count);

			count++;
		}
		for (int i = 0; i < 4; i++)
		{
			stockArray[i].print();
		}
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "If you had a 10% appreciation in price the values would be" << endl;
		cout << '\n' << '\n';

	}
	for (count = 0; count < 4; count++)
	{

		double price_a = stockArray[count].getPrice();
		price_a *= 1.1;
		string name = stockArray[count].getName();
		string symbol = stockArray[count].getSymbol();
		double earnings = stockArray[count].getEarnings();
		double pOverE = stockArray[count].pOverE();
		stockArray[count] =
		{

			symbol,
			name,
			price_a,
			earnings
		};
		stockArray[count].print();
	}

	return 0;
}

bool OpenFile(ifstream& input_file)
{
	char stock_file[40];
	std::cout << "what is the name of the file?\n";
	std::cin >> stock_file;

	input_file.open(stock_file);

	if (input_file.fail())
	{
		cout << "You failed to open the file" << endl;
		return false;
	}
	else

		return true;
}

void fill_stock_from_file(stock stockArray[], ifstream & in_file, int & count)
{
	char line[81];
	string symbol;
	string name_with_quotes;
	double price;
	double earnings;

	
	in_file.getline(line, 80);

	if (!in_file.eof()) {
		tokenizer(line, symbol, name_with_quotes, price, earnings);
		stockArray[count] =
		{
			symbol,
			name_with_quotes,
			price,
			earnings
		};
	}
}

void tokenizer(char line[], string & symbol, string & name_with_quotes, double & price, double & earnings)
{
	string token;
	istringstream iss(line);

	std::getline(iss, symbol, ',');
	std::getline(iss, name_with_quotes, ',');
	std::getline(iss, token, ',');
	price = atof(token.c_str());
	std::getline(iss, token, ',');
	earnings = atof(token.c_str());

}
