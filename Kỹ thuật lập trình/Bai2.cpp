/*
2. Viết chương trình thực hiện các yêu cầu sau:
-	Nhập số nguyên dương n thỏa mãn 1≤n≤30.
-	Nhập một dãy số a có n số nguyên.
-	Chỉ bằng một lần duyệt dãy số hãy cho biết dãy số a thỏa mãn tính chất nào dưới đây:
	o	Dãy số tăng thực sự (a[i]<a[i+1], 0≤i≤n-2).
	o	Dãy số tăng dần (a[i]≤a[i+1], 0≤i≤n-2).
	o	Dãy số giảm thực sự (a[i]>a[i+1], 0≤i≤n-2).
	o	Dãy số giảm dần (a[i]≥a[i+1], 0≤i≤n-2).
	o	Dãy số không có trật tự nào.
*/

#include <iostream>

using namespace std;

void nhapSoNguyen(int& n) {
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

int main() {
	int n;
	nhapSoNguyen(n);
	int* head = new int[n];
	int* p = head;
	
	nhapDaySo(p, n);

	bool tangThucSu = true, tangDan = true, giamThucSu = true, giamDan = true;
	for (int i = 0; i < n - 1; i++) {
		if (*(p + i) >= *(p + i + 1)) {
			tangThucSu = false;
		}
		if (*(p + i) > *(p + i + 1)) {
			tangDan = false;
		}
		if (*(p + i) <= *(p + i + 1)) {
			giamThucSu = false;
		}
		if (*(p + i) < *(p + i + 1)) {
			giamDan = false;
		}
	}
	if (tangThucSu) {
		cout << "Day so tang thuc su." << endl;
	}
	else if (tangDan) {
		cout << "Day so tang dan." << endl;
	}
	else if (giamThucSu) {
		cout << "Day so giam thuc su." << endl;
	}
	else if (giamDan) {
		cout << "Day so giam dan." << endl;
	}
	else {
		cout << "Day so khong co trat tu nao." << endl;
	}

	delete[] head;
	return 0;
}