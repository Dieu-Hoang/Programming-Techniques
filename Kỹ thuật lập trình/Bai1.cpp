/*
1. Viết chương trình thực hiện các yêu cầu sau:
-	Nhập số nguyên dương n thỏa mãn 1≤n≤30.
-	Tạo một dãy số a có n số nguyên sao cho a[0]=1, a[1]=1, a[i]=a[i-1]+a[i-2] khi i≥2.
-	Hiển thị dãy số a ra màn hình.
-	Tính và hiển thị ra màn hình tổng tất cả các phần tử dữ liệu của dãy số a.
-	Tìm phần tử nhỏ nhất (min) của a, thay tất cả các phần tử min bằng số 0
*/
#include <iostream>
#include <fstream>

using namespace std;

void nhapSoNguyen(int& n) {
	do {
		cout << "Nhap so nguyen duong n (1 <= n <= 30): ";
		cin >> n;
	}
	while (n < 1 || n > 30);
}

void nhapDaySo(int* p, int n) {
	*p = 1;
	*(p + 1) = 1;
	for (int i = 2; i < n; i++) {
		*(p + i) = *(p + i - 1) + *(p + i - 2);
	}
}

void hienMang(int* p, int n) {
	for (int i = 0; i < n; i++) {
		cout << *(p + i) << " ";
	}
	cout << endl;
}

int tinhTong(int* p, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += *(p + i);
	}
	return sum;
}

int timSoNhoNhat(int* p, int n) {
	int min = *p;
	for (int i = 0; i < n; i++) {
		if (min > *(p + i)) {
			min = *(p + i);
		}
	}
	return min;
}

void thaySoNhoNhat(int* p, int n) {
	int min = timSoNhoNhat(p, n);
	for (int i = 0; i < n; i++) {
		if (*(p + i) == min) {
			*(p + i) = 0;
		}
	}
}

int main() {
	int n;
	nhapSoNguyen(n);
	int* head, * p;
	head = new int[n];
	p = head;
	nhapDaySo(p, n);

	cout << "Day so a: ";
	hienMang(p, n);

	// Ghi ra file
	ofstream of1("Bai1.txt", ios::out);
	if (of1.is_open()) {
		of1 << "Day so vua nhap la: ";
		for (int i = 0; i < n; i++) {
			of1 << *(p + i) << " ";
		}
		of1 << endl;
		of1.close();
	}
	else {
		cout << "Khong the mo file\n";
	}

	int sum = tinhTong(p, n);
	cout << "Tong cac phan tu la: " << sum << endl;

	thaySoNhoNhat(p, n);
	cout << "Day so sau khi thay so nho nhat bang so 0 la: ";
	hienMang(p, n);

	ofstream of2("Bai1.txt", ios::app);
	if (of2.is_open()) {
		of2 << "Day so vua nhap la: ";
		for (int i = 0; i < n; i++) {
			of2 << *(p + i) << " ";
		}
		of2 << endl;
		of2.close();
	}
	else {
		cout << "Khong the mo file\n";
	}


	delete[] head;
	return 0;
}