#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int d[1<<12][1<<12],m,n,num[200];
int dp(int ques,int ans)
{
	if(d[ques][ans]!=-1)
		return d[ques][ans];
	d[ques][ans];
	int cnt=0;
	for(int i=1; i<=n; i++)
		if((num[i]&ques)==ans)
			cnt++;
	if(cnt<=1)
		d[ques][ans]=0;
	else
	{
		d[ques][ans]=1<<30;
		for(int i=0; i<m; i++)
			if(!((ques>>i)&1))
			{
				d[ques][ans]=min(d[ques][ans],max(dp(ques|(1<<i),ans|(1<<i)),dp(ques|(1<<i),ans))+1);
				//printf("%d %d %d\n",ques,ans,ret);
			}
	}
	//printf("%d %d %d\n",ques,ans,d[ques][ans]);
	return d[ques][ans];
}
char s[20];
int main()
{
	while(scanf("%d%d",&m,&n)&&m)
	{
		memset(d,-1,sizeof(d));
		memset(num,0,sizeof(num));
		for(int i=1; i<=n; i++)
		{
			scanf("%s",s);
			for(int j=0; j<m; j++)
				num[i]=(num[i]<<1)|(s[j]-'0');
		}
		printf("%d\n",dp(0,0));
	}
	return 0;
}
/*
4 16
0000
0001
0010
0011
0100
0101
0110
0111
1000
1001
1010
1011
1100
1101
1110
1111
*/