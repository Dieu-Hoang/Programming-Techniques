/*
2. Viết chương trình thực hiện các yêu cầu sau:
- Nhập ma trận A cấp mxn (1≤m,n≤20, m, n nhập từ bàn phím).
- Nhập ma trận B cấp pxq  (1≤p,q≤20, p, q nhập từ bàn phím).
- Tạo ma trận C=A+B, hiển thị ma trận C ra màn hình.
- Tạo ma trận D=AxB, hiển thị ma trận D ra mà
*/
#include <iostream>
using namespace std;

void nhapKichThuoc(int& m, int& n) {
	do {
		cout << "Nhap so hang: ";
		cin >> m;
		cout << "Nhap so cot: ";
		cin >> n;
	} while (m < 1 || m > 20);
}

void nhapMaTran(float** A, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Nhap phan tu tai hang " << i + 1 << ", cot " << j + 1 << ": ";
			cin >> *(*(A + i) + j);
		}
	}
}

void hienMaTran(float** A, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << *(*(A + i) + j) << " ";
		}
		cout << endl;
	}
}

void tinhTong(float** A, int m, int n, float** B, int p, int q) {
	if (m != p || n != q) {
		cout << "Khong the tinh tong, kich thuoc hai ma tran khong phu hop!" << endl;
	}
	else {
		float** C = new float* [m];
		for (int i = 0; i < m; i++) {
			*(C + i) = new float[n];
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				*(*(C + i) + j) = *(*(A + i) + j) + *(*(B + i) + j);
			}
		}
		cout << "Ma tran tong C = A + B: \n";
		hienMaTran(C, m, n);
		for (int i = 0; i < m; i++) {
			delete[] C[i];
		}
	}
}

void tinhTich(float** A, int m, int n, float** B, int p, int q) {
	if (m != q) {
		cout << "Khong the tinh tich, so hang cua A phai bang so cot cua B!" << endl;
	}
	else {
		float** D = new float* [m];
		for (int i = 0; i < m; i++) {
			*(D + i) = new float[q];
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < q; j++) {
				*(*(D + i) + j) = 0;
				for (int k = 0; k < m; k++) {
					*(*(D + i) + j) += *(*(A + i) + k) * *(*(B + k) + j);
				}
			}
		}
		cout << "Ma tran tich D = A * B: \n";
		hienMaTran(D, m, q);
		for (int i = 0; i < m; i++) {
			delete[] D[i];
		}
	}
}

int main() {
	int m, n, p, q;
	cout << "Nhap kich thuoc ma tran A:" << endl;
	nhapKichThuoc(m, n);
	float** A = new float* [m];
	for (int i = 0; i < m; i++) {
		*(A + i) = new float[n];
	}
	cout << "Nhap kich thuoc ma tran B:" << endl;
	nhapKichThuoc(p, q);
	float** B = new float* [p];
	for (int i = 0; i < p; i++) {
		*(B + i) = new float[q];
	}

	// Nhập ma trận A
	cout << "Nhap ma tran A:" << endl;
	nhapMaTran(A, m, n);

	// Nhập ma trận B
	cout << "Nhap ma tran B:" << endl;
	nhapMaTran(B, p, q);

	tinhTong(A, m, n, B, p, q);
	tinhTich(A, m, n, B, p, q);

	for (int i = 0; i < m; i++) {
		delete[] A[i];
	}
	for (int i = 0; i < p; i++) {
		delete[] B[i];
	}

	return 0;
}
