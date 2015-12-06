#include <stdio.h>
#include <string.h>
int n,n2,pos[100001],point[200001];
void add(int num,int p)
{
	while(p<=n2)
	{
		point[p]+=num;
		p+=p&(-p);
	}
}
int get(int p)
{
	int ret=0;
	while(p>0)
	{
		ret+=point[p];
		p-=p&(-p);
	}
	return ret;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(point,0,sizeof(point));
		int m;
		scanf("%d%d",&n,&m);
		int p=n;
		n2=100000+n;
		for(int i=1; i<=n; i++)
		{
			pos[i]=100000+i;
			add(1,pos[i]);
		}
		int cd_num;
		scanf("%d",&cd_num);
		printf("%d",get(pos[cd_num])-1);
		add(-1,pos[cd_num]);
		pos[cd_num]=100000;
		add(1,pos[cd_num]);
		for(int i=2; i<=m; i++)
		{
			scanf("%d",&cd_num);
			printf(" %d",get(pos[cd_num])-1);
			add(-1,pos[cd_num]);
			pos[cd_num]=100000-i+1;
			add(1,pos[cd_num]);
		}
		printf("\n");
	}
	return 0;
}
