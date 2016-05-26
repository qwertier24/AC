#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#define zero 10
using namespace std;
int d[1001][30][11]={0},weight[11]={0},m,last_step[1001][30][11];
vector<int> ans;
int main()
{
	char s[20];
	scanf("%s",s);
	for(int i=0; i<10; i++)
		weight[i+1]=s[i]-'0';
	scanf("%d",&m);
	d[0][zero][0]=1;
	for(int i=1; i<=m; i++)
		for(int j=0; j<=20; j++)
			for(int k=0; k<=10; k++)
				for(int cur=1; cur<=10; cur++)
				{
						//if(j==zero&&k==0&&l==0&&i-1==0)
						//	printf("%d %d\n",d[i-1][j][k][l],weight[cur]&&i%2&&cur!=k&&j+cur<=zero+10&&(j<zero||(j==zero&&i-1==0)));
					if(weight[cur]&&i%2&&cur!=k&&j+cur<=zero+10&&(j<zero||(j==zero&&i-1==0)))
					{
						//if(j==zero&&k==0&&l==0&&i-1==0)
						//	printf("%d \n",d[i-1][j][k][l]);
						if(d[i-1][j][k])
						{
							//printf("%d %d %d %d\n",i,j+cur-zero,cur,l);
							d[i][j+cur][cur]=1;
							last_step[i][j+cur][cur]=k;
							//printf("%d %d %d %d\n",i,j+cur-zero,cur,l);
						}
					}
					else if(weight[cur]&&i%2==0&&cur!=k&&j-cur>=0&&j>zero)
					{
						if(d[i-1][j][k])
						{
							d[i][j-cur][cur]=1;
							last_step[i][j-cur][cur]=k;
							//printf("%d %d %d %d\n",i,j-cur-zero,k,cur);
						}
					}
				}
	if(m%2)
	{
		bool ok=false;
		int minus,step;
		for(int i=zero+1; i<=zero+10&&!ok; i++)
			for(int j=1; j<=10&&!ok; j++)
				if(d[m][i][j])
				{
					ok=true;
					minus=i,step=j;
					break;
				}
		if(ok)
		{
			printf("YES\n");
			for(int i=m; i>=1; i--)
			{
				if(i%2)
				{
					ans.push_back(step);
					int t=minus;
					minus-=step;
					step=last_step[i][t][step];
				}
				else
				{
					ans.push_back(step);
					int t=minus;
					minus+=step;
					step=last_step[i][t][step];
				}
			}
			for(int i=ans.size()-1; i>=0; i--)
				printf("%d ",ans[i]);
		}
		else
			printf("NO");
	}
	else
	{
		bool ok=false;
		int minus,step;
		for(int i=zero-1; i>=0; i--)
			for(int j=1; j<=10&&!ok; j++)
					if(d[m][i][j])
					{
						ok=true;
						//printf("%d %d %d\n",i,j,k);
						minus=i,step=j;
						break;
					}
		if(ok)
		{
			printf("YES\n");
			for(int i=m; i>=1; i--)
			{
				if(i%2)
				{
					ans.push_back(step);
					int t=minus;
					minus-=step;
					step=last_step[i][t][step];
				}
				else
				{
					ans.push_back(step);
					int t=minus;
					minus+=step;
					step=last_step[i][t][step];
				}
			}
			for(int i=ans.size()-1; i>=0; i--)
				printf("%d ",ans[i]);
		}
		else
			printf("NO");
	}
	return 0;
}
