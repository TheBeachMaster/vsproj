// Array2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	int breaker = 0;


	int iar1[5], iar2[5], i = 0;
	cout << "Enter 5 numbers of the First Array" << endl;
	for (int i = 0; i < 5; i++)
	{
		cin >> iar1[i];
	}
	cout << "Enter 5 numbers of the Second Array" << endl;
	for (int i = 0; i < 5; i++)
	{
		cin >> iar2[i];
	}
	cout << endl;


	if (std::equal(std::begin(iar1), std::end(iar1), std::begin(iar2))) {

		cout << "Arrays are equal." <<endl;
	}
	else {

		cout << "Arrays are not equal." <<endl;
	}

	cout << "Enter any number to exit" << endl;
	cin >> breaker;
    return 0;
}

