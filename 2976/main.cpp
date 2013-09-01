#include <iostream>
#include <cstring>

using namespace std;

void find(char * str, char * subStr) {
	int len = strlen(str);
	int subLen = strlen(subStr);
	int i = 0, j = 0;

	while (i < subLen && j < len) {
        if (subStr[i] == str[j])
            i++;
        j++;
	}
	if (i == subLen)
        cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
	char str[1000001], subStr[1000001];

    while (cin >> subStr >> str) {
        find(str, subStr);
    }

	return 0;
}
