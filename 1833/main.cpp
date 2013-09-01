#include <iostream>
#include <algorithm>
#define MAX 1024
using namespace std;

int main()
{
	int m = 0;
	cin >> m;

	while (m--)
	{
		int n = 0, k = 0, a[MAX];
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		for (int i = 0; i < k; i++)
			next_permutation(a, a + n);

		for (int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}