#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

char * standarlize(char * str) {
	char * stdStr = new char[10];
	int len = strlen(str), l = 0;

	for (int i = 0; i < len; i++) {
		//去'-'
		if (*(str + i) == '-') continue;
		if (l == 3) {
			*(stdStr + l) = '-';
			l++;
		}

		//字母映射
		if (str[i] >= 'A' && str[i] <'Q') {
			stdStr[l] = (str[i] - 'A') / 3 + '2';
			l++;
			continue;
		}
		else if (str[i] > 'Q' && str[i] <= 'Y') {
			stdStr[l] = (str[i] - 'A' - 1) / 3 + '2';
			l++;
			continue;
		}

		*(stdStr + l) = str[i];
		l++;
	}

	*(stdStr + l) = '\0';

	return stdStr;
}

int compare(const void *elem1,const void *elem2) {
	return (strcmp((char*)elem1, (char*)elem2));
}

int main() {
	long n = 0, number = 0;
    cin >> n;
   	char tel[100000][9];

    memset(tel, 0, sizeof tel);

    cin.get();

	while (n--) {
		char str[20] = {'\0'};
		cin.getline(str, 20);

		strcpy(tel[number++],standarlize(str));
	}

    qsort(tel, number, 9, compare);

	bool noDuplicate = true;
	for (int i = 0; i < number; i++) {
		int count = 1, k = i + 1;
		while (strcmp(tel[i], tel[k]) == 0) {
			count++;
			k++;
			noDuplicate = false;
		}

		if (count > 1)
			cout << tel[i] << " " << count << endl;

		i = k - 1;
	}

	if (noDuplicate) cout << "No duplicates." << endl;

	return 0;
}
