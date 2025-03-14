//#include<iostream>
//#include<cmath>
//#include<iomanip> // Thu vien dung dinh dang nhap xuat
//using namespace std;
//
//int main() {
//	//Khai bao va nhap dau vao, ra
//	double x, S;
//	int n;
//	cout << "Enter x: ";
//	cin >> x;
//	cout << "Enter n: ";
//	cin >> n;
//	//2.Xu ly
//	//Neu n chan: Tinh S theo truong hop n chan
//	if (n % 2 == 0) {
//		S = 2016 * x;
//		for (int i = 2; i <= n; i++) {
//			S += pow(x, i) / pow(3, i - 1);
//		}
//	}
//	//Neu n le: Tinh S theo truong hop n le
//	else
//		S = 0;
//	cout << "S = " <<setprecision(5)<< S;
//	return 0;
//}