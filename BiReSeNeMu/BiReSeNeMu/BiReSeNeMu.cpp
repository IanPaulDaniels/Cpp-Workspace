// BiReSeNeMu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int numExp = 0;
double varArray[9];



float f(double x) {
	double y = 0;

	for (int i = numExp; i >= 0; i--) {
		if( i == 1 )
			y += varArray[i] * x;
		else if( i == 0 ){
			y += varArray[i];
			break;
		}
		else {
			y += varArray[i] * pow(x,i);
		}
	}

	cout	<< "x:\t" << x << endl
			<< "f(x):\t" << y << endl << endl;

	return y;
}

void bisection(float a, float b, int maxBis, float tol) {
	//Initialize these variables.
	float 
		ya = f(a), 
		yb = f(b),
		xm,
		ym;

	if ( ya * yb >= 0 ) {
		cout << "Error! Zero Not Found";
	}

	//Begin Iterations
	for (int index = 1; index <= maxBis; index++){
		xm = (a + b) / 2;
		ym = f(xm);

		if( abs(ym) < tol) break;	// Solution is Good Enough
		if (ya * ym < 0){			// Solution is in left hand interval
			b = xm;
			yb = ym;
		}
		else {
			a = xm;
			ya = ym;
		}
	}

}

int main() {
	
	int	
		max					=	0,
		numSignificativos	=	0;
	double
		tol					=	0;

	// Conseguir el numero mas alto de exponente
	cout << "Entre numero del exponente mas alto (9 Max): ";
	
	do 
	{
	cin >> numExp;
	cout << endl;
	} while (numExp > 9 || numExp <= 0);
	
	// Conseguir variables para cada exponente.
	for (int i = numExp; i >= 0; i--)
	{
		cout << "Entre la variable para X^" << i << ": ";
		cin >> varArray[i];
		
	}
	cout << endl;

	//Conseguir Max
	cout << "Entre el maximo numero de iteraciones (MAX): ";
	cin >> max;
	cout << endl;

	// COnseguir Tol.
	cout << "Indique la cantidad de digitos significativos: ";
	cin >> numSignificativos;

	tol = 1 * pow(10.0,-numSignificativos);

	// Mostrar Funcion
	for (int i = 0; i <= numExp; i++) {
		if (varArray[numExp - i] != 0) // Si la Variable no es igual a 0, entonces mostrar Variable con Exponente.
		{
			if (numExp - i == 1) // Si aX^1, entonces aX (X^1 = X)
			{
				cout << varArray[numExp - i] << "X";

 			}
			else if (numExp - i == 0) // Si aX^0, entonces a. (aX^0 = a)
			{
				cout << varArray[numExp - i];
				
				break;
			}
			else // aX^y
			{
				cout << varArray[numExp - i] << "X^" << numExp - i; 
				}
		
			if( numExp - i - 1 >= 0 ) // Añadir signo de suma
				{
					cout << " + ";
					
				}
			
			
		}
	
	}
	cout << endl;

	f(1);
	f(2);
	
	bisection(1, 2, max, tol);
	

	return 0;
	
}