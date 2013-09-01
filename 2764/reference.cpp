#include<cstdio>
int _main()
{
	char s[1002];
	int n;
	while(scanf("%s",s)==1&&s[0]!='0')
	{
		n=0;
		for(int i=0;s[i]!=0;i++)
			n+=s[i]-'0';
		printf("%d\n",(n-1)%9+1);
	}
	return 0;
}