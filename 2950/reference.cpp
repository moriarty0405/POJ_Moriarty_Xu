#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define LEN_MAX (50 + 10)

using std:: sort;

struct PEANUT
{
	int nRow;
	int nColumn;
	int nNum;
};

PEANUT peanuts[LEN_MAX * LEN_MAX];

bool CmpPeanut(PEANUT one, PEANUT two)
{
	return one.nNum >= two.nNum;
}

bool CanGetPeanut(PEANUT& p, int row, int column, int time)
{
	return time >= (1 + p.nRow + abs(row - p.nRow) + abs(column - p.nColumn));
}

int _main()
{
	int nT;
	int nN, nM, nK;
	int nNum;

	scanf("%d", &nT);
	while (nT--)
	{
		scanf("%d%d%d", &nM, &nN, &nK);
		int nCount = 0;
		for (int i = 0; i < nM; ++i)
		{
			for (int j = 0; j < nN; ++j)
			{
				scanf("%d", &nNum);
			if (nNum)
			{
				peanuts[nCount].nRow = i + 1;
				peanuts[nCount].nColumn = j + 1;
				peanuts[nCount].nNum = nNum;
				++nCount;
			}
		}
	}
	sort(peanuts, peanuts + nCount, CmpPeanut);
	int nSum = 0;
	int row = 0, column = 0;

	if (nK >= (1 + 2 * peanuts[0].nRow))
	{
		nSum = peanuts[0].nNum;
		nK -= (peanuts[0].nRow + 1);
		row = peanuts[0].nRow;
		column = peanuts[0].nColumn;
		for (int i = 1; i < nCount; ++i)
		{
			if (CanGetPeanut(peanuts[i], row, column, nK))
			{
				nSum += peanuts[i].nNum;
				nK -= (1 + abs(row - peanuts[i].nRow) + abs(column - peanuts[i].nColumn));
				row = peanuts[i].nRow;
				column = peanuts[i].nColumn;
			}
			else
			{
				break;
			}
		}
	}

	printf("%d\n", nSum);
	}

	return 0;
}