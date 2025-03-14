//#include<iostream>
//#include<cmath>
//#include<iomanip>
//using namespace std;
//
//int main() {
//	//khai báo các biến đầu vào
//	int x1, y1, x2, y2;
//	cout << "Enter the coordinates of point A: ";
//	cin >> x1 >> y1;
//	cout << "Enter the coordinates of point B: ";
//	cin >> x2 >> y2;
//	//khai báo và tính D, M, C
//	double D, M, C;
//	D = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
//	M = fabs(x2 - x1) + fabs(y2 - y1);
//	C = 1 - (x1 * x2 + y1 * y2) / (sqrt(x1 * x1 + y1 * y1) * sqrt(x2 * x2 + y2 * y2));
//	// In D,M, C ra mà hình
//	cout << setprecision(3) << "Euclidean distance: " << D << endl;
//	cout << "Manhattan distance: " << M << endl;
//	cout << "Cosin distance: " << C << endl;
//	return 0;
//}