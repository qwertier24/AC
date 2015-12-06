/*
ID: mayukun3
PROG: runround
LANG: C++
*/
#include <stdio.h>
#include <string.h>
int bign[10000],len=0;
bool circle()
{
	int vis[1000]={0};
	bign[0]++;
	int c=bign[0]/10;
	bign[0]%=10;
	int i=1;
	while(c!=0)
	{
		int t=bign[i]+c;
		c=t/10;
		bign[i]=t%10;
		if(i+1>len)len=i+1;
		i++;
	}
	for(int i=0; i<len; i++)
	{
		if(vis[bign[i]])
			return false;
		vis[bign[i]]=1;
	}
	memset(vis,0,sizeof(vis));
	int count=1;
	for(int j=len-1; j>=0;)
	{
		vis[j]=true;
		j=(j-bign[j]+len*10)%len;
		count++;
		if(j==len-1&&count==len+1)
			return true;
		else if(j==len-1||vis[j])
			return false;
	}
}
int main()
{
	freopen("runround.in","r",stdin);
	freopen("runround.out","w",stdout);
	char s[1000];
	scanf("%s",s);
	len=strlen(s);
	for(int i=0; i<len; i++)
		bign[i]=s[len-i-1]-'0';
	while(!circle())
	{
	}
	for(int i=len-1; i>=0; i--)
		printf("%d",bign[i]);
	printf("\n");
}