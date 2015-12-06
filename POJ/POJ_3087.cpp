#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
using namespace std;
map<string,int> mp;
int main()
{
	//freopen("prob.out","w",stdout);
	int T,kase=1,n;
	scanf("%d",&T);
	while(T--)
	{
		string s1,s2,endpos,pos;
		mp.clear();
		scanf("%d",&n);
		printf("%d ",kase++);
		cin>>s1>>s2>>endpos;
		bool flag=false;
		int times=0;
		while(true)
		{
			for(int i=0; i<n; i++)
			{
				pos.push_back(s2[i]);
				pos.push_back(s1[i]);
			}
			times++;
			//cout<<s1<<" "<<s2<<" "<<pos<<endl;
			if(pos==endpos)
			{
				printf("%d\n",times);
				flag=true;
			}
			else if(mp.count(pos))
			{
				printf("-1\n");
				flag=true;
			}
			else
			{
				mp[pos]=1;
			}
			if(flag)break;
			for(int i=0; i<n; i++)
			{
				s1[i]=pos[i];
				s2[i]=pos[i+n];
				pos.clear();
			}
		}
	}
	return 0;
}
