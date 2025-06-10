/*
. Viết chương trình thực hiện các yêu cầu sau:
-	Nhập số nguyên dương n thỏa mãn 1≤n≤30.
-	Nhập một dãy số a có n số nguyên.
-	Hiển thị ra màn hình các phần tử dãy số là số nguyên tố, số phần tử và tổng của chúng.
*/
#include <iostream>
using namespace std;

void nhap(int& n) {
	do {
		cout << "Nhap so nguyen duong n (1 <= n <= 30): ";
		cin >> n;
	} while (n < 1 || n > 30);
}

void nhapDaySo(int* p, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> *(p + i);
	}

}

bool laSoNto(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void timSoNguyenTo(int* p, int n) {
	int dem = 0;
	int tong = 0;
	for (int i = 0; i < n; i++) {
		if (laSoNto(*(p + i)) == true) {
			//cout << *(p + i) << " ";
			dem++;
			tong += *(p + i);
		}
	}
	if (dem != 0) {
		cout << "Phan tu la so nguyen to cua day la: ";
		for (int i = 0; i < n; i++) {
			if (laSoNto(*(p + i)) == true) {
				cout << *(p + i) << " ";
			}
		}
		cout << "\nSo phan tu la so nguyen to la: " << dem << endl;
		cout << "Tong so phan tu la: " << tong << endl;
	}
	else {
		cout << "Khong ton tai phan tu la so nguyen to trong day so!";
	}
	
}

int main() {
	int n;
	nhap(n);
	int* head = new int[n];
	int* p = head;
	nhapDaySo(p, n);
	timSoNguyenTo(p, n);

	return 0;
}