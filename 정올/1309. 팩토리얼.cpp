#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std; 

void factoral(int n, long long answer) {
	if (n == 0) {
		cout << n + 1 << "! = " << n + 1 << endl;
		cout << answer << endl;
		return;
	}
	cout << n + 1 << "! = " << n + 1 << " * " << n << "!" << endl;
	factoral(n - 1, answer * n);
}
int main() {

	long long n = 0;
	cin >> n;
	factoral(n - 1, n);


	return 0;
}