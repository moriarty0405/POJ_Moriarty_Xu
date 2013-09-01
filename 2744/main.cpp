#include <iostream>
#include <cstring>

using namespace std;

int t = 0, n = 0;
char str[100][101];

void myRevstr(char * str) {
    int len = strlen(str);
    char temp[101];

    for (int i = 0; i < len; i ++) {
        temp[i] = *(str + (len - i - 1));
    }
    temp[len] = '\0';

    strcpy(str, temp);
}

int search(const char * str, int len) {
	char subStr[101], revStr[101];
	int subLen = len;

	while (subLen) {
		for (int i = 0; i <= len - subLen; i++) {
			strncpy(subStr, str + i, subLen);
			strncpy(revStr, str + i, subLen);
			subStr[subLen] = revStr[subLen] = '\0';
			myRevstr(revStr);

			bool found = true;
			for (int k = 0; k < n; k++) {
				if (strstr(str + k * 101, subStr) == NULL 
					&& strstr(str + k * 101, revStr) == NULL) {
					found = false;
					break;
				}
			}

			if (found) return subLen;
		}
		subLen--;

	}

    return 0;
}

int main() {
	cin >> t;

	while (t--) {
		int min = 0;
		cin >> n;

		cin.get();

		for (int i = 0; i < n; i++) {
			cin.getline(str[i], 100);

			if (strlen(str[i]) < strlen(str[min])) min = i;
		}

        int subLen = search(str[min], strlen(str[min]));

		cout << subLen << endl;
	}

	return 0;
}
