#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip> 
#define CountOfNode 17
#define Min 0.0
#define Max 0.5

using namespace std;

double x = Min;
double y;

double Function1(double x) {
	return (x / (1 - pow(x, 2))) + (tan(x));
}



int main() {
	int n = 1000;
	double step = (Max - Min) / n;
	double sum = (Function1(Min) + Function1(Max)) / 2;
	for (int i = 1; i <= CountOfNode; i++) {

		y = Function1(x);
		cout << setw(2) << setfill('0') << i << " x = ";
		printf("%.3f", x);
		cout << " y = ";
		printf("%.3f\n", y);

		x += 0.03;
		
	}
	for (int i = 1; i < n; i++) {
		double x = Min + i * step;
		sum += Function1(x);
	}
	cout << "Integral [0,0.5] = "<< sum * step << endl;
}
