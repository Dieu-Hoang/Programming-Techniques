#include <iostream>
using namespace std;
// Ham nhap
void Nhap(double& x) {
	cout << "\nNhap: ";
	cin >> x;
}
// Ham giai he phuong trinh bac 1 bang phuong phap cramer X[i] = |A[i]| / |A| 
// 
int GiaiHePTbac1(double a, double b, double c, double d, double e, double f, double& x_1, double& x_2) {
	double delta_A = a * e - b * d; // tinh dinh thuc cua ma tran he so
	if (delta_A == 0) {
		if (a * f - c * d == 0) {
			// cout << "\nHe phuong trinh co vo so nghiem";
			return 0;
		}
		else {
			// cout << "\nHe phuong trinh vo nghiem";
			return -1;
		}
	}
	else {
		// cout << "\nHe phuong trinh co nghiem duy nhat: x_1 == " << x_1 << " x_2 = " << x_2;
		double delta_A1 = c * e - b * f; // tinh dinh thuc cua ma tran A thay cot 1 bang cot so hang tu do
		x_1 = delta_A1 / delta_A;
		double delta_A2 = a * f - c * d;
		x_2 = delta_A2 / delta_A;
		return 1;
	}
}
int main() {
	double a, b, c, d, e, f, x_1, x_2;
	Nhap(a); Nhap(b); Nhap(c); Nhap(d); Nhap(e); Nhap(f);
	if (GiaiHePTbac1(a, b, c, d, e, f, x_1, x_2) == 0) {
		cout << "\He phuong trinh co vo so nghiem";
	}
	else if(GiaiHePTbac1(a, b, c, d, e, f, x_1, x_2) == -1) {
		cout << "\He phuong trinh vo nghiem";
	}
	else {
		cout << "\nHe phuong trinh co nghiem duy nhat: x_1 = " << x_1 << " va x_2 = " << x_2;
	}

	return 0;
}