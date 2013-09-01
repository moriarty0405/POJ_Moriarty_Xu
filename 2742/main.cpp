#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int n = 0, arr[26];

	char str[1001];
	cin >> n;

	while (n > 0) {
        for (int i = 0; i < 26; i++) {
            arr[i] = 0;
        }

		int len = 0;
		cin.get();//Çå³ý¿Õ¸ñ
		cin.getline(str, 1000);
		len = strlen(str);

		for (int i = 0; i < len; i++) {
			if (str[i] >= 'a' && str[i] <= 'z'){
				arr[str[i] - 'a']++;
			}
		}

		int max = 0;
		for (int i = 0; i < 26; i++) {
			if (arr[i] > arr[max]) {
				max = i;
			}
		}
		cout << (char)(max + 'a') << " " << arr[max] << endl;

		n--;
	}

	return 0;
}
