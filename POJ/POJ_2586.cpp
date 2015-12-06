#include <stdio.h>
#include <algorithm>
//#define get(i) (i==1)?s:-d;
using namespace std;
int s,d;
int get(int i)
{
	return (i==1)?s:-d;
}
int sum(int p)
{
	int ret=0;
	for(int i=0; i<12; i++)
		ret+=get((p>>i)&1);
	return ret;
}
bool check(int p)
{
	int t=0;
	for(int i=0; i<5; i++)
		t+=get((p>>i)&1);
	for(int i=4; i<12; i++)
	{
		if(t>=0)
			return false;
		//printf("%d %d %d\n",t,get(((p>>(i+1))&1)),get(((p>>(i-4))&1)));
		t+=get(((p>>(i+1))&1))-get(((p>>(i-4))&1));
	}
	return true;
}
int main()
{
	while(scanf("%d%d",&s,&d)!=EOF)
	{
		int ans=-(1<<30);
		check(0);
		
		for(int i=0; i<(1<<12); i++)
			if(check(i))
				ans=max(ans,sum(i));
				
		if(ans<0)
			printf("Deficit\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
