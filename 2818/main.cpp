#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int n;
	while (cin >> n && n) {
		int arr[201], mod[201], index[201], k = 0, len = 0;
		char str[201], code[201];
		
		memset(arr,0 ,sizeof arr);

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			arr[i] = arr[i] - 1;
		}

		while (cin >> k && k) {
			memset(str,0 ,sizeof str);
			memset(code,0 ,sizeof code);
			memset(mod,0 ,sizeof mod);
			
			for(int i = 0; i < n; i++) {
                index[i] = i;
            }
			
			for (int i = 0; i < n; i++) {
	            int temp = index[i];
	            while (++mod[i]) {
	                index[i] = arr[index[i]];

	                if (temp == index[i]) break;
	            }
			}
		
			cin.get();//除去空格
			cin.getline(str, n);
			len = strlen(str);

			str[len] = ' ';

			for (int i = 0; i < n; i++) {
				int temp = k % mod[i];

				for (int j = 0; j < temp; j++) {
					index[i] = arr[index[i]];
				}
			}

			for (int i = 0; i < n; i++) {
				code[index[i]] = str[i];
			}

			code[n] = '\0';
            cout << code << endl;
		}
		cout << endl;
	}

	return 0;
}
