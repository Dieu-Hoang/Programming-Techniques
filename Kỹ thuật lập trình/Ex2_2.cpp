#include<iostream>
using namespace std;

int main() {
	//Khai bao va nhap dau vao a, b, c
	int a, b, c;
	cout << "Nhap a: "; cin >> a;
	cout << "Nhap b: "; cin >> b;
	cout << "Nhap c: "; cin >> c;

	//Khai bao delta va dau ra
	double d, x1, x2;
	//Xet truong hop phuong trinh khong phai bac 2
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
	//Truong hop phuong trinh bac 2: Tinh delta va bien luan 
	else {
		d = b * b - 4 * a * c;
		//Neu delta < 0 => Ket luan PT vo nghiem
		if (d < 0) { 
			cout << "Phuong trinh vo nghiem";
		}
		//Neu delta == 0 => Ket luan PT co nghiem kep. Tinh nghiem
		else if (d == 0) {
			x1 = -b * 1.0 / (2 * a);
			cout << "Phuong trinh co nghiem kep: x = " << x1 << endl;
		}
		//Neu delta > 0 => Ket luan PT co nghiem hai nghiem phan biet. Tinh nghiem cua PT
		else {
			x1 = 1.0 * (-b + sqrt(d)) / (2 * a);
			x2 = 1.0 * (-b - sqrt(d)) / (2 * a);
			cout << "Phuong trinh co hai nghiem phan biet:\n x1 = " << x1 << ", " << "x2 = " << x2 << "\n";
		}
	}
	return 0;
}