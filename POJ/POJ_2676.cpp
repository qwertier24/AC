#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int g[9][9],row[9][10],col[9][10],block[9][10];
bool found;
void print()
{
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
			printf("%d",g[i][j]);
		printf("\n");
	}
}
inline int block_num(int x,int y)
{
	return (x/3)*3+y/3;
}
inline bool check(int x,int y,int num)
{
	if(row[x][num]||col[y][num]||block[block_num(x,y)][num])
		return false;
	else
		return true;
}
void search(int pos)
{
	if(pos==81)
	{
		print();
		found=true;
		return;
	}
	int x=pos/9,y=pos%9;
	//printf("%d %d %d\n",x,y,row[8][9]);
	//print();
	if(!g[x][y])
	{
		for(int i=1; i<10&&!found; i++)
			if(check(x,y,i))
			{
				g[x][y]=i;
				row[x][i]=col[y][i]=block[block_num(x,y)][i]=1;
				search(pos+1);
				row[x][i]=col[y][i]=block[block_num(x,y)][i]=0;
				g[x][y]=0;
			}
	}
	else
	{
		search(pos+1);
	}
}
int main()
{
	//freopen("prob.out","w",stdout);
	char s[20];
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(row,0,sizeof(row));
		memset(col,0,sizeof(col));
		memset(block,0,sizeof(block));
		found=false;
		for(int i=0; i<9; i++)
		{
			scanf("%s",s);
			for(int j=0; j<9; j++)
			{
				g[i][j]=s[j]-'0';
				if(g[i][j])
					row[i][g[i][j]]=col[j][g[i][j]]=block[block_num(i,j)][g[i][j]]=1;
			}
		}/*
		for(int i=0; i<9; i++)
		{
			for(int j=1; j<10; j++)
			printf("%d ",row[i][j]);
			printf("\n");
		}*/
		search(0);
	}
	return 0;
}
