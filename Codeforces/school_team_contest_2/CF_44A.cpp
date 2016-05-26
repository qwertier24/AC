#include <stdio.h>
#include <string>
#include <map>
#include <iostream>
using namespace std;
struct LEAVE
{
	string s1,s2;
	bool operator<(const LEAVE& rhs)const
	{
		return s1<rhs.s1||(s1==rhs.s1&&s2<rhs.s2);
	}
};
map<LEAVE,int> mp;
int main()
{
	int n;
	scanf("%d",&n);
	string s1,s2;
	for(int i=1; i<=n; i++)
	{
		cin>>s1>>s2;
		if(!mp.count((LEAVE){s1,s2}))
			mp[(LEAVE){s1,s2}]=1;
	}
	printf("%d",mp.size());
	return 0;
}
