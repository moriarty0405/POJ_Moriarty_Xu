#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char str[1001][21];
	int mark[1001];
	
	memset(str, '\0', sizeof(char) * 21 * 1001);
	memset(mark, 0, sizeof(int) * 1001);

	int count = 0;

	while (cin.get(str[count], 1001).get() != NULL && str[count][0])
		count++;

	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1; j < count; j++) {
			for (int k = 0; str[i][k] != '\0' && str[j][k] != '\0'; k++) {
				if (str[i][k] != str[j][k]) break;
				if (k >= mark[i]) mark[i]++;
				if (k >= mark[j]) mark[j]++;
			}
		}
	}

	for (int i = 0; i < count; i++)
	{
		cout << str[i] << " ";
		for (int j = 0; j <= mark[i]; j++)
		{
			char c = str[i][j];
			if (str[i][j] != '\0')
				cout << str[i][j];
		}

		cout << endl;
	}

	system("pause");

	return 0;
}