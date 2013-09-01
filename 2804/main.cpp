#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct InputDictionary
{
	char engWord[11];
	char word[11];
};

InputDictionary dict[100010];

int Cmp(const void * a, const void * b) {
	return strcmp(((InputDictionary *)a)->word,((InputDictionary *)b)->word);
}

int main() {
	char s[30] = {'\0'};
	int count = 0;

	while (cin.getline(s, 30) && s[0] != '\n') {
		sscanf(s, "%s%s", dict[count].engWord, dict[count].word);
		count++;
	}

	qsort(dict, count, sizeof(InputDictionary), Cmp);


	return 0;
}
