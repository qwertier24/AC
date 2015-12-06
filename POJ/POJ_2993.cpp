#include <stdio.h>
#include <ctype.h>
#include <cstring>
#define n 17
#define m 33
char g[100][100],s1[2000],s2[2000];
char chr[2][6]={{'K','Q','R','B','N','P'},{'k','q','r','b','n','p'}};
void pos(int& x,int& y,char* t)
{
	x=(8-(t[1]-'0')+1)*2-1;
	y=(t[0]-'a')*4+2;
}
void solve(char* s,int t)
{
	int p=6;
	while(true)
	{
		int x,y;
		p++;
		if(p>=strlen(s))
			break;
		if(isupper(s[p]))
		{
			char type=s[p];
			p++;
			pos(x,y,s+p);
			g[x][y]=type-('A'-'a')*t;
			p+=2;
		}
		else
		{
			pos(x,y,s+p);
			g[x][y]='P'-('A'-'a')*t;
			p+=2;
		}
	}
}
int main()
{
	for(int i=0; i<n; i+=2)
		for(int j=0; j<m; j++)
			g[i][j]='-';
	for(int j=0; j<m; j+=4)
		for(int i=0; i<n; i++)
			g[i][j]='|';
	for(int i=0; i<17; i+=2)
		for(int j=0; j<33; j+=4)
			g[i][j]='+';
	for(int i=1; i<n; i+=4)
		for(int j=1; j<m; j+=8)
			g[i][j]=g[i][j+2]=g[i][j+1]=g[i+2][j+4]=g[i+2][j+6]=g[i+2][j+5]='.';
	for(int i=1; i<n; i+=4)
		for(int j=5; j<m; j+=8)
			g[i][j]=g[i][j+1]=g[i][j+2]=g[i+2][j-2]=g[i+2][j-3]=g[i+2][j-4]=':';
	gets(s1);
	solve(s1,0);
	gets(s2);
	solve(s2,1);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			printf("%c",g[i][j]);
		printf("\n");
	}
	return 0;
}
