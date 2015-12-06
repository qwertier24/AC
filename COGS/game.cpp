#include <stdio.h>
#include <algorithm>
using namespace std;
struct HANDS
{
	int l,r;
	bool operator<(const HANDS& rhs) const
	{
		return l*r<rhs.l*rhs.r;
	}
}king,sec[200001];
struct BIGN
{
	int len,num[5000];
	BIGN(int t)
	{
		num[1]=t;
		len=1;
	}
	void operator*=(int t)
	{
		for(int i=1; i<=len; i++)
			num[i]*=t;
		int c=0;
		for(int i=1; i<=len||c; i++)
		{
			if(i>len)
				len++;
			num[i]+=c;
			c=num[i]/10;
			num[i]%=10;
		}
	}
	BIGN operator/=(int t)
	{
		int c=0;
		for(int i=len; i>=1; i--)
		{
			num[i]+=c*10;
			c=num[i]%t;
			num[i]=num[i]/t;
		}
		while(!num[len]&&len>1)
			len--;
	}
	bool operator<(const BIGN& t)
	{
		if(len==t.len)
		{
			for(int i=len; i>=1; i--)
			{
				if(t.num[i]>num[i])
					return true;
				else if(t.num[i]<num[i])
					return false;
			}
		}
		return len<t.len;
	}
	void print()
	{
		for(int i=len; i>=1; i--)
			printf("%d",num[i]);
		printf("\n");
	}
};
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%d %d",&king.l,&king.r);
	for(int i=1; i<=n; i++)
		scanf("%d %d",&sec[i].l,&sec[i].r);
	sort(sec+1,sec+n+1);
	BIGN t(1),ans(0);
	t*=king.l;
	for(int i=1; i<=n; i++)
	{
		BIGN t2=t;
		t2/=sec[i].r;
		if(ans<t2)
			ans=t2;
		//t2.print();
		t*=sec[i].l;
	}
	ans.print();
	return 0;
}
