#include<iostream>
#include<cmath>
using namespace std;

int main() {
	double x;
	cout << "Enter x: ";
	cin >> x;
	long double ans;
	ans = pow(x, 2) + exp(fabs(x)) + pow(sin(x), 2);
	ans = ans / pow(pow(x, 2) + 1, 1.0 / 5);
	cout << "Answer: " << ans;
	return 0;
}