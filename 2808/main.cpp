#include <iostream>

using namespace std;

int main()
{
	const int LEN = 10001;
    int l, m, count = 0;

    bool a[LEN];

    cin >> l >> m;

    for (int i = 0; i < LEN; i++)
    {
    	a[i] = true;
    }

    for (int i = 0; i < m; i++)
    {
    	int begin, end;

    	cin >> begin >> end;

    	for (int j = begin; j <= end; j++)
    	{
    		if (!a[j]) continue;
    		a[j] = false;
    	}
    }

    for (int k = 0; k <= l; k++)
	{
		if (a[k]) count++;
	}

	cout << count << endl;
}
