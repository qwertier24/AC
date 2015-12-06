/*
ID: mayukun3
PROG: friday
LANG: C++
*/
#include <stdio.h>
int days(int year,int month)
{
	if(month==1 || month==3||month==5||month==7||month==8||month==10||month==12)
		return 31;
	else if(month==4||month==6||month==9||month==11)
		return 30;
	else
	{
		if(year%4 || (year%100==0&&year%400))
			return 28;
		else
			return 29;
	}
}
int main()
{
	freopen("friday.in","r",stdin);
	freopen("friday.out","w",stdout);
	int count[7]={0};
	int begin=1900,end,t,day=5;
	scanf("%d",&t);
	end=begin+t-1;
	for(int i=begin; i<=end; i++)
		for(int j=1; j<=12; j++)
		{
			count[day]++;
			day=(day+days(i,j))%7;
		}
	printf("%d %d",count[5],count[6]);
	for(int i=0; i<5; i++)
		printf(" %d",count[i]);
	printf("\n");
}