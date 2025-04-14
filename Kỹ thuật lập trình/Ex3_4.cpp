//#include <iostream>
//using namespace std;
//
//// Ham nhap
//void Nhap(double& x) {
//	cout << "\nNhap: ";
//	cin >> x;
//}
//
//// Ham giai phuong trinh bac 2
//int GiaiPTbac2(double a, double b, double c, double& x_1, double& x_2) {
//	if (a == 0) {
//		if (b == 0) {
//			if (c == 0) {
//				//cout << "\nPhuong trinh co vo so nghiem";
//				return 0;
//			}
//			else {
//				//cout << "\nPhuong trinh vo nghiem";
//				return -1;
//			}
//		}
//		else {
//			x_1 = -c / b;
//			//cout << "\nPhuong trinh co 1 nghiem: x = " << x_1;
//			return 1;
//		}
//	}
//	else {
//		double delta = b * b - 4 * a * c;
//		if (delta < 0) {
//			//cout << "\nPhuong trinh vo nghiem";
//			return -1;
//		}
//		else if (delta == 0) {
//			x_1 = -b / (2 * a);
//			//cout << "\nPhuong trinh co 1 nghiem: x = " << x_1;
//			return 1;
//		}
//		else {
//			x_1 = (-b + sqrt(delta)) / (2 * a);
//			x_2 = (-b - sqrt(delta)) / (2 * a);
//			//cout << "\nPhuong trinh co 2 nghiem: x_1 = " << x_1 << ", x_2 = " << x_2;
//			return 2;
//		}
//	}
//}
//
//int main() {
//	double a, b, c, x_1, x_2;
//	Nhap(a); Nhap(b); Nhap(c);
//	if (GiaiPTbac2(a, b, c, x_1, x_2) == -1)
//		cout << "\nPhuong trinh vo nghiem";
//	else if (GiaiPTbac2(a, b, c, x_1, x_2) == 0)
//		cout << "\nPhuong trinh co vo so nghiem";
//	else if (GiaiPTbac2(a, b, c, x_1, x_2) == 1)
//		cout << "\nPhuong trinh co 1 nghiem: x = " << x_1;
//	else if (GiaiPTbac2(a, b, c, x_1, x_2) == 2)
//		cout << "\nPhuong trinh co 2 nghiem: x_1 = " << x_1 << ", x_2 = " << x_2;
//	return 0;
//}