#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#include <iostream>
using namespace std;
int a[10],v;
int main()
{
	string ans;
	scanf("%d",&v);
	for(int i=1; i<=9; i++)
		scanf("%d",&a[i]);
	int min_cost=1<<30,pos;
	for(int i=1; i<=9; i++)
		if(a[i]<=min_cost)
		{
			min_cost=a[i];
			pos=i;
		}
	while(v>=min_cost)
	{
		ans.push_back('0'+pos);
		v-=min_cost;
	}
	pos=0;
	if(min_cost!=1<<30)
	while(true)
	{
		if(pos>=ans.size())
			break;
		bool found=false;
		for(int i=9; i>=1; i--)
			if(a[i]-min_cost<=v)
			{
				found=true;
				v-=a[i]-min_cost;
				ans[pos]=i+'0';
				break;
			}
		pos++;
		if(!found)
			break;
	}
	if(ans.size())
	cout<<ans;
	else
		cout<<-1;
	return 0;
}
