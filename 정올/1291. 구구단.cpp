#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
/*
더 깔끔하게 짤 수 있을 것 같은데... 
*/
int main() {

	for (;;) { //문제에서 제대로 출력될 때까지 계속 입력을 받아 처리해야된다. 
		int a, b;
		cin >> a >> b;
		if (a > 9 || b > 9 || a < 2 || b < 2) { // 범위를 넘었을 때
			cout << "INPUT ERROR!"<<endl;
			continue;
		}
		if (a > b) //전체 범위를 출력하기 위해서
			b--;
		else
			b++;
		for (int j = 1; j < 10; j++) {
			for (int i = a; i != b;) {
				cout << i << " * " << j << " = ";
				if (i * j < 10) // 출력 줄을 맞추기 위해서 한자리 수일때 ' '하나를 추가한다.
					cout << " " << i * j << "   ";
				else
					cout << i * j << "   ";
				if (i > b)
					i--;
				else
					i++;
			}
			cout << endl;
		}
		break;
	}
	return 0;
}