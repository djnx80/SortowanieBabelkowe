// SortowanieBabelkowe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void sortuj(int [], int);	// tablica i ile elementów

int main()
{
	int ile_el = 50;		// ile elementow w tablicy
	int *elementy = new int[ile_el];	// tworzymy dynamicznie tablicy
	srand(time(NULL));

	cout << "Tablica przed sortowaniem:" << endl;
	for (int i = 0; i < ile_el; i++) {	// losowe liczby do tablicy
		elementy[i] = 1 + rand() % 200;
		cout << elementy[i] << " ";
	}

	sortuj(elementy, ile_el);		// sortuj i wyœwietl

	cout << endl << "Tablica po sortowaniu:" << endl;
	for (int i = 0; i < ile_el; i++)
		cout << elementy[i] << " ";

	delete [] elementy;	// usuwamy z pamiêci tablicê

	getchar();
	return 0;
}

void sortuj(int elementy[], int ile)
{
	for (int i = 0; i < ile-1; i++)		// ostatniego elementu nie sprawdzamy bo i tak zostanie wypchana najwieksza liczba na wierzch
	{
		for (int j = ile-1; j >=i+1; j--)		// pêtla od koñca do i+1
		{
			if (elementy[j] < elementy[j - 1])	// jezeli element jest mniejszy od poprzednika 
			{
				int x = elementy[j];
				elementy[j] = elementy[j - 1];	// to zamien go miejscmi i sprawdz nastepny
				elementy[j - 1] = x;
			}
		}
	}
}