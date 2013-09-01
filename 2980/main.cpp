#include <iostream>
#include <cstring>
#define MAX 210

using namespace std;

const char * multiply(const char * strNum1, const char * strNum2)
{
	int len1, len2, num1[MAX], num2[MAX], result[MAX], k = 0;
	char * r = new char[MAX];
	len1 = strlen(strNum1);
	len2 = strlen(strNum2);
	memset(num1, 0, MAX);
	memset(num2, 0, MAX);
	memset(result, 0, MAX);

	for (int i = 0; i < len1; i++)
		num1[i] = strNum1[len1-i-1] - '0';
	for (int i = 0; i < len2; i++)
		num2[i] = strNum2[len2-i-1] - '0';

	for (int i = 0; i < len2; i++)
		for (int j = 0; j < len1; j++)
			result[i+j] += num1[j] * num2[i];

	for (int i = 0; i < len1 + len2; i++)
	{
		if (result[i] >= 10)
		{
			result[i+1] += result[i] / 10;
			result[i] %= 10;
		}
	}
		
	bool output = false;
	for (int i = len1 + len2 - 1; i >= 0; i--)
	{
		if (output)
			r[k++] = result[i] + '0';
		else if (result[i])
		{
			r[k++] = result[i] + '0';
			output = true;
		}
	}
	if (!output)
	{
		r[0] = '0';
		r[1] = '\0';
	}
	else 
		r[k] = '\0';
		
	return r;
}

int main()
{
	char strNum1[MAX], strNum2[MAX];
	cin.getline(strNum1, MAX);
	cin.getline(strNum2, MAX);
	
	cout << multiply(strNum1, strNum2) << endl;

	system("pause");
	return 0;
}