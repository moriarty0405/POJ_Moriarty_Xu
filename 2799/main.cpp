#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char str[10001][51];
	int n = 0, max = 0, mark[10001];
	cin >> n;

	cin.get();

	memset(str, '\0', sizeof(char) * 10001 * 51);
	memset(mark, 0, sizeof(int) * 10001);

	for (int i = 0; i < n; i++)
	{
		int j = 0;

		cin.getline(str[i], 51);
		
		while (str[i][j] != '.')
			j++;
		mark[i] = j;

		if (j >= max)
			max = j;
	}

	for (int i = 0; i < n; i++)
	{
		if (mark[i] == max) 
			cout << str[i] << endl;
		else 
		{
			for (int j = 0; j < max - mark[i]; j++)
			{
				cout << " ";
			}

			cout << str[i] << endl;
		}
	}

	system("pause");
	
	return 0;
}