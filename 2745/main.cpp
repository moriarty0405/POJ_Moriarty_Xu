#include <iostream>
#include <cstring>

using namespace std;

int * convert(const char * str)
{
	int len = strlen(str);
	int * a = new int[len];

	for (int i = 0; i < len; i++)
	{
		*(a + i) = str[i] - '0';
	}

	return a;
}

void printH(int num, int size, int part, bool last)
{
	if ((num != 0 && num != 1 && num != 4 && num != 7)
		|| (num == 4 && part == 2) || (num == 0 && part != 2)
		|| (num == 7 && part == 1))
	{
		cout << " ";
		for (int i = 0; i < size; i++)
		{
			cout << "-";
		}
		cout << " ";
	}
	else if ((num == 1) || (num == 4 && part != 2) 
		|| (num == 0 && part == 2) || (num == 7 && part != 1))
	{
		for (int i = 0; i < size + 2; i++)
		{
			cout << " ";
		}
	}

	if (!last)
		cout << " ";
}

void printV(int num, int size, int part, bool last)
{
	if (num != 1 && num != 2 && num != 3 && num != 7 && part == 1)
		cout << "|";
	else if (part == 1)
		cout << " ";
	if ((num == 2 || num == 6 || num == 8 || num == 0) && part == 3)
		cout << "|";
	else if (part == 3)
		cout << " ";

	for (int i = 0; i < size; i++)
	{
		cout << " ";
	}

	if (num != 5 && num != 6 && part == 1)
		cout << "|";
	else if (part == 1)
		cout << " ";
	if (num != 2 && part == 3)
		cout << "|";
	else if (part == 3)
		cout << " ";

	if (!last)
		cout << " ";
}

int main()
{
	int s = 0, len = 0, * num;
	char n[20];

	memset(n, '\0', 9);

	while (cin >> s >> n && s && n[0] != '0')
	{
		len = strlen(n);
		num = convert(n);

		for (int j = 0; j < len; j++)
			printH(*(num + j), s, 1, (len - 1) == j);
		cout << endl;

		for (int i = 0; i < s; i++)
		{
			for (int j = 0; j < len; j++)
				printV(*(num + j), s, 1, (len - 1) == j);
			cout << endl;
		}
		
		for (int j = 0; j < len; j++)
			printH(*(num + j), s, 2, (len - 1) == j);
		cout << endl;

		for (int i = 0; i < s; i++)
		{
			for (int j = 0; j < len; j++)
				printV(*(num + j), s, 3, (len - 1) == j);
			cout << endl;
		}
		
		for (int j = 0; j < len; j++)
			printH(*(num + j), s, 3, (len - 1) == j);
		cout << endl;

		for (int j = 0; j < len; j++)
		{
			for (int k = 0; k < s + 2; k++)
			{
				cout << " ";
			}
			if (j < len - 1)
				cout << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}