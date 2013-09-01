#include <iostream>

using namespace std;

int modC(int c) {
	switch(c % 4) {
		case 0: c = 0;break;
		case 1: c = 5;break;
		case 2: c = 3;break;
		case 3: c = 1;break;
	}

	return c;
}

int main() {
	int N, a, b, c, d, e, f, x, y;

	while(1) {
		cin >> a >> b >> c >> d >> e >> f;
		if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0)break;
		N = f + e + d + (c + 3)/ 4;

		y = 5 * d + modC(c);
		if (b > y) {
			N += (b - y + 8) / 9;
		}

		x = 36 * N - 36 * f - 25 * e - 16 * d - 9 * c - 4 * b;
		if (a > x) {
			N += (a - x + 35) / 36;
		}

		cout << N << endl;
	}

    return 0;
}
