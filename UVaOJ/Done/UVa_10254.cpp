#include <stdio.h>
#include <algorithm>
#include <string.h>
#define MAXN 10000
using namespace std;
struct BIGN
{
	int len,num[100];
	BIGN()
	{
		memset(num,0,sizeof(num));
	}
	int operator*= (int t)
	{
		for(int i=1; i<=len; i++)
			num[i]*=t;
		int c=0;
		for(int i=1; i<=len||c; i++)
		{
			if(i>len)len++;
			num[i]+=c;
			c=num[i]/10;
			num[i]%=10;
		}
	}
	void operator=(const BIGN& rhs)
	{
		len=rhs.len;
		for(int i=1; i<=len; i++)
			num[i]=rhs.num[i];
	}
	BIGN operator+(const BIGN& rhs)
	{
		BIGN t;
		t.len=max(rhs.len,len);
		for(int i=1; i<=t.len; i++)
			t.num[i]=rhs.num[i]+num[i];
		int c=0;
		for(int i=1; i<=t.len||c; i++)
		{
			if(i>t.len)t.len++;
			t.num[i]+=c;
			c=t.num[i]/10;
			t.num[i]%=10;
		}
		return t;
	}
	void print()
	{
		for(int i=len; i>=1; i--)
			printf("%d",num[i]);
		printf("\n");
	}
}d[MAXN+1],t;
int main()
{
	int n;
	memset(d,0,sizeof(d));
	d[0].len=1,d[0].num[1]=0;
	t.len=1,t.num[1]=1;
	for(int i=1; i<=143; i++)
	{
		for(int j=1; j<=i&&i*(i-1)/2+j<=MAXN; j++)
		{
			d[i*(i-1)/2+j]=d[i*(i-1)/2+j-1]+t;
		}
		t*=2;
	}
	while(scanf("%d",&n)!=EOF)
	{
		d[n].print();
	}
	return 0;
}
