/*
4. Viết chương trình thực hiện các yêu cầu sau:
-	Nhập số nguyên dương n thỏa mãn 1≤n≤30.
-	Nhập một dãy số a có n số thực.
-	Tìm và in ra màn hình các số âm có trị tuyệt đối lớn hơn 5 và giá trị trung bình cộng của chúng.
-	Nhập số nguyên k bất kỳ, xóa phần tử thứ k trong dãy số a nếu k thỏa mãn, 
	hiển thị lại dãy số sau khi xóa, hoặc thông báo k không thỏa mãn.
*/
#include <iostream>
#include <math.h>
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

void tinhToan(float* p, int n) {
	float dem = 0;
	float tong = 0;
	for (int i = 0; i < n; i++) {
		if (fabs(*(p + i)) > 5 && *(p + i) < 0) {
			//cout << *(p + i) << " ";
			tong += *(p + i);
			dem++;
		}
	}
	if (dem == 0) {
		cout << "Day so khong co so am co gia tri tuyet doi lon hon 5!\n";
	}
	else {
		cout << "Cac so am co gia tri tuyet doi lon hon 5 la: ";
		for (int i = 0; i < n; i++) {
			if (fabs(*(p + i)) > 5 && *(p + i) < 0) {
				cout << *(p + i) << " ";
			}
		}
		cout << "\nTrung binh cong cua cac so am co gia tri tuyet doi lon hon 5 la: " << tong / dem << endl;
	}

}

void xoaPhanTu(float* p, int& n, int k) {
	if (k < 1 || k > n) {
		cout << "Vi tri k = " << k << " khong thoa man!\n";
		return;
	}
	for (int i = k - 1; i < n - 1; i++) {
		*(p + i) = *(p + i + 1);
	}
	n--;
	cout << "Day so sau khi xoa phan tu tai vi tri k = " << k << ": ";
	hienDaySo(p, n);
}

int main() {
	int n;
	nhapSoNguyen(n);
	float* head = new float[n];
	float* p = head;
	nhapDaySo(p, n);

	tinhToan(p, n);

	int k; 
	cout << "Nhap vi tri phan tu muon xoa: ";
	cin >> k;
	xoaPhanTu(p, n, k);
	//hienDaySo(p, n);

	ofstream outFile("Bai4.txt", ios::out); 
	if (outFile.is_open()) {
		outFile << "Day so sau khi xoa phan tu tai vi tri k = " << k << " la: ";
		for (int i = 0; i < n; i++) {
			outFile << *(p + i) << " ";
		}
		outFile << endl;
		outFile.close();
	}
	else {
		cout << "Khong the mo file!\n";
	}
	delete[] head;
	return 0;
}