// BGE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void main() {
    int
		n=3, // Numero de columnas y filas en A; Numero de Filas en B.
		m=1; // Numero de Columnas en B.

	float 
		A[3][3], // Matriz de coeficientes (n * n)
		B[3][1]; // Lado derecho de la ecuacion. (n * m)

	cout << "Entre el numero de columnas y filas de sus ecuaciones (A): ";
	cin >> n;
    
	cout << "Entre el numero de resultados (B): ";
	cin >> m;

	// Llenar el array de A de valores
	cout << "Entre los valores de la tabla A: " << endl;
	for(int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << "A[" << i << "][" << j<< "]: ";
			cin >> A[i][j];
		}
	}

	// Llenar el array de B de valores
	cout << "Entre los valores de la tabla B: " << endl;
	for(int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cout << "B[" << i << "][" << j<< "]: ";
			cin >> B[i][j];
		}
	}

	
}

