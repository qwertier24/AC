/*
ID: mayukun3
PROG: zerosum
LANG: C++
*/
#include <stdio.h>
char e0[4]={' ','+','-'},exp[10];
int n;
void print(char* s)
{
	printf("1");
	for(int i=0; i<n-1; i++)
		printf("%c%d",s[i],i+2);
	printf("\n");
}
void search(int deep)
{
	if(deep==n)
	{
		int last_num=1,result=0,opt=1;
		for(int i=1; i<n; i++)
		{
			if(exp[i]==' ')
				last_num=last_num*10+i+1;
			else if(exp[i]=='+')
			{
				result+=last_num*opt;
				last_num=i+1;
				opt=1;
			}
			else
			{
				result+=last_num*opt;
				last_num=i+1;
				opt=-1;
			}
		}
		result+=opt*last_num;
		if(result==0)
			print(exp+1);
		return;
	}
	for(int i=0; i<3; i++)
	{
		exp[deep]=e0[i];
		search(deep+1);
	}
}
int main()
{
	freopen("zerosum.in","r",stdin);
	freopen("zerosum.out","w",stdout);
	scanf("%d",&n);
	for(int i=0; i<3; i++)
	{
		exp[1]=e0[i];
		search(2);
	}
}