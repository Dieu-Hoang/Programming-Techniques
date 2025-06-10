/*
7. Viết chương trình thực hiện các yêu cầu sau:
-	Nhập số nguyên dương n thỏa mãn 1≤n≤30.
-	Nhập một dãy số a có n số thực.
-	Tách dãy số a thành 2 dãy số b và c sao cho dãy số b gồm các phần tử dương, dãy số c gồm các phần tử âm.
-	Hiển thị hai dãy số b và c ra màn hình.
*/
#include <iostream>
using namespace std;

void nhap(int& n) {
	do {
		cout << "Nhap so nguyen duong n (1 <= n <= 30): ";
		cin >> n;
	} while (n < 1 || n > 30);
}

void nhapDaySo(float* p, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> *(p + i);
	}
}

void hienDaySo(float* p, int n) {
	for (int i = 0; i < n; i++) {
		cout << *(p + i) << " ";
	}
	cout << endl;
}

void tachDaySo(float* p, int n) {
	float* b = new float[n];
	int pB = 0;
	float* c = new float[n];
	int pC = 0;
	for (int i = 0; i < n; i++) {
		if (*(p + i) > 0) {
			*(b + pB) = *(p + i);
			pB++;
		}
		if (*(p + i) < 0) {
			*(c + pC) = *(p + i);
			pC++;
		}
	}
	if (pB > 0) {
		cout << "Cac phan tu duong cua day so a la: ";
		hienDaySo(b, pB);
	}
	else {
		cout << "\nDay so khong co phan tu duong!\n";
	}
	if (pC > 0) {
		cout << "Cac phan tu am cua day so a la: ";
		hienDaySo(c, pC);
	}
	else {
		cout << "\nDay so khong co phan tu am!\n";
	}
	
	delete[] b;
	delete[] c;
}

int main() {
	int n;
	nhap(n);
	float* headA = new float[n];
	float* pA = headA;
	nhapDaySo(pA, n);

	tachDaySo(pA, n);

	delete[] headA;
	return 0;
}