/*
ID: mayukun3
PROG: fracdec
LANG: C++
*/
#include <stdio.h>
#include <string.h>
int main()
{
	int a,b,remain,bign[100010],vis[100010];
	freopen("fracdec.in","r",stdin);freopen("fracdec.out","w",stdout);
	scanf("%d %d",&a,&b);
	remain=a%b;
	bign[0]=a/b;
	if(remain==0)
		printf("%d.0\n",bign[0]);
	else
	{
		int cycle_length=0,cnt=0;
		char ans[100010];
		for(cnt=1; remain; cnt++)
		{
			if(vis[remain])
			{
				cycle_length=cnt-vis[remain];
				break;
			}
			vis[remain]=cnt;
			bign[cnt]=remain*10/b;
			remain=remain*10%b;
		}
		sprintf(ans,"%d.",bign[0]);
		int p=strlen(ans);
		if(cycle_length==0)
		{
			for(int i=1; i<=cnt-1; i++)
				ans[p++]=bign[i]+'0';
			ans[p]='\0';
		}
		else
		{
			for(int i=1; i<=cnt-cycle_length-1; i++)
				ans[p++]=bign[i]+'0';
			ans[p++]='(';
			for(int i=cnt-cycle_length; i<cnt; i++)
				ans[p++]=bign[i]+'0';
			ans[p++]=')';
			ans[p]='\0';
		}
		for(int i=0; i<p; i++)
		{
			if(i%76==0&&i)
				printf("\n");
			printf("%c",ans[i]);
		}
		printf("\n");
	}
	return 0;
}