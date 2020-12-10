#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;
	vector<vector<int>> list;
	if (m == 1) {
		for (int i = 0; i < n; i++) {
			vector<int> a;
			for (int j = 0; j < n; j++) {
				a.push_back(i + 1);
			}
			list.push_back(a);
		}
	}
	else if (m == 2) {
		for (int i = 0; i < n; i++) {
			vector<int> a;
			if (i % 2 == 0) {
				for (int j = 0; j < n; j++) {
					a.push_back(j + 1);
				}
			}
			else {
				for (int j = n; j > 0; j--)
					a.push_back(j);
			}
			list.push_back(a);
		}
	}
	else if (m == 3) {
		for (int i = 0; i < n; i++) {
			vector<int> a;
			for (int j = 1; j <= n; j++) {
				a.push_back(j * (i + 1));
			}
			list.push_back(a);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << list[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}