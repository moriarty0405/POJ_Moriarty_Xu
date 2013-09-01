#include <iostream>
#include <cstring>

using namespace std;

char * standardlize(char * s) {
	int len = 0;
	char temp[101];


	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ') continue;
		if (s[i] >= 'a' && s[i] <= 'z') {
			temp[len++] = s[i] - 'a' + 'A';
			continue;
		}
		temp[len] = s[i];
		len++;
	}
	temp[len] = '\0';

	strcpy(s, temp);

	return s;
}


int main() {
	int t = 0;
	cin >> t;
	cin.get();

	while (t--) {
		char str1[101], str2[101];
		cin.getline(str1, 100);
		cin.getline(str2, 100);
		
		cin.get();

		if (strcmp(standardlize(str1), standardlize(str2)) == 0)
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}
