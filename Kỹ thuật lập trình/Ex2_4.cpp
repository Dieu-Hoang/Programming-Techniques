#include<iostream>
using namespace std;

bool is_prime(int n) {
	if (n == 1 || n == 0) {
		return false;
	}
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	long long T = 0, D = 0;
	cout << "Enter n: ";
	cin >> n;
	/*bool prime[10005];
	for (int i = 0; i < 10005; i++) {
		prime[i] = true;
	}
	for (int i = 2; i <= n; i += 1) {
		for (int j = i * i; j <= n; j += i) {
			prime[j] = false;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (prime[i] == true) {
			cout << i << "\n";
			T += i;
			D += 1;
		}
	}*/
	for (int i = 2; i <= n; i++) {
		if (is_prime(i)) {
			T += i;
			D++;
		}
	}

	cout << "The sum of prime numbers in range [1, n]: T = " << T << endl;
	cout << "The number of prime numbers in range [1, n]: D = " << D << endl;
	return 0;
}