#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#include <iostream>
using namespace std;
int d[110][110];
char s[110];
bool match(char a,char b)
{
	if((a=='('&&b==')')||(a=='['&&b==']'))
		return true;
	else
		return false;
}
void print_one_chr(char t)
{
	if(t=='('||t==')')
		printf("()");
	else
		printf("[]");
}
void print(int l,int r)
{
	//printf("%d %d\n",l,r);
	if(r==l)
	{
		print_one_chr(s[l]);
	}
	else if(match(s[l],s[r])&&d[l+1][r-1]==d[l][r])
	{
		printf("%c",s[l]);
		print(l+1,r-1);
		printf("%c",s[r]);
	}
	else
	{
		for(int i=l; i<r; i++)
			if(d[l][i]+d[i+1][r]==d[l][r])
			{
				print(l,i);
				print(i+1,r);
				break;
			}
	}
}
int main()
{
	while(gets(s+1)!=NULL)
	{
		int n=strlen(s+1);
		memset(d,0,sizeof(d));
		for(int i=1; i<=n; i++)
			for(int l=1; l+i-1<=n; l++)
			{
				int r=l+i-1;
				if(match(s[l],s[r]))
					d[l][r]=d[l+1][r-1];
				else
					d[l][r]=d[l][r-1]+1;
				for(int j=l+1; j<=r; j++)
					d[l][r]=min(d[l][r],d[l][j-1]+d[j][r]);
				//printf("%d %d %d:%d\n",i,l,r,d[l][r]);
			}
		//cout<<d[1][n]<<endl;
		print(1,n);
		printf("\n");
	}
	return 0;
}
