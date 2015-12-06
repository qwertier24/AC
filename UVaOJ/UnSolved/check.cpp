#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	/*
	freopen("prob.in","w",stdout);
	srand(time(0));
	int t=rand()%100+1;
	while(t--)
	{
		int n=rand()%1001;
		for(int i=1; i<=n; i++)
			printf("%c",rand()%26+'a');
		printf("\n");
	}
	*/
	char s1[10000],s2[10000];
	FILE* fans=fopen("prob.ans","r");
	FILE* fout=fopen("prob.out","r");
	int count=0;
	while(fgets(s1,10000,fans)!=NULL)
	{
		count++;
		fgets(s2,10000,fout);
		if(strcmp(s1,s2))
		{
			printf("ans: %sout: %s%d",s1,s2,count);
			break;
		}
	}
	return 0;
}
