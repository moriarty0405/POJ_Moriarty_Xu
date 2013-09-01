#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int a[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2)
		{
			cout << 0 << " " << 0 << endl;
		}
		else if (a[i] % 4 != 0)
		{
			cout << a[i] / 4 + 1 << " " << a[i] / 2 << endl;
		}
		else
		{
			cout << a[i] / 4 << " " << a[i] /2 << endl;
		}
	}

	return 0;
}
