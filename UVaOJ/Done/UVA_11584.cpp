#define MAXN 1000
#include <stdio.h>
#include <cstring>
#define INF 100000000
int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	int d[MAXN],T;
	char str[1001];
	bool p[MAXN][MAXN];
	scanf("%d",&T);
	while(T--)
	{
	memset(p,0,sizeof(p));
	scanf("%s",str);
	int len=strlen(str);
	for(int i=0; i<len; i++)
	{
		for(int j=0; j<=min(len-i-1,i);j++)
		{
			if(str[i-j]==str[i+j])
				p[i-j][i+j]=true;
			else
				break;
		}
	}
	for(int i=0; i<len; i++)
	{
		for(int j=0; j<=min(len-i-1,i); j++)
		{
			if(str[i-j]==str[i+j+1])
				p[i-j][i+j+1]=true;
			else
				break;
		}
	}
	/*
	for(int i=0; i<len; i++)
		for(int j=0; j<len; j++)
			if(p[i][j])
				printf("%d %d\n",i,j);
	*/
	d[0]=1;
	for(int i=1; i<len; i++)
	{
		d[i]=d[i-1]+1;
		for(int j=0; j<i; j++)
			if(p[j][i])
				d[i]=min(d[i],d[j-1]+1);
	}
	printf("%d\n",d[len-1]);
	}
	return 0;
}
