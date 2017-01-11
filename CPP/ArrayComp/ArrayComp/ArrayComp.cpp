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
	int arr[] = { 1, 2, 2 };
	int arrb[] = { 1, 2, 1 };
	int a = (sizeof(arr) / sizeof(arr[0]));
	int b = (sizeof(arrb) / sizeof(arrb[0]));
	std::cout << checkSimilarity(arr, arrb, a, b);
}

/*
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
*/