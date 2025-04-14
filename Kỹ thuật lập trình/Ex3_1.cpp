//#include <iostream>
//// #include <iomanip> // thu vien dung ham setprecision
//using namespace std;
//
//long long GT(int n) {
//	long long Gt = 1;
//	if (n == 0 || n == 1) return 1;
//	for (int i = n; i >= 1; i--) {
//		Gt = Gt * i;
//	}
//	return Gt;
//	//return n * GT(n - 1);
//}
//
//int main() {
//	int n;
//	double S;
//	cout << "Nhap so nguyen duong n: ";
//	cin >> n;
//	S = (double) (GT(n) + 1) / GT(n + 1); 
//	cout << "S = " << S << endl;
//	return 0;
//}