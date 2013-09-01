#include<iostream>
#include<cstring>
#include<memory>

using namespace std;
int main()
{
	int t,n,i,j,j1,k,m,num,len[100]={},min,mini,flag=1,re=0,from;
	char a[100][101]={};
	cin>>t;
	
	for(i=0;i<t;i++)
	{
		re=0;
		cin>>n;
		
		for(j=0;j<n;j++)
		{
			cin>>a[j];
			len[j]=strlen(a[j]);
		}
		
		min=len[0];
		mini=0;
		
		for(k=1;k<n;k++)
		{
			if(min>len[k])
			{
				min=len[k];
				mini=k;
			}
		}
		
		for(num=min;num>=0;num--)
		{
			re=0;
			for(from=0;from<=min-num;from++)
			{
				flag=1;

				char b[101]={},rev[101]={};
				for(j=from,j1=0;j<from+num;j++,j1++)
					b[j1]=a[mini][j];
				b[j1]='\0';
				
				for(m=0;m<num;m++)
					rev[m]=b[num-m-1];
				rev[m]='\0';
				
				for(k=0;k<n;k++)
				{
					if(k==mini)	continue;
					
					if(strstr(a[k],b)!=0||strstr(a[k],rev)!=0)
					{
						continue;
					}
					else
					{
						flag=0;break;
					}

				}
				if(flag==1)
				{re=1;break;}
			}
			if(re==1)break;
		}
		cout<<num<<endl;
	}
	return 0;
}