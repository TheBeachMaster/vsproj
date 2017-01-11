// ArrayComp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int arrayA[5], arrayB[5] , i =0; //Declare our two Arrays A and B and another variable i to count our Arrays

	cout << "Enter 5 numbers of the First Array" << endl;

	for (int i = 0; i < 5; i++)
	{
		cin >> arrayA[i];
	}

	cout << "Enter 5 numbers of the Second Array" << endl;

	for (int i = 0; i < 5; i++)
	{
		cin >> arrayB[i];
	}


	int a = (sizeof(arrayA) / sizeof(arrayA[0]));
	int b = (sizeof(arrayB) / sizeof(arrayB[0]));
	cout << checkForSimilar(arrayA, arrayB, a, b);
	 
    return 0;
}

