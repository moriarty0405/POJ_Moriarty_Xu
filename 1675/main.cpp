#include <iostream>
#include "cstdlib"

using namespace std;

int main()
{
	int t, x, y;
	char begin[3], end[3];

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin.get();
		cin.get(begin, 3).get(); 	//获取begin
		cin.get(end, 3);         	//获取end

		x = abs(end[0] - begin[0]);	//计算横向距离
		y = abs(end[1] - begin[1]);	//计算纵向距离

		//如果距离为0
		if (x == 0 && y == 0) cout << "0 0 0 0" << endl;

		else
        {
            //王的距离 坐标差的较大者
            if (x > y) cout << x << " ";
            else cout << y << " ";

            //后的距离 若形成的是等腰三角形或者在同一直线上则一步，非等腰则两步
            if (x == y || x == 0 || y == 0) cout << "1 ";
            else cout << "2 ";

            //车的距离 若在同一直线则为1，不在同一直线则为2
            if (x == 0 || y == 0) cout << "1 ";
            else cout << "2 ";

            //像的距离
            if (abs(x - y) % 2 != 0) cout << "Inf";
            else if (x == y) cout << "1";
            else cout << "2";

            cout << endl;

        }


	}


	return 0;
}
