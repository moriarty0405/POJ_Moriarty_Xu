#include <iostream>
#include <cstring>
#define MAX 1005

using namespace std;

int main()
{
	char num[MAX] = {'\0'};
	cin >> num;
	while (num[0] != '0')
	{
		int sum = 0;

		for (int i = 0; i < strlen(num); i++)
			sum += num[i] - '0';
		while (sum > 9)
		{
			int total = 0;
			while (sum)
			{
				total += sum % 10;
				sum = sum / 10;
			} 
			sum = total;
		}
		cout << sum << endl;

		cin >> num;
	}
	system("pause");
	return 0;
}