#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int cnt[12][26]={0};
char s[20];
bool check(int n)
{
	for(int i=1; i<n; i++)
		if(s[i]<=s[i-1])
			return false;
	return true;
}
int main()
{
	for(int i=0; i<26; i++)
		cnt[1][i]=1;
	for(int i=2; i<=10; i++)
		for(int j=0; j<26; j++)
			for(int k=j+1; k<26; k++)
				cnt[i][j]+=cnt[i-1][k];
	while(scanf("%s",s)!=EOF)
	{
		int n=strlen(s),p=0,last_alpha=-1;
		if(check(n))
		{
			for(int i=1; i<=n-1; i++)
				for(int j=0; j<26; j++)
					p+=cnt[i][j];
			for(int i=n; i>=1; i--)
			{
				for(int j=last_alpha+1; j<s[n-i]-'a'; j++)
				{
					//printf("%d %d %d %d\n",last_alpha,i,j,cnt[i][j]);
					p+=cnt[i][j];
				}
				last_alpha=s[n-i]-'a';
				//printf("%d %d\n",last_alpha,i);
			}
			printf("%d\n",p+1);
		}
		else
			printf("0\n");
	}
	return 0;
}
