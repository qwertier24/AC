/*
ID: mayukun3
PROG: passwd
LANG: C++
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
int L,n,v_cnt[30]={0},nov_cnt[30]={0},ans=0;
char s[20],chr[30];
int isvowel(char t)
{
	return (t=='a'||t=='e'||t=='i'||t=='o'||t=='u');
}
void search(int pos,int v_num,int nov_num,int deep)
{
	if(ans>=25000)
		return;
	//printf("%d %d %d %c\n",deep,v_num,nov_num,chr[pos]);
	if(1-v_num>v_cnt[pos]||2-nov_num>nov_cnt[pos])
		return;
	s[deep]=chr[pos];
	if(deep==L-1)
	{
		if(v_num+isvowel(chr[pos])>=1&&nov_num+(!isvowel(chr[pos]))>=2)
		{
		ans++;
		printf("%s\n",s);
		}
		else
			return;
	}
	else
	{
		for(int i=pos+1; n-i>=L-1-deep; i++)
			search(i,v_num+isvowel(chr[pos]),nov_num+(!isvowel(chr[pos])),deep+1);
	}
}
int main()
{
	freopen("passwd.in","r",stdin);freopen("passwd.out","w",stdout);
	scanf("%d%d",&L,&n);
	for(int i=0; i<n; i++)
	{
		scanf("%s",s);
		chr[i]=s[0];
	}
	sort(chr,chr+n);
	for(int i=n-1; i>=0; i--)
	{
		v_cnt[i]=v_cnt[i+1]+isvowel(chr[i]);
		nov_cnt[i]=nov_cnt[i+1]+(!isvowel(chr[i]));
		//printf("%d %d %d\n",i,v_cnt[i],nov_cnt[i]);
	}
	for(int i=0; i<=n; i++)
		search(i,0,0,0);
	return 0;
}