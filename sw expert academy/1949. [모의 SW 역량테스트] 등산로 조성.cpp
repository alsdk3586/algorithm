#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef struct node {
	int i;
	int j;
};
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
int max_length = 0;
void search(vector<vector<int>> map, node point, int possible, int count, vector<vector<int>> visit) {

	for (int k = 0; k < 4; k++) {
		if (point.i + dx[k] >= 0 && point.i + dx[k] < map.size() && point.j + dy[k] >= 0 && point.j + dy[k] < map.size()) {
			if (visit[point.i + dx[k]][point.j + dy[k]] == 1)
				continue;
			if (map[point.i + dx[k]][point.j + dy[k]] < map[point.i][point.j]) {
				visit[point.i + dx[k]][point.j + dy[k]] = 1;
				search(map, { point.i + dx[k],point.j + dy[k] }, possible, count + 1, visit);
				visit[point.i + dx[k]][point.j + dy[k]] = 0;
			}
			else if (possible != -1 && map[point.i][point.j] <= map[point.i + dx[k]][point.j + dy[k]]) {
				if (map[point.i + dx[k]][point.j + dy[k]] - map[point.i][point.j] < possible) {
					int box = map[point.i + dx[k]][point.j + dy[k]];
					map[point.i + dx[k]][point.j + dy[k]] = map[point.i][point.j] - 1;
					visit[point.i + dx[k]][point.j + dy[k]] = 1;
					search(map, { point.i + dx[k],point.j + dy[k] }, -1, count + 1, visit);
					map[point.i + dx[k]][point.j + dy[k]] = box;
					visit[point.i + dx[k]][point.j + dy[k]] = 0;
				}
			}
		}
	}
	if (count > max_length) {
		max_length = count;
	}
}


int main() {
	int tc = 0;
	cin >> tc;
	for (int p = 1; p <= tc; p++) {
		int N, K;
		cin >> N >> K;
		max_length = 0;
		vector<vector<int>> map;
		vector<node> list;
		vector<vector<int>> visit;
		int max = 0;
		for (int i = 0; i < N; i++) {
			vector<int> a;
			vector<int> b;
			for (int j = 0; j < N; j++) {
				int box = 0;
				cin >> box;
				a.push_back(box);
				b.push_back(0);
				if (box > max) {
					list.clear();
					max = box;
					list.push_back({ i,j });
				}
				else if (box == max) {
					list.push_back({ i,j });
				}
			}
			map.push_back(a);
			visit.push_back(b);
		}
		for (int i = 0; i < list.size(); i++) {
			visit[list[i].i][list[i].j] = 1;
			search(map, list[i], K, 1, visit);
			visit[list[i].i][list[i].j] = 0;
		}
		cout << "#" << p << " " << max_length << endl;
	}
	return 0;
}