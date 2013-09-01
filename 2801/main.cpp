#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int m, n, p;
	int characters[26];
	cin >> m >> n >> p;

	for (int i = 0; i < 26; i++)
	{
		characters[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		char c;

		for (int j = 0; j < m; j++)
        {
        	cin >> c;
        	characters[c - 'A']++;
        }

	}

	for (int i = 0; i < p; i++)
	{
		char word[100];
		cin >> word;

		for (int j = 0; j < strlen(word); j++)
		{
			characters[word[j] - 'A']--;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (characters[i] > 0)
		{
			for (int j = 0; j < characters[i]; j++)
			{
				cout << (char)(i + 'A');
			}
		}
	}

	cout << endl;

	return 0;
}
