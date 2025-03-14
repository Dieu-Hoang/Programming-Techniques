#include<iostream>
using namespace std;

int main() {
	int a, b, c;
	cout << "Nhap a: "; cin >> a;
	cout << "Nhap b: "; cin >> b;
	cout << "Nhap c: "; cin >> c;

	double d, x1, x2;
	if (a == 0) {
		cout << "Phuong trinh khong phai bac 2\n";
		if (b == 0) {
			if (c == 0)
				cout << "Phuong trinh co vo so nghiem\n";
			else
				cout << "Phuong trinh vo nghiem";
		}
		else {
			x1 = -1.0 * c / b;
			cout << "Phuong trinh co mot nghiem duy nhat: x = " << x1 << endl;
		}
	}
	else {
		d = b * b - 4 * a * c;
		//cout << "d = " << d << endl;
		if (d < 0) {
			cout << "Phuong trinh vo nghiem";
		}
		else if (d == 0) {
			x1 = -b * 1.0 / (2 * a);
			cout << "Phuong trinh co mot nghiem kep: x = " << x1 << endl;
		}
		else {
			x1 = 1.0 * (-b + sqrt(d)) / (2 * a);
			x2 = 1.0 * (-b - sqrt(d)) / (2 * a);
			cout << "Phuong trinh co hai nghiem phan biet:\n x1 = " << x1 << ", " << "x2 = " << x2 << "\n";
		}
	}
	return 0;
}