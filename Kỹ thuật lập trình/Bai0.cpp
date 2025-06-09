/*
0. Chèn dữ liệu vào dãy số
Viết chương trình thực hiện các yêu cầu sau.
-	Nhập số nguyên dương n thỏa mãn 1≤n≤20.
-	Nhập dãy số có n số thực.
-	Hiển thị dãy số vừa nhập ra màn hình.
-	Nhập vào số thực x và số nguyên k thỏa mãn 1≤k.
Chèn số thực x vào vị trí thứ k trong dãy số nếu k ≤ n, ngược lại chèn x vào vị trí thứ n+1.
*/
#include <iostream>

using namespace std;

void nhapSoNguyen(int& n) {
	do {
		cout << "Nhap so nguyen duong n (1 <= n <= 20): ";
		cin >> n;
	} while (n < 1 || n > 20);
}

void nhapMang(float* p, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> *(p + i);
	}
}

void hienMang(float* p, int n) {
	for (int i = 0; i < n; i++) {
		cout << *(p + i) << " ";
	}
	cout << endl;
}

void chenMang(float* p, int& n) {
	float x;
	int k;
	cout << "\nNhap so thuc x: ";
	cin >> x;
	do {
		cout << "Nhap vi tri k (1 <= k <= " << n << "): ";
		cin >> k;
	} while (k < 1);
	if (k >= n) {
		*(p + n) = x; 
	}
	else {
		for (int i = n - 1; i >= k; i--) {
			*(p + i + 1) = *(p + i);
		}
		*(p + k - 1) = x; // Chen x vao vi tri k-1 (vi tri thuc te)
	}
	n++;
}

int main() {
	int n;
	nhapSoNguyen(n);
	float* head, * p;
	head = new float[n + 2];
	p = head;
	nhapMang(p, n);
	cout << "Mang da nhap: ";
	hienMang(p, n);
	
	chenMang(p, n);
	cout << "Mang sau khi chen: ";
	hienMang(p, n);

	delete[] head; 
	return 0;
}
