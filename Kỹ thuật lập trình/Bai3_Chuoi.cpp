/*
3. Viết chương trình nhập vào hai chuỗi str1 và str2.
Hãy cho biết:
- Hai chuỗi có bằng nhau hay không nếu phân biệt chữ hoa và chữ thường.
- Hai chuỗi có bằng nhau hay không nếu không phân biệt chữ hoa và chữ thường.
- Hai chuỗi có bằng nhau hay không nếu chỉ tính 3 ký tự đầu tiên.
*/

#include <iostream>

using namespace std;

void nhapChuoiKyTu(char* str) {
	cout << "Nhap chuoi ky tu: ";
	cin >> str;
}

bool soSanhPhanBiet(char* str1, char* str2, int size = 0) {
	bool giongNhau = true;
	if (size != 0) {
		for (int i = 0; i < size; i++) {
			if (str1[i] != str2[i]) {
				giongNhau = false;
				break;
			}
		}
	}
	else if (strlen(str1) == strlen(str2)) {
		for (int i = 0; i < strlen(str1); i++) {
			if (str1[i] != str2[i]) {
				giongNhau = false;
				break;
			}
		}
	}

	return giongNhau;
}

char* chuyenThanhChuThuong(char* str) {
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] < 'Z' && str[i] > 'A') {
			str[i] += 32;
		}
	}
	return str;
}

bool soSanhKhongPhanBiet(char* str1, char* str2) {
	str1 = chuyenThanhChuThuong(str1);
	str2 = chuyenThanhChuThuong(str2);
	return soSanhPhanBiet(str1, str2);

}

int main() {
	char* str1 = new char[100];
	char* str2 = new char[100];

	cout << "Nhap chuoi ky tu thu nhat: \n";
	nhapChuoiKyTu(str1);
	cout << "Nhap chuoi ky tu thu hai: \n";
	nhapChuoiKyTu(str2);

	// so sanh 2 chuoi ky tu phan biet chu hoa va chu thuong
	if (soSanhPhanBiet(str1, str2)) cout << "Hai chuoi giong nhau neu phan biet chu hoa va chu thuong!\n";
	else cout << "Hai chuoi khac nhau neu phan biet chu hoa va chu thuong!\n";

	if (soSanhKhongPhanBiet(str1, str2)) cout << "Hai chuoi giong nhau neu khong phan biet chu hoa va chu thuong!\n";
	else cout << "Hai chuoi khac nhau neu khong phan biet chu hoa va chu thuong!\n";

	if (soSanhPhanBiet(str1, str2, 3)) cout << "Hai chuoi giong nhau neu chi tinh 3 ky tu dau tien!\n";
	else cout << "Hai chuoi khac nhau neu chi tinh 3 ky tu dau tien!\n";

	delete[] str1;
	delete[] str2;
	return 0;
}
