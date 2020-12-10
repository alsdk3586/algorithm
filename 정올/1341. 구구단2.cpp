#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int main() {

	int a, b;
	cin >> a >> b;
	if (a > b)
		b--;
	else
		b++;
	for (int i = a; i != b;) {

		for (int j = 1; j < 10; j++) {
			cout << i << " * " << j << " = ";
			if (i * j < 10)
				cout << " " << i * j << "   ";
			else
				cout << i * j << "   ";
			if (j % 3 == 0)
				cout << endl;
		}
		cout << endl;
		if (i < b)
			i++;
		else
			i--;
	}


	return 0;
}