#include <stdio.h>
#include <string.h>
int cnt[30];
bool vis[30];
bool check()
{
	for(int i=2; i<=26; i+=2)
		if(cnt[i]%2)
			return false;
	return true;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		char s[27];
		scanf("%s",s);
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		for(int i=0; i<26; i++)
			if(!vis[i])
			{
				int j=i,n=0;
				do{
					vis[j]=true;
					j=s[j]-'A';
					n++;
				}while(j!=i);
				cnt[n]++;
			}
		if(check())
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
