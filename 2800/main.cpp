#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int character[26];

	for (int i = 0; i < 26; i++) {
        character[i] = 0;
	}

	for (int i = 0; i < 4; i++) {
		char str[81] = {"\0"};

		cin.getline(str,80);
        int len = strlen(str);
        for (int j=0;j<len;j++)
        {
            if (str[j]>='A'&&str[j]<='Z')
            {
                character[str[j]-'A']++;
            }
        }

	}

	int max = 0;
	for (int i = 0; i < 26; i++) {
		if (character[i] >= max) {
			max = character[i];
		}
	}

	for (int i = max; i > 0 ; i--) {
		for (int j = 0; j < 26; j++) {
			if (character[j] >= i) {
				cout << "* ";
			} else cout << "  ";
		}

		cout << endl;
	}

	for (int i = 0; i < 26; i++) {
		cout << (char)('A' + i) << " ";
	}


	return 0;
}
