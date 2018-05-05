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
	//void update(string p_sym, string p_name, double p_price, double p_earnings) { earnings = p_earnings; symbol = p_sym; price = p_price; name_with_quotes = p_name; };
	
	
	void print() { cout << symbol << " " << name_with_quotes << " " << price << " " << earnings << endl; };
	void appreciate() { price += (price * .1); };
	string getSymbol();
	string getName();
	double getPrice();
	double getEarnings();
	double appreciation();
	double pOverE();  // (price over earnings)	
	//void setData(stock s, string, string, double, double);
	
	stock()
	{
		price = 0;
		earnings = 0;
		name_with_quotes = '\0';
		symbol = '\0';
	};
	stock(string p_symbol, string p_name, double p_price, double p_earnings)
	{
		//cout << a << " " << b << " " << c << " " << d;
		symbol = p_symbol;
		name_with_quotes = p_name;
		price = p_price;
		earnings = p_earnings;
		
		double pOverE = price / earnings;

	};


private:
	string symbol;
	string name_with_quotes;
	double price;
	double earnings;
	

};

bool OpenFile(ifstream& input_file);
void fill_stock_from_file(stock stockArray[], ifstream &, int & count);
//void fill_stock_from_file(ifstream & in_file, int & count);  // temporary starting version.
void tokenizer(char line[], std::string & symbol, std::string & name_with_quotes, double & price, double & earnings);
void printMe(stock s, std::string symbol, std::string name, double price, double earnings);
//void fill_stock_from_file_appreciate(stock stockArray[], ifstream &, int & count);
