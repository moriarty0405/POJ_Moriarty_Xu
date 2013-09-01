#include <iostream>
#include <stdlib.h>
#include <algorithm>

#define LEN_MAX (50 + 10)

using namespace std;

struct Peanut
{
	int x;//row
	int y;//column
	int number;
};

Peanut peanut[LEN_MAX * LEN_MAX];
int totleTime = 0;

bool compare(Peanut x, Peanut y)
{
	return x.number > y.number;
}

bool canGet(int now, int leftTime)
{
	int time = 0 ,actualTime = 0;

	if (now == -1)//Ğ¡Â·ÉÏ
	{
		actualTime = peanut[0].x + 1;
		time = 2 * peanut[0].x + 1;
	}
	else
	{
		time = abs(peanut[now].x - peanut[now+1].x) + 
			abs(peanut[now].y - peanut[now+1].y) + 1;
		actualTime = time;
		time += peanut[now+1].x;
	}

	if (leftTime >= time)
	{
		totleTime -= actualTime;
		return true;
	}
	else return false;
}

int main()
{
	int m, n, count = 0, peanutsNum = 0;

	cin >> m >> n >> totleTime;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int num = 0;
			cin >> num;

			if (num > 0)
			{
				peanut[count].number = num;
				peanut[count].x = i;
				peanut[count++].y = j;
			}
		}
	}

	sort(peanut, peanut + count, compare);
	
	for (int i = 0; i < count; i++)
	{
		if (canGet(i - 1, totleTime))
			peanutsNum += peanut[i].number;
		else break;
	}

	cout << peanutsNum << endl;

	system("pause");

	return 0;
}