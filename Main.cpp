#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double Y; // значення Y
double x; // значення х
double e = 0.0001; 
double S; // значення S ( сума всіх функцій )
double G; // перехідне значення функції 
double fault; // похибка

double CalculatingY(double Y, double x) { // визначення Y
	x = fabs(x);
	Y = (((1 + pow(x, 2)) / 2) * atan(x) - (x / 2));
	return Y;
}

double CalculatingS(double Y, double x, double e) { // визначення найближчого значення S порівнянно з Y
	int k = 1;
	x = fabs(x);
	while (true) {
		G = pow(-1, k + 1) * (pow(x, 2 * k + 1)) / (4 * pow(k, 2) - 1);
		S += G; // значення S сума всіх функцій

		fault = fabs(S - Y); 
		if (fault < e) { // перевірка щоб | S(x) – Y(x) | ( тобто похибка була менша за e
			break;
			
		}
		k += 1;
	}
	return S;
}


int main() {
	cout << "Enter x = ";
	cin >> x;
	cout << endl;
	cout << "Enter e = ";
	cin >> e;
	cout << endl;

	if (fabs(x) > 0 && fabs(x) < 1 && e < 0.0001) {
		Y = CalculatingY(Y, x);
		CalculatingS(Y, x, e);
		cout << "Y = " << Y << endl;
		cout << "S = " << S << endl;
		cout << "fault = ";
		printf("%.10f\n", fault);
			
	}
	else {
		cout << "Error";
	}
	return 0;
}
