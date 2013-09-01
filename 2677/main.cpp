#include <iostream>

using namespace std;


int main() {
	int n, square = 0, length = 0;
	bool matrix[101][101];
	cin >> n;
	
	for (int i = 0; i< 101; i++) {
		for (int j = 0; j < 101; j++) {
			matrix[i][j] = false;
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t = 0;
			cin >> t;
			
			if (t <= 50) {
				square++;
				matrix[i][j] = true;
			}
		}
	}
	
	for (int i = 0; i< 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (matrix[i][j]) {
				if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
					length++;
				} else if (!(matrix[i - 1][j] & matrix[i + 1][j] 
					& matrix[i][j + 1] & matrix[i][j - 1])) {
					length++;
				}
			}
		}
	} 
	
	cout << square << " " << length;
	
	return 0;
}