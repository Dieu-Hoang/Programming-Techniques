/*
. Viết chương trình thực hiện các yêu cầu sau:
-	Nhập số nguyên dương n thỏa mãn 1≤n≤30.
-	Nhập một dãy số a có n số nguyên.
-	Hiển thị ra màn hình các số chẵn chia hết cho 3 và vị trí của chúng.
-	Sắp xếp dãy số a sao cho các số chẵn ở đầu dãy số theo thứ tự giảm dần, các số lẻ ở cuối dãy số theo thứ tự giảm dần.
-	Hiển thị dãy số sau khi sắp xếp.
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

void nhapDaySo(int* p, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> *(p + i);
	}
}

void tinhToan(int* p, int n) {
	bool tonTai = false;
	for (int i = 0; i < n; i++) {
		if (*(p + i) % 2 == 0 && *(p + i) % 3 == 0) {
			cout << "So chan chia het cho 3: " << *(p + i) << " tai vi tri " << i + 1 << endl;
			tonTai = true;
		}
	}
	if (tonTai == false) {
		cout << "Khong co so chan chia het cho 3 trong day." << endl;
	}
	else {
		cout << endl;
	}
}

void hienDaySo(int* p, int n) {
	for (int i = 0; i < n; i++) {
		cout << *(p + i) << " ";
	}
	cout << endl;
}

void sapXepGiam(int* p, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (*(p + i) < *(p + j)) {
				int temp = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = temp;
			}
		}
	}
}

void sapXep(int* p, int n) {
	int* chan = new int[n];
	int soChan = 0;
	int* le = new int[n];
	int soLe = 0;
	for (int i = 0; i < n; i++) {
		if (*(p + i) % 2 == 0) {
			chan[soChan] = *(p + i);
			soChan++;
		}
		else {
			le[soLe] = *(p + i);
			soLe++;
		}
	}

	sapXepGiam(chan, soChan);
	sapXepGiam(le, soLe);
	
	for (int i = 0; i < n; i++) {
		if (i < soChan) {
			*(p + i) = *(chan + i);
		}
		else {
			*(p + i) = *(le + i - soChan);
		}
	}
	delete[] chan;
	delete[] le;
}     


int main() {
	int n;
	nhapSoNguyen(n);
	int* head = new int[n];
	int* p = head;

	nhapDaySo(p, n);

	tinhToan(p, n);

	sapXep(p, n);
	cout << "Day so sau khi sap xep la: ";
	hienDaySo(p, n);

	ofstream outFile;
	outFile.open("Bai3.txt", ios::out);
	if (outFile.is_open()) {
		outFile << "Day so sau khi sap xep la: ";
		for (int i = 0; i < n; i++) {
			outFile << *(p + i) << " ";
		}
		outFile << endl;
	}
	else {
		cout << "Khong the mo file!\n";
	}

	delete[] head;
	return 0;
}
