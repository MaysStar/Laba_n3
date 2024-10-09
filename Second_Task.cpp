#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double Y; 
double x;
double e = 0.0001; 
double S; 
double G;
double fault; 


int main() {
	cout << "Enter x = ";
	cin >> x;
	cout << endl;
	cout << "Enter e = ";
	cin >> e;
	cout << endl;

	if (fabs(x) > 0 && fabs(x) < 1 && e < 0.0001) {
		x = fabs(x);
		Y = (((1 + pow(x, 2)) / 2) * atan(x) - (x / 2));;
		int k = 1;
		x = fabs(x);
		while (true) {
			G = pow(-1, k + 1) * (pow(x, 2 * k + 1)) / (4 * pow(k, 2) - 1);
			S += G;

			fault = fabs(S - Y);
			if (fault < e) {
				break;

			}
			k += 1;
		}
		cout << "Y = ";
		printf("%.10f\n", Y);
		cout << endl;
		cout << "S = ";
		printf("%.10f\n", S);
		cout << endl;
		cout << "fault = ";
		printf("%.10f\n", fault);
			
	}
	else {
		cout << "Error";
	}
	return 0;
}
