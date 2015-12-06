#include <stdio.h>
#include <string.h>
int d[20010],def[20010],num[20010],pa[20010];
int findset(int x)
{
	if(pa[x]==x)
		return x;
	int root=findset(pa[x]);
	d[x]^=d[pa[x]];
	pa[x]=root;
	return pa[x];
}
int main()
{
	int n,q,a,b,kase=1;
	char order[200];
	while(scanf("%d%d",&n,&q)&&n)
	{
		printf("Case %d:\n",kase++);
		memset(d,0,sizeof(d));
		memset(def,0,sizeof(def));
		for(int i=0; i<n; i++)
			pa[i]=i;
		bool ok=true;
		int fact_cnt=0;
		for(int i=1; i<=q; i++)
		{
			if(!ok){gets(order);continue;}
			scanf("%s",order);
			if(order[0]!='I'&&order[0]!='Q')
				scanf("%s",order);
			if(order[0]=='I')
			{
				int v;
				fact_cnt++;
				gets(order);
				if(sscanf(order,"%d %d %d",&a,&b,&v)==2)
				{
					//printf("%d %d %d\n",a,b,q);
					findset(a);
					if(!def[pa[a]])
						num[pa[a]]=b^d[a],def[pa[a]]=1;
					else if(num[pa[a]]!=b^d[a])
					{
						printf("The first %d facts are conflicting.\n",fact_cnt);
						ok=false;
						continue;
					}
				}
				else
				{
					//printf("%d %d %d\n",a,b,q);
					findset(a);findset(b);
					if(pa[a]==pa[b])
					{
						if(d[a]^d[b]!=v)
						{
							printf("The first %d facts are conflicting.\n",fact_cnt);
							ok=false;
							continue;
						}
					}
					else
					{
						if(def[pa[a]]&&def[pa[b]]&&num[pa[a]]^num[pa[b]]!=v)
						{
							printf("The first %d facts are conflicting.\n",fact_cnt);
							ok=false;
							continue;
						}
						int t=pa[a];pa[t]=a;d[t]=d[a];
						pa[a]=b;
						d[a]=v;
						findset(t);
						if(!def[pa[t]]&&def[t])
						{
							num[pa[t]]=num[t]^d[t];
							def[pa[t]]=1;
						}
					}
				}
			}
			else
			{
				int v[100],k,cnt=0,t=0;
				scanf("%d",&k);
				for(int j=1; j<=k; j++)
				{
					scanf("%d",&v[j]);
					if(v[j]>=n)
						cnt=-1;
				}
				int root_num=-1;
				for(int j=1; j<=k&&cnt!=-1; j++)
				{
					findset(v[j]);
					if(def[pa[v[j]]])
						v[j]=d[v[j]]^num[pa[v[j]]];
					else
					{
						if(pa[v[j]]==root_num||root_num==-1)
						{
							root_num=pa[v[j]];
							v[j]=d[v[j]];
							cnt++;
						}
						else
							cnt=-1;
					}
				}
				if(cnt%2)printf("I don't know.\n");
				else {for(int j=1;j<=k; j++)t^=v[j]; printf("%d\n",t);}
			}
		}
		printf("\n");
	}
	return 0;
}
