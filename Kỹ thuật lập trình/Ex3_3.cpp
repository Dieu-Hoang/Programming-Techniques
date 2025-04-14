//#include <iostream>
//using namespace std;
//
//// Ham nhap
//void Nhap(double &x) {
//	cout << "\nNhap: ";
//	cin >> x;
//}
//// Ham tim ra max
//double Max(double a, double b, double c) {
//	double max = a;
//	if (b > max) 
//		max = b;
//	if (c > max) 
//		max = c;
//	return max;
//}
//// Ham tim ra min
//double Min(double a, double b, double c) {
//	double min = a;
//	if (b < min) 
//		min = b;
//	if (c < min) 
//		min = c;
//	return min;
//}
//int main() {
//	double a, b, c;
//	Nhap(a); Nhap(b); Nhap(c);
//	cout << "Gia tri lon nhat trong 3 so a, b, c: " << Max(a, b, c) << endl;
//	cout << "Gia tri nho nhat trong 3 so a, b, c: " << Min(a, b, c) << endl;
//	double d, e;
//	Nhap(d); Nhap(e);
//	double prev_max = Max(a, b, c);
//	double prev_min = Min(a, b, c);
//	cout << "Gia tri lon nhat trong 5 so a, b, c, d, e: " << Max(prev_max, d, e) << endl;
//	cout << "Gia tri nho nhat trong 5 so a, b, c, d, e: " << Min(prev_max, d, e) << endl;
//
//	return 0;
//}