#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#define MAXLEN 2000
using namespace std;
struct BIGN
{
	int len,num[MAXLEN];
	BIGN()
	{
		memset(num,0,sizeof(num));
	}
	void operator*=(BIGN t)
	{
		int numt[MAXLEN];
		memset(numt,0,sizeof(numt));
		for(int i=1; i<=len; i++)
			for(int j=1; j<=t.len; j++)
				numt[i+j-1]+=num[i]*t.num[j];
		len=t.len+len-1;
		int c=0;
		for(int i=1; i<=len||c; i++)
		{
			if(i>len)len++;
			numt[i]+=c;
			c=numt[i]/10;
			numt[i]%=10;
			num[i]=numt[i];
		}
	}
	void init_from_std()
	{
		char s[200];
		scanf("%s",s);
		len=strlen(s);
		for(int i=1; i<=len; i++)
			num[i]=s[len-i]-'0';
	}
	void print()
	{
		for(int i=len; i>=1; i--)
			printf("%d",num[i]);
		printf("\n");
	}
}p;
BIGN power(int a,int b)
{
	BIGN t,ret;
	t.len=1,t.num[1]=a;
	int c=t.num[1]/10;
	t.num[1]%=10;
	while(c)
	{
		t.num[++t.len]=c%10;
		c/=10;
	}
	ret.len=1,ret.num[1]=1;
	for(int i=1; i<=b; i++)
	{
		ret*=t;
	}
	return ret;
}
int cmp(BIGN a,BIGN b)
{
	if(a.len>b.len)return 1;
	else if(a.len<b.len)return -1;
	else
	{
		for(int i=a.len; i>=1; i--)
		{
			if(a.num[i]>b.num[i])
				return 1;
			else if(a.num[i]<b.num[i])
				return -1;
		}
		return 0;
	}
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		p.init_from_std();
		int l=1,r=1e9;
		while(l<r)
		{
			int m=(l+r)/2;
			int result=cmp(power(m,n),p);
			if(result==0)
			{
				l=m;
				break;
			}
			else if(result==-1)
				l=m+1;
			else
				r=m-1;
		}
		printf("%d\n",l);
	}
	return 0;
}
