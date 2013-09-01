#include <iostream>
#include <stdio.h>

using namespace std;

struct Monkey
{
	int id;
	struct Monkey * next;
	struct Monkey * previous;
};

Monkey * linkDelete(Monkey * monkey, Monkey * head)
{
	Monkey * nextMonkey = monkey->next;
	if (nextMonkey == head)
		nextMonkey = nextMonkey->next;

	Monkey * deletePrevious = monkey->previous;
	Monkey * deleteNext = monkey->next;

	deletePrevious->next = monkey->next;
	deleteNext->previous = monkey->previous;

	monkey->next = NULL;
	monkey->previous = NULL;

	return nextMonkey;
}


int main()
{
	int n, m, count;
	Monkey * head = new Monkey, * monkey[301];
	head->id = 0;
	
	while (cin >> n >> m != NULL && n && m)
	{
		count = 0;

		for (int i = 0; i < n; i++)
		{
			monkey[i] = new Monkey;

			if (i > 0)
			{
				monkey[i]->previous = monkey[i-1];
				monkey[i]->next = head;

				monkey[i-1]->next = monkey[i];
				head->previous = monkey[i];
			} else 
			{
				head->next = monkey[i];
				head->previous = monkey[i];
				monkey[i]->previous= head;
				monkey[i]->next = head;
			}
			
			monkey[i]->id = i + 1;
		}

		Monkey * deleteMonkey = head;

		while(n != 1)
		{
			while(count < m)
			{
				deleteMonkey = deleteMonkey->next;

				if (deleteMonkey != head)
					count++;
			}

			if (deleteMonkey == head)
				deleteMonkey = deleteMonkey->next;

			deleteMonkey = linkDelete(deleteMonkey, head);
			count = 1;

			n--;
		}

		cout << head->next->id << endl;
	}

	system("pause");
	
	return 0;
}