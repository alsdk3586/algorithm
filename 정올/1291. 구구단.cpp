#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
/*
�� ����ϰ� © �� ���� �� ������... 
*/
int main() {

	for (;;) { //�������� ����� ��µ� ������ ��� �Է��� �޾� ó���ؾߵȴ�. 
		int a, b;
		cin >> a >> b;
		if (a > 9 || b > 9 || a < 2 || b < 2) { // ������ �Ѿ��� ��
			cout << "INPUT ERROR!"<<endl;
			continue;
		}
		if (a > b) //��ü ������ ����ϱ� ���ؼ�
			b--;
		else
			b++;
		for (int j = 1; j < 10; j++) {
			for (int i = a; i != b;) {
				cout << i << " * " << j << " = ";
				if (i * j < 10) // ��� ���� ���߱� ���ؼ� ���ڸ� ���϶� ' '�ϳ��� �߰��Ѵ�.
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