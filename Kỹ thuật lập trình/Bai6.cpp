/*
Viết chương trình thực hiện các yêu cầu sau:
-	Nhập số nguyên dương n thỏa mãn 1≤n≤30.
-	Nhập hai dãy số a và b đều có n số thực.
-	Tạo dãy số c từ hai dãy số a và b sao cho trong dãy số c không tồn tại các phần tử có giá trị bằng nhau.
-	Hiển thị dãy số c ra màn hình.
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

bool tonTaiPhanTu(float* p, int n, float giaTri) {
	for (int i = 0; i < n; i++) {
		if (*(p + i) == giaTri) {
			return true;
		}
	}
	return false;
}

void taoDaySo(float* a, float* b, float* c, int n) {
	int kichThuocC = 0;
	for (int i = 0; i < n; i++) {
		if (tonTaiPhanTu(c, n, *(a + i)) == false) {
			*(c + kichThuocC) = *(a + i);
			kichThuocC += 1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (tonTaiPhanTu(c, n, *(b + i)) == false) {
			*(c + kichThuocC) = *(b + i);
			kichThuocC += 1;
		}
	}
	hienDaySo(c, kichThuocC);
	ofstream outFile;
	outFile.open("Bai6.txt", ios::out);
	if (outFile.is_open()) {
		outFile << "Cac phan tu trong mang c la: ";
		for (int i = 0; i < kichThuocC; i++) {
			outFile << *(c + i) << " ";
		}
		outFile << endl;
		outFile.close();
	}
	else {
		cout << "Khong the mo file!\n";
	}

}

int main() {
	int n;
	nhapSoNguyen(n);

	float* a = new float[n];
	float* b = new float[n];

	cout << "Nhap cac phan tu thuoc day a: \n";
	nhapDaySo(a, n);
	cout << "Nhap cac phan tu thuoc day b: \n";
	nhapDaySo(b, n);

	float* c = new float[2 * n];
	taoDaySo(a, b, c, n);


	delete[] a;
	delete[] b;
	delete[] c;

	return 0;
}