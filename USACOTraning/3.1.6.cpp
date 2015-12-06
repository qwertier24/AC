/*
ID: mayukun3
PROG: contact
LANG: C++
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
int p=0;
using namespace std;
struct block
{
	int cnt,num,length,ord;
	bool operator< (const block& rhs) const
	{
		if(cnt>rhs.cnt)return true;
		else if(cnt<rhs.cnt)return false;
		else
		{
			if(length<rhs.length)
				return true;
			else if(length==rhs.length&& num<rhs.num)
				return true;
			else
				 return false;
		}
	}
	void operator++(int)
	{
		cnt++;
	}
	void print()
	{
		for(int i=length-1; i>=0; i--)
			printf("%d",(num>>i)&1);
	}
	bool operator==(const block& rhs)
	{
		return cnt==rhs.cnt;
	}
}d[13][1<<12];
vector<block> ans;
int len=0,a,b,n,t=0;
char s[2000001];
int main()
{
	freopen("contact.in","r",stdin);freopen("contact.out","w",stdout);
	scanf("%d%d%d",&a,&b,&n);
	while(scanf("%s",s+len)!=EOF)
	{
		len=strlen(s);
	}
	//printf("%s",s);
	for(int i=0; i<a-1&&i<len; i++)
		t=(t<<1)|(s[i]-'0');
	for(int i=a-1; i<b&&i<len; i++)
	{
		t=(t<<1)|(s[i]-'0');
		for(int j=a; j<=i+1; j++)
		{
			d[j][t%(1<<j)]++;
			d[j][t%(1<<j)].num=t%(1<<j);
			d[j][t%(1<<j)].length=j;
		}
	}
	for(int i=b; i<len; i++)
	{
		t=(t<<1)|(s[i]-'0');
		t%=(1<<14);
		for(int j=a; j<=b; j++)
		{
			d[j][t%(1<<j)]++;
			d[j][t%(1<<j)].num=t%(1<<j);
			d[j][t%(1<<j)].length=j;
		}
	}
	for(int i=a; i<=b; i++)
		for(int j=0; j<(1<<12); j++)
			ans.push_back(d[i][j]);
	sort(ans.begin(),ans.end());
	ans[0].ord=1;
	for(int i=1; i<ans.size(); i++)
	{
		if(ans[i]==ans[i-1])
			ans[i].ord=ans[i-1].ord+1;
		else
			ans[i].ord=1;
	}
	for(int i=0; i<n; i++)
	{
		if(p>=ans.size()||ans[p].cnt==0)
			break;
		printf("%d\n",ans[p].cnt);
		while(ans[p]==ans[p+1])
		{
			if(p>=ans.size()||ans[p].cnt==0)
				break;
			if(ans[p].ord%6)
			{
				ans[p].print();
				printf(" ");
			}
			else
			{
				ans[p].print();
				printf("\n");
			}
			p++;
		}
		ans[p].print();
		p++;
		printf("\n");
	}
	return 0;
}