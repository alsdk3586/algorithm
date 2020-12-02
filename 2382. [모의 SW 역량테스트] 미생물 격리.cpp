#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;


typedef struct node {
	int i;
	int j;
	int amount;
	int direct;
};
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int change[] = { 1,0,3,2 };
int comapre(node a, node b) {
	if (a.i == b.i)
		if (a.j == b.j)
			return a.amount > b.amount;
		else
			return a.j < b.j;
	return a.i < b.i;
}
int main() {

	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);


	int tc = 0;
	cin >> tc;
	for (int p = 1; p <= tc; p++) {
		int n, m, k;
		int map[110][110] = { 0 };
		cin >> n >> m >> k;
		vector <node>list;
		for (int i = 0; i < n; i++) {
			map[0][i] = -1;
			map[n - 1][i] = -1;
			map[i][0] = -1;
			map[i][n - 1] = -1;
		}
		for (int i = 0; i < k; i++) {
			int x, y, amount, direct;
			cin >> x >> y >> amount >> direct;
			list.push_back({ x,y,amount,direct - 1 });
		}

		for (int t = 0; t < m; t++) {
			for (int l = 0; l < list.size(); l++) {
				if (list[l].i == -1)
					continue;
				int x = list[l].i + dx[list[l].direct];
				int y = list[l].j + dy[list[l].direct];
				if (map[x][y] == -1) {
					list[l].direct = change[list[l].direct];
					list[l].amount /= 2;
				}
				list[l].i = x;
				list[l].j = y;
			}
			sort(list.begin(), list.end(), comapre);
			for (int l = 0; l < list.size(); l++) {
				int max_index = l;
				for (int ll = l + 1; ll < list.size(); ll++) {

					if (list[l].i == list[ll].i && list[l].j == list[ll].j) {

						list[max_index].amount += list[ll].amount;
						list[ll].i = -1;

					}
					else {
						l = ll - 1;
						break;
					}
				}

			}
		}
		int answer = 0;
		for (int l = 0; l < list.size(); l++) {
			if (list[l].i != -1)
				answer += list[l].amount;
		}
		cout << "#" << p << " " << answer << endl;
	}
	return 0;
}