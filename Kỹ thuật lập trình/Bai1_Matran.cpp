/*
1. Viết chương trình thực hiện các yêu cầu sau:
- Nhập số nguyên dương n thỏa mãn 1≤n≤10.
- Nhập ma trận vuông cấp n với các phần tử là số thực.
- Hiển thị ma trận ra màn hình.
- Tính và hiển thị ra màn hình tổng các phần tử trên đường chéo chính của ma trận.
- Tính và hiển thị ra màn hình tổng của các phần tử trên dòng có chỉ số chẵn, trên cột có
chỉ số lẻ của ma trận.
*/

#include <iostream>
#include <iomanip>
using namespace std;

void nhapSoNguyen(int& n) {
	do {
		cout << "Nhap so nguyen duong n (1 <= n <= 10): ";
		cin >> n;
	} while (n < 1 || n > 10);
}

void nhapMaTran(float** maTran, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Nhap phan tu hang " << i + 1 << " cot " << j + 1 << ": ";
			cin >> *(*(maTran + i) + j);
		}
	}
}

void hienMaTran(float** maTran, int n) {
	cout << "\nMa tran vua nhap la: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << *(*(maTran + i) + j) << " ";
		}
		cout << endl;
	}
}

void tinhTongDuongCheoChinh(float** maTran, int n) {
	float tong = 0;
	for (int i = 0; i < n; i++) {
		tong += *(*(maTran + i) + i);
	}
	cout << "Tong cac phan tu tren duong cheo chinh: " << tong << endl;
}

void tinhTongDongChanCotLe(float** maTran, int n) {
	float tong = 0;
	for (int i = 1; i < n; i += 2) {
		for (int j = 0; j < n; j += 2) {
			tong += *(*(maTran + i) + j);
		}
	}
	cout << "Tong cac phan tu tren dong co chi so chan va cot co chi so le: " << tong << endl;
}

int main() {
	int n;
	nhapSoNguyen(n);
	float** maTran;
	maTran = new float* [n];
	for (int i = 0; i < n; i++) {
		maTran[i] = new float[n];
	}

	nhapMaTran(maTran, n);
	hienMaTran(maTran, n);

	tinhTongDuongCheoChinh(maTran, n);

	tinhTongDongChanCotLe(maTran, n);

	return 0;
}
