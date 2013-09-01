#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char str[201] = {'\0'};
	
	while (cin.getline(str, 200)) {
		if ((strcmp(str, "START") == 0) 
			|| (strcmp(str, "END") == 0))
			continue;
		else if ((strcmp(str, "ENDOFINPUT") == 0)) break;
		
		int len = strlen(str);
	
		for (int i = 0; i < len; i++) {
			if (str[i] >= 'A' && str[i] <= 'Z') {
				if ((str[i] - 'A') >= 5) {
					str[i] = (char)(str[i] - 5);
				} else {
					str[i] = (char)(str[i] + 21);
				}
			}
		}
		
		cout << str << endl;
	}
	
	return 0;
}
