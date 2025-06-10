/*
Viết chương trình thực hiện các yêu cầu sau:
-	Nhập số nguyên dương n thỏa mãn 1≤n≤30.
-	Nhập một dãy số a có n số thực.
-	Hiển thị dãy số a theo chiều ngược lại với thứ tự nhập.
-	Sắp xếp dãy số a theo thứ tự giảm dần, hiển thị dãy số sau khi sắp xếp.
-	Nhập số thực x, chèn x vào dãy số a sao cho trật tự của dãy số a không bị thay đổi.
*/
#include <iostream>
#include <fstream>
using namespace std;

void nhapSoNguyen(int& n) {
	do {
		cout << "Nhap so nguyen duong n (1 <= n <= 30): ";
		cin >> n;
	} while (n < 1 || n > 30);
}

void nhapDaySo(float* p, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap phan tu thu " << i + 1 << " : ";
		cin >> *(p + i);
	}
}

void hienNguocDaySo(float* p, int n) {
	for (int i = n - 1; i >= 0; i--) {
		cout << *(p + i) << " ";
	}
	cout << endl;

	ofstream outFile;
	outFile.open("Bai5.txt", ios::out);
	if (outFile.is_open()) {
		outFile << "Day so nguoc lai la: ";
		for (int i = n - 1; i >= 0; i--) {
			outFile << *(p + i) << " ";
		}
		outFile << endl;
		outFile.close();
	}
}

void hienDaySo(float* p, int n) {
	for (int i = 0; i < n; i++) {
		cout << *(p + i) << " ";
	}
	cout << endl;
}

void sapXepGiam(float* p, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (*(p + i) < *(p + j)) {
				float tam = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = tam;
			}
		}
	}
	ofstream outFile;
	outFile.open("Bai5.txt", ios::app);
	if (outFile.is_open()) {
		outFile << "Day so sau khi sap xep giam dan la: ";
		for (int i = 0; i < n; i++) {
			outFile << *(p + i) << " ";
		}
		outFile << endl;
		outFile.close();
	}
}

void chenSo(float* p, int& n) {
	float x;
	cout << "Nhap so thuc x: ";
	cin >> x;
	for (int i = 0; i < n; i++) {
		if (*(p + i) >= x && *(p + i + 1) <= x) {
			for (int j = n; j > i + 1; j--) {
				*(p + j) = *(p + j - 1);
			}
			*(p + i + 1) = x;
			n++;
			break;
		}
	}
	cout << "Day so sau khi chen x = " << x << " la: ";
	hienDaySo(p, n);
	ofstream outFile;
	outFile.open("Bai5.txt", ios::app);
	if (outFile.is_open()) {
		outFile << "Day so sau khi chen la: ";
		for (int i = 0; i < n; i++) {
			outFile << *(p + i) << " ";
		}
		outFile << endl;
		outFile.close();
	}
}

int main() {
	int n;
	nhapSoNguyen(n);
	float* head = new float[n + 1];
	float* p = head;

	nhapDaySo(p, n);

	cout << "Day so co chieu nguoc lai voi thu tu nhap la: ";
	hienNguocDaySo(p, n);

	sapXepGiam(p, n);
	cout << "Day so sau khi sap xep giam dan la: ";
	hienDaySo(p, n);
		
	chenSo(p, n);

	delete[] head;
	return 0;
}