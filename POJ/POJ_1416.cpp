#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#define INF 1<<30
using namespace std;
int org,tgt,pow10[7]={1,10,1E2,1E3,1E4,1E5,1E6},n;
int Minus(int S)
{
	//printf("S:%d\n",S);
	int all_sum=0,t_mod=1E6,sum_t;
	for(int i=0; i<=n-2; i++)
	{
		if((S>>i)&1)
		{
			sum_t=(org%t_mod)/(pow10[n-i-1]);
			all_sum+=sum_t;
			t_mod=pow10[n-i-1];
		}
			//printf("     sum_t:%d         all_sum:%d\n",sum_t,all_sum);
	}
	sum_t=org%t_mod;
	all_sum+=sum_t;
	if(tgt>=all_sum)
		return tgt-all_sum;
	else
		return INF;
}
int main()
{
	while(scanf("%d%d",&tgt,&org)&&(tgt||org))
	{
		int ans_minus=1<<30,ans_divide;
		int t=org;
		n=0;
		bool regected=false;
		while(t)
		{
			t/=10;
			n++;
		}
		for(int i=0; i<(1<<(n-1)); i++)
		{
			//printf("%d %d\n",i,Minus(i));
			if(ans_minus>Minus(i))
			{
				ans_minus=Minus(i),ans_divide=i;
				regected=false;
			}
			else if(ans_minus==Minus(i))
			{
				regected=true;
			}
		}
		if(ans_minus==INF)
			printf("error\n");
		else if(regected)
			printf("rejected\n");
		else
		{
			printf("%d",tgt-ans_minus);
			int t_mod=1E6;
			for(int i=0; i<=n-2; i++)
			{
				if((ans_divide>>i)&1)
				{
					printf(" %d",(org%t_mod)/(pow10[n-i-1]));
					t_mod=pow10[n-i-1];
				}
			}
			printf(" %d \n",org%t_mod);
		}
	}
	return 0;
}
