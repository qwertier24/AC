#include <stdio.h>
#include <string.h>
char str[1001];
int dp[1001][1001],p[1001][1001];
int DP(int x,int y)
{
    int &ans = dp[x][y];
    if(ans != -1)
        return ans;
    if(x >= y)
    {
        ans = 0;
        return ans;
    }
    if(str[x] == str[y])
    {
        ans = DP(x + 1,y - 1);
        p[x][y] = 0;
    }
    else if(DP(x + 1,y) > DP(x,y - 1))
    {
        ans = DP(x,y - 1) + 1;
        p[x][y] = -1;//取后面
    }
    else
    {
        ans = DP(x + 1,y) + 1;
        p[x][y] = 1;//取前面
    }
    return ans;
}
void printans(int x,int y)
{
    if(x > y)
        return;
    if(x == y)
        printf("%c",str[x]);
    else if(p[x][y] == 0)
    {
        printf("%c",str[x]);
        printans(x + 1,y - 1);
        printf("%c",str[y]);
    }
    else if(p[x][y] == 1)
    {
        printf("%c",str[x]);
        printans(x + 1,y);
        printf("%c",str[x]);
    }
    else
    {
        printf("%c",str[y]);
        printans(x,y - 1);
        printf("%c",str[y]);
    }
}
int main()
{
	freopen("prob.in","r",stdin);
	freopen("prob.ans","w",stdout);
    while(scanf("%s",str) != EOF)
    {
        memset(dp,-1,sizeof(dp));
        int len = strlen(str);
        printf("%d ",DP(0,len - 1));
        printans(0,len - 1);
        putchar('\n');
    }
    return 0;
}