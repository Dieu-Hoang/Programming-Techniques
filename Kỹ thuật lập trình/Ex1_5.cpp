#include<iostream>
using namespace std;

int main() {
	int x1, y1, x2, y2, x3, y3;
	cout << "Enter the coordinates of point A: ";
	cin >> x1 >> y1;
	cout << "Enter the coordinates of point B: ";
	cin >> x2 >> y2;
	cout << "Enter the coordinates of point C: ";
	cin >> x3 >> y3;
	double xK, yK, inter;
	xK = (x1 + x2 + x3) / 3;
	yK = (y1 + y2 + y3) / 3;

	inter = sqrt(pow(x1 - xK, 2) + pow(y1 - yK, 2)) + sqrt(pow(x2 - xK, 2) + pow(y2 - yK, 2)) + sqrt(pow(x3 - xK, 2) + pow(y3 - yK, 2));

	cout << "xK = " << xK << endl;
	cout << "yK = " << yK << endl;
	cout << "Inter = " << inter;
	return 0;
}