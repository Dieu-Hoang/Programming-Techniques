#include<iostream>
using namespace std;

int main() {
	//Khai bao va nhap so dien tieu thu, khai bao dap an
	int a, ans = 0;
	cout << "Enter electricity meter reading: ";
	cin >> a;
	//cout << a;
	if (0 < a && a <= 100)
		ans = 750 * a;
	else if (101 <= a && a <= 200)
		ans = 750 * 100 + 1250 * (a - 100);
	else if (201 <= a && a <= 300)
		ans = 750 * 100 + 1250 * 100 + 1750 * (a - 200);
	else
		ans = 750 * 100 + 1250 * 100 + 1750 * 100 + 3000 * (a - 300);
	//2. Tinh so tien phai tra theo 4 muc
	//3. In so tien phai tra ra man hinh
	cout << "The total amount due is " << ans << "d";
	return 0;
}