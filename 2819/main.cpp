#include <iostream>
#include <cstring>

using namespace std;

void move(char * s, int k, int * a, int len) {
	if (!len) return;

	k = k % len;

	char temp[81];
	strcpy(temp, s);

	for (int i = 0; i < len; i++) {
		if ((i + k) < len)
			temp[a[i + k]] = s[a[i]];
		else temp[a[i + k - len]] = s[a[i]];
	}

	strcpy(s, temp);
}

int main() {
	int k1, k2, k3;

	while (cin >> k1 >> k2 >> k3 && k1 && k2 && k3) {
		char str[81] = {'\0'};
		int substr1[81] = {0};
		int substr2[81] = {0};
		int substr3[81] = {0};

		cin.get();
		cin.getline(str, 81);
		int len = strlen(str), sublen1 = 0, sublen2 = 0, sublen3 = 0;

		for (int i = 0; i < len; i++) {
			if (str[i] >= 'a' && str[i] <= 'i')
				substr1[sublen1++] = i;
			if (str[i] >= 'j' && str[i] <= 'r')
				substr2[sublen2++] = i;
			if ((str[i] >= 's' && str[i] <= 'z') || str[i] == '_')
				substr3[sublen3++] = i;
		}

		move(str, k1, substr1, sublen1);
		move(str, k2, substr2, sublen2);
		move(str, k3, substr3, sublen3);

		cout << str << endl;
	}

	return 0;
}
