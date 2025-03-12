#include<iostream>
using namespace std;

int main() {
	int n;
	cout << "Enter number: ";
	cin >> n;
	int N, T, C, D;
	N = n / 1000;
	n %= 1000;
	T = n / 100;
	n %= 100;
	C = n / 10;
	n %= 10;
	D = n;
	cout << N << " ngàn " << T << " trăm " << C << " chục " << D << " đơn vị ";
	return 0;
}