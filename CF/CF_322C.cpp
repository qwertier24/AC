#include <stdio.h>
#include <cstring>
int vis[300][300]={0};
bool check(int a1,int a2,int b1,int b2)
{
	//printf("a1 %d a2 %d\n",a1,a2);
	if(a2==0)
	{
		return a1==a2&&b1%b2==0&&b1/b2>=0;
	}
	else if(b2==0)
	{
		return b1==b2&&a1%a2==0&&a1/a2>=0;
	}
	else
	{
		return b1%b2==0&&a1%a2==0&&b1/b2==a1/a2&&b1/b2>=0;
	}
}
int main()
{
	char opt[200];
	int x,y;
	scanf("%d%d%s",&x,&y,opt);
	x+=100,y+=100;
	int steps=strlen(opt);
	vis[100][100]=1;
	int last_x=100,last_y=100;
	if(last_x==x&&last_y==y)
	{
		printf("Yes");
		return 0;
	}
	for(int i=0; i<steps; i++)
	{
		if(opt[i]=='U')
		{
			last_y++;
			vis[last_x][last_y]=1;
		}
		else if(opt[i]=='D')
		{
			last_y--;
			vis[last_x][last_y]=1;
		}
		else if(opt[i]=='L')
		{
			last_x--;
			vis[last_x][last_y]=1;
		}
		else
		{
			last_x++;
			vis[last_x][last_y]=1;
		}
		if(last_x==x&&last_y==y)
		{
			printf("Yes");
			return 0;
		}
	}
	//printf("%d %d\n",last_x,last_y);
	if(last_x==100&&last_y==100)
	{
		printf("No");
		return 0;
	}
	for(int i=0; i<=200; i++)
		for(int j=0; j<=200; j++)
			if(vis[i][j]&&check(x-i,last_x-100,y-j,last_y-100))
			{
				//printf("%d %d %d %d\n",i,j,x,y);
				printf("Yes");
				return 0;
			}
	printf("No");
	return 0;
}
