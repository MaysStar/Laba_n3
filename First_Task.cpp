#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip> 
#define Min 0.0
#define Max 0.5

using namespace std;

double x = Min;
double xwhile = Min;
double y;
int CountOfNode;

int main() {

	cout << "Enter count of nodes: ";
	cin >> CountOfNode;
	double step = (Max - Min) / CountOfNode;
	double S = 0.0;
	double Swhile = 0.0;
	double xmom;
	for (int i = 1; i <= CountOfNode; i++) {

		y = ((x / (1 - pow(x, 2))) + (tan(x)));
		cout << setw(3) << setfill('0') << i << " x = ";
		printf("%.5f", x);
		cout << " y = ";
		printf("%.5f\n", y);

		x += (Max - Min) / CountOfNode;
		xmom = i * step;
		S += (xmom / ((1 - pow(xmom, 2))) + (tan(xmom))) * step;
	}
	int t = 0;
	while (t < CountOfNode) {
		Swhile += (xwhile / ((1 - pow(xwhile, 2))) + (tan(xwhile))) * step;
		xwhile += step;
		t++;
	}
	int k = 0;
	double sum = ((Min / (1 - pow(Min, 2))) + (tan(Min))) + ((Max / (1 - pow(Max, 2))) + (tan(Max)));
	do {
		double x = Min + k * step;
		if (k % 2 == 0) {
			sum += 2 * ((x / (1 - pow(x, 2))) + (tan(x)));
		}
		else {
			sum += 4 * ((x / (1 - pow(x, 2))) + (tan(x)));
		}
		k++;
	}
	
	while (k < CountOfNode);
	sum = (step / 3) * sum;

	
	cout << "Integral for [0,0.5] = "<< S << endl;
	cout << "Integral while [0,0.5] = " << Swhile << endl;
	cout << "Integral do while [0,0.5] = " << sum << endl;
}
