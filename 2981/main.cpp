#include <iostream>
#include <cstring>
#define MAX 210
using namespace std;

const char * add(const char * strNum1, const char * strNum2)
{
	char * result = new char[MAX];
	int num1[MAX], num2[MAX], len1, len2, larger = 0, count, k = 0;
	memset(num1, 0 , MAX);
	memset(num2, 0 , MAX);

	len1 = strlen(strNum1); 
	len2 = strlen(strNum2);
	larger = (len1 > len2) ? len1 : len2;

	for (int i = 0; i < len1; i++)
		num1[i] = strNum1[len1-i-1] - '0';
	for (int i = 0; i < len2; i++)
		num2[i] = strNum2[len2-i-1] - '0';

	for (count = 0; count < larger; count++)
	{
		num1[count] += num2[count];
		if (num1[count] >= 10)
		{
			num1[count+1] += num1[count] / 10;
			num1[count] %= 10;
		}
	}
	if (num1[count] != 0)
		larger++;
	
	bool output = false;
	for (int i = larger - 1; i >= 0; i--)
		if (output)
			result[k++] = num1[i] + '0';
		else if (num1[i])
		{
			result[k++] = num1[i] + '0';
			output = true;
		}

	if (!output)//½á¹ûÎª0
	{
		result[0] = '0';
		result[1] = '\0';
	}
	else 
		result[k] = '\0';
	
	return result;
}

int main()
{
	int num1[MAX], len1 = 0, larger = 0, count;
	int num2[MAX], len2 = 0;
	char strNum1[MAX], strNum2[MAX];

	memset(num1, 0 , MAX);
	memset(num2, 0 , MAX);

	cin.getline(strNum1, MAX);
	cin.getline(strNum2, MAX);
	cout << add(strNum1, strNum2) << endl;

	system("pause");
	return 0;
}