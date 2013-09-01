#include <iostream>
#include <cstring>
#define MAX 61

using namespace std;

char * multiply(const char * strNum1, const char * strNum2)
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

char * toString(int num)
{
	char * str = new char[MAX];

	if (num >= 10)
	{
		str[1] = num % 10 + '0';
		str[0] = num / 10 + '0';
		str[2] = '\0';
	}
	else 
	{
		str[0] = num + '0';
		str[1] = num + '1';
	}

	return str;
}

int main()
{
	int number = 0;
	char num[MAX] = {'\0'}, checkNum[MAX] = {'\0'}, resultNum[MAX] = {'\0'};
	cin >> num;
	strcpy(checkNum, num);
	strcat(checkNum, num);

	for (int i = 1; i <= strlen(num); i++)
	{
		char * ch = toString(i);
		resultNum = multiply(num, ch);
	}
	


	system("pause");
	return 0;
}