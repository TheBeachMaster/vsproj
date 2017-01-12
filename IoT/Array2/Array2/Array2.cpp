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



	int iar1[] = { 1,2,3,4,5 };
	int iar2[] = { 1,2,3,4,5 };

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

