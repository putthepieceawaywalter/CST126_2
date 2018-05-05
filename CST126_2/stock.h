//--------------------------------------------------------------------
// stock.h
//     
//--------------------------------------------------------------------
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>

using namespace std;

class stock
{
public:
	
	void print();
	void appreciate() { price += (price * .1); };
	string getSymbol();
	string getName();
	double getPrice();
	double getEarnings();
	double appreciation();
	double pOverE();  // (price over earnings)	
	
	stock()
	{
		price = 0;
		earnings = 0;
		name_with_quotes = '\0';
		symbol = '\0';
		if (earnings == 0)
		{
			a = 0;
		}

	};
	stock(string p_symbol, string p_name, double p_price, double p_earnings)
	{
		symbol = p_symbol;
		name_with_quotes = p_name;
		price = p_price;
		earnings = p_earnings;

	};


private:
	string symbol;
	string name_with_quotes;
	double price;
	double earnings;
	double a;

};

bool OpenFile(ifstream& input_file);
void fill_stock_from_file(stock stockArray[], ifstream &, int & count);
void tokenizer(char line[], std::string & symbol, std::string & name_with_quotes, double & price, double & earnings);
