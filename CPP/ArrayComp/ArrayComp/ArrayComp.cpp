// ArrayComp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
using namespace std;

bool checkSimilarity(int arraya[], int arrayb[], int a, int b)
{

	std::sort(arraya, arraya + a);
	std::sort(arrayb, arrayb + b);
	return a == b && std::equal(arraya, arraya + a, arrayb);
}

int main()
{
	int breakCode = 0;
	int arrayA[5], arrayB[5], i = 0;

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
	std::cout << checkSimilarity(arrayA, arrayB, a, b);

	cout << "Enter any number to exit" << endl;
	cin >> breakCode;
}

