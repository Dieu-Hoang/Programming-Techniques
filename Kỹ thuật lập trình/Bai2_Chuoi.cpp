/*
2. Thống kê chuỗi.
Viết chương trình thực hiện các yêu cầu:
- Nhập vào một đoạn văn bản không quá 255 ký tự.
- Hiển thị đoạn văn bản sau khi nhập.
- Cho biết trong đoạn văn bản có bao nhiêu ký tự là chữ số, bao nhiêu ký tự không phải là chữ cái latin.
- Nhập vào một từ bất kỳ, cho biết từ này có xuất hiện trong chuỗi hay không? Nếu có hãy chỉ
ra vị trí bắt đầu xuất hiện từ này trong chuỗi.
*/
#include <iostream>
#include <cstring>
#include <string>
#define MAX 257

using namespace std;

void nhapVB(char* vanBan) {
	while (true) {
		cout << "Nhap van ban (toi da 255 ky tu): ";
		cin.getline(vanBan, MAX);
		int doDai = strlen(vanBan);
		if (doDai <= MAX - 2) {
			break;
		}
		else {
			cout << "Van ban qua dai! Vui long nhap lai.\n\n";
			// Xóa bộ đệm nếu cần thiết (nếu còn dữ liệu dư)
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
}

bool laChuSo(char x) {
	if (x > '9' || x < '0') {
		return false;
	}
	return true;
}

bool laChuCai(char x) {
	bool laChuCai = false;
	if ((x < 'Z' && x > 'A') || (x < 'z' && x > 'a')) {
		laChuCai = true;
	}
	return laChuCai;
}

void demChuSo(char* vanBan, int size) {
	int dem = 0;
	for (int i = 0; i < size; i++) {
		if (laChuSo(*(vanBan + i))) {
			dem += 1;
		}
	}
	if (dem == 0) cout << "Van ban khong co ky tu nao la chu so!\n";
	else cout << "So ky tu la chu so trong doan van ban la: " << dem << endl;
}

void demKyTuKhacLatin(char* vanBan, int size) {
	int dem = 0;
	for (int i = 0; i < size; i++) {
		if (!laChuCai(*(vanBan + i))) {
			dem += 1;
		}
	}
	if (dem == 0) cout << "Van ban khong co ky tu nao khong la chu cai Latin!\n";
	else cout << "So ky tu khong la chu cai Latin la: " << dem << endl;

}

int coKyTu(char* vanBan, int size, char x) {
	int ans = -1;
	for (int i = 0; i < size; i++) {
		if (*(vanBan + i) == x) {
			ans = i;
			break;
		}
	}
	return ans;
}

void timChuoicon(char* vanBan, int size) {
	char tiepTuc;
	do {
		string chuoiCon;
		cout << "Nhap chuoi con: ";
		cin >> chuoiCon;
		int viTri = coKyTu(vanBan, size, chuoiCon[0]);
		if (viTri > -1) {
			int k = 0;
			for (int i = viTri; k < chuoiCon.length(); i++, k++) {
				if (*(vanBan + i) != chuoiCon[k]) {
					viTri = -1;
					break;
				}
			}
		}
		if (viTri != -1) cout << "Vi tri cua tu trong chuoi la: " << viTri + 1 << endl;
		else cout << "Khong co tu trong chuoi!\n";
		cout << "Ban co muon tim tiep khong (y/n): ";
		cin >> tiepTuc;
	} while (tiepTuc == 'y');
}

int main() {
	char* vanBan = new char[MAX];
	nhapVB(vanBan);
	//string s = "Hello 1005, C++!";
	/*int size = s.length();
	for (int i = 0; i < size; i++) {
		*(vanBan + i) = s[i];
	}*/
	int size = strlen(vanBan);
	cout << "Doan van ban vua nhap: ";
	for (int i = 0; i < size; i++) {
		cout << *(vanBan + i);
	}
	cout << endl;

	// dem so luong ky tu la chu so
	demChuSo(vanBan, size);

	// dem so luong ky tu khong phai la chu cai Latin
	demKyTuKhacLatin(vanBan, size);

	// xac dinh vi tri cua tu xuat hien trong chuoi
	timChuoicon(vanBan, size);

	delete[] vanBan;
	return 0;
}
