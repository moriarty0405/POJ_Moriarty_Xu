#include <iostream>

using namespace std;

int main() {
	int n, x = 0, y = 0, w = 0, l = 0;
	cin >> n;
	
	bool flag = false;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t;
			cin >> t;
			
			//记下第一个0的坐标
			if (t == 0 && !flag) {
				x = j;
				y = i;
				flag = true;
			}
			
			//经过循环计算出长度
			if (t == 0 && flag) {
				w = j - x;
				l = i - y;
			}
		}
	}
	
	cout << (w - 1) * (l - 1) << endl;
	
	return 0;
}
