/*
3. Viết chương trình thực hiện các yêu cầu sau:
- Nhập số nguyên dương m là số lượng vận động viên tham gia thi đấu môn cử tạ (1≤m≤10).
- Nhập số nguyên dương n là số lần cử tạ của mỗi vận động viên (1≤n<=5).
- Nhập bảng thành tích cử tạ của các vận động viên (tính bằng kg).
- Hiển thị bảng thành tích.
- Cho biết thành tích cử tạ cao nhất là bao nhiêu kg.
- Cho biết vận động viên nào có tổng thành tích cử tạ cao nhất và thành tích đó là bao nhiêu
kg.
*/
#include <iostream>
#include <iomanip> // Thư viện để sử dụng setw
using namespace std;

void nhapSoNguyen(int& x, int max) {
	do {
		cout << "Nhap mot so nguyen duong: ";
		cin >> x;
	} while (x < 1 || x > max);
}

void nhapBang(float** bang, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Nhap thanh tich (kg) cua van dong vien " << i + 1 << " lan cu ta thu " << j + 1 << ": ";
			cin >> bang[i][j];
		}
	}
	cout << endl;
}

void hienBang(float** bang, int m, int n) {
	cout << "Bang thanh tich cu ta:\n";
	cout << setw(10) << "Van Dong Vien";
	for (int j = 0; j < n; j++) {
		cout << setw(10) << "Lan " << j + 1 << " (kg)";
	}
	cout << endl;
	cout << "--------------------------------------------------------\n";
	for (int i = 0; i < m; i++) {
		cout << setw(6) << "VDV "<< i + 1;
		for (int j = 0; j < n; j++) {
			cout << setw(16) << bang[i][j];
		}
		cout << endl;
	}
	cout << "--------------------------------------------------------\n";
}

void timMaxThanhTich(float** bang, int m, int n) {
	float maxThanhTich = bang[0][0];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (bang[i][j] > maxThanhTich) {
				maxThanhTich = bang[i][j];
			}
		}
	}
	cout << "Thanh tich cu ta cao nhat la: " << maxThanhTich << " kg.\n";
}

void timMaxTongThanhTich(float** bang, int m, int n) {
	float maxTong = 0;
	int vanDongVienMax = 0;
	for (int i = 0; i < m; i++) {
		float tongThanhTich = 0;
		for (int j = 0; j < n; j++) {
			tongThanhTich += bang[i][j];
		}
		if (tongThanhTich > maxTong) {
			maxTong = tongThanhTich;
			vanDongVienMax = i + 1; // Lưu số thứ tự vận động viên
		}
	}
	cout << "Van dong vien " << vanDongVienMax << " co tong thanh tich cao nhat: " << maxTong << " kg.\n";
}

int main() {
	int m, n;
	cout << "Nhap so luong van dong vien (1 <= m <= 10): \n";
	nhapSoNguyen(m, 10);
	cout << "Nhap so lan cu ta cua moi van dong vien (1 <= n <= 5): \n";
	nhapSoNguyen(n, 5);

	float** bang = new float* [m];

	for (int i = 0; i < m; i++) {
		bang[i] = new float[n];
	}
	
	nhapBang(bang, m, n);
	hienBang(bang, m, n);

	timMaxThanhTich(bang, m, n);
	timMaxTongThanhTich(bang, m, n);

	for (int i = 0; i < m; i++) {
		delete[] bang[i];
	}

	return 0;
}
