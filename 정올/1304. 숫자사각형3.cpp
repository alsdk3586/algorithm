#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int main() {

	int n = 0;
	cin >> n;
	vector<vector<int>> list;
	int number = 1;
	for (int i = 0; i < n; i++) {
		vector<int> a;
		for (int j = 0; j < n; j++) {
			a.push_back(number++);
		}
		list.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << list[j][i] << " ";
		}
		cout << endl;
	}

	return 0;
}