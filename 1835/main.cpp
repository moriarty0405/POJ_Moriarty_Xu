#include <iostream>
#include <cstring>

using namespace std;
int x, y, z, p, r, u;

int rev(int p)
{
	switch(p)
	{
		case 0 : return 3;
		case 1 : return 4;
		case 2 : return 5;
		case 3 : return 0;
		case 4 : return 1;
		case 5 : return 2;
		default : return -1;
	}
}

int main()
{
	int m = 0;
	cin >> m;

	while (m--)
	{
		int temp = 0;
		x = y = z = p = 0, r = 1, u = 2;
		int times = 0, steps = 0;
		char direction[8] = {'\0'};
		cin >> times;

		while (times--)
		{
			cin >> direction >> steps;

			switch(direction[0])
			{
				case 'f' : break;
				case 'b' : p = rev(p); r = rev(r); break;
				case 'l' : temp = p; p = rev(r); r = temp; break;
				case 'r' : temp = p; p = r; r = rev(temp); break;
				case 'u' : temp = p; p = u; u = rev(temp); break;
				case 'd' : temp = p; p = rev(u); u = temp; break;
				default : break;
			}

			switch(p)
			{
				case 0 : x += steps; break;
				case 1 : y += steps; break;
				case 2 : z += steps; break;
				case 3 : x -= steps; break;
				case 4 : y -= steps; break;
				case 5 : z -= steps; break;
				default : break;
			} 
		}
		cout << x << " " << y << " " << z << " " << p << endl; 
	}
	system("pause");
	return 0;
}