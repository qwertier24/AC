#include <stdio.h>
#include <string.h>
#define MAXN 2000
struct BIGN
{
	int num[MAXN];
	int len;
	void operator+=(BIGN& t)
	{
		len=len>t.len?len:t.len;
		int c=0;
		for(int i=1; i<=len; i++)
		{
			int a=num[i]+c+t.num[i];
			num[i]=a%10;
			c=a/10;
		}
		if(c)
		{
			len++;
			num[len]++;
		}
	}
	void operator++(int b)
	{
		int c=1;
		for(int i=1; c; i++)
		{
			if(i>len)len++;
			int a=num[i]+c;
			num[i]=a%10;
			c=a/10;
		}
	}
}d[MAXN+1];
void Init()
{
	int match[10]={6,2,5,5,4,5,6,3,7,6};
	memset(d,0,sizeof(d));
	for(int i=1; i<10; i++)
	{
		d[i].len=1;
	}
	for(int i=1; i<10; i++)
	{
		d[match[i]]++;
	}
	for(int i=1; i<=MAXN; i++)
		for(int j=0; j<10; j++)
			if(i-match[j]>=0)
				d[i]+=d[i-match[j]];
	d[6]++;
	for(int i=1; i<=MAXN; i++)
		d[i]+=d[i-1];
}
void print(int p)
{
	for(int i=d[p].len; i>=1; i--)
		printf("%d",d[p].num[i]);
	printf("\n");
}
int main()
{
	Init();
	int n;
	while(scanf("%d",&n)!=-1)
		print(n);
	return 0;
}
