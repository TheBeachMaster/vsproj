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