/*
1. Chuẩn hóa chuỗi ký tự
Viết chương trình thực hiện các yêu cầu:
- Nhập vào một chuỗi khác rỗng là họ tên của một người.
- Xóa các dấu cách thừa trong chuỗi. (trước và sau chuỗi không có khoảng trắng, giữa các từ
có một khoảng trắng)
- Chuẩn hóa chuỗi thành một danh từ riêng (Viết hoa ký tự đầu của mỗi từ).
- Hiển thị chuỗi ra màn hình.
*/
#include <iostream>
#include <string.h>
using namespace std;

void nhapTen(char* ten) {
	do {
		cout << "Nhap ho ten: ";
		cin.getline(ten, 100);
		if (!strcmp(ten, "")) cout << "Vui long nhap lai ho ten!\n";
	} while (!strcmp(ten, ""));
}

void xoaPhanTu(char* ten, int& n, int x) {
	for (int i = x; i + 1 < n; i++) {
		ten[i] = ten[i + 1];
	}
	n--;
}

void xoaDauCachThua(char* ten, int& doDai) {
	// xoa dau cach thua giua cac tu
	for (int i = 0; i + 1 < doDai; i++) {
		if (*(ten + i) == ' ' && *(ten + i + 1) == ' ') {
			xoaPhanTu(ten, doDai, i);
			i--;
			//doDai--;
		}
	}
	// xoa dau cach dau cac tu
	for (int i = 0; i + 1 < doDai && *(ten + i) == ' '; i++) {
		xoaPhanTu(ten, doDai, i);
		i--;
		//doDai--;
	}
	// xoa dau cach sau cac tu
	for (int i = doDai - 1; i > 1 && *(ten + i) == ' '; i--) {
		doDai--;
	}
}

void chuanHoa(char* ten, const int& doDai) {
	for (int i = 1; i < doDai; i++) {
		if (*(ten) <= 'z' && *(ten) >= 'a') {
			*(ten) += 'A' - 'a';
		}
		if (*(ten + i - 1) == ' ' && *(ten + i) <= 'z' && *(ten + i) >= 'a') {
			*(ten + i) = *(ten + i) - 32;
		}
		else if (*(ten + i - 1) != ' ' && *(ten + i) <= 'Z' && *(ten + i) >= 'A') {
			*(ten + i) += 32;
		}
	}
}

void hienTen(char* ten, const int& doDai) {
	cout << "Ten sau khi duoc chuan hoa la: ";
	for (int i = 0; i < doDai; i++) {
		cout << ten[i];
	}
	cout << endl;
}

int main()
{
	char* ten = new char[100];
	nhapTen(ten);
	int doDai = strlen(ten);
	//cout << "do dai chuoi: " << doDai << endl;
	xoaDauCachThua(ten, doDai);

	// chuan hoa danh tu rieng
	//cout << "do dai sau khi xoa: " << doDai << endl;
	chuanHoa(ten, doDai);

	hienTen(ten, doDai);
	return 0;
}
