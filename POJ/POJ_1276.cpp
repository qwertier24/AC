#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<map>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;
int num[1000],f[1001],d[11][100001];
int main()
{
        freopen("prob.in","r",stdin);
        int n,C;
        while(scanf("%d%d",&C,&n)!=EOF)
        {
                int ans=C;
                memset(d,-1,sizeof(d));
                d[0][0]=0;
                for(int i=1; i<=n; i++)
                {
                        scanf("%d%d",&num[i],&f[i]);
                        for(int j=0; j<f[i]; j++)
                                d[i][j]=d[i-1][j];
                        for(int j=0; j<=C-f[i]; j++)
                                if(d[i-1][j+f[i]]!=-1)
                                        d[i][j+f[i]]=0;
                                else if(d[i][j]!=-1)
                                        d[i][j+f[i]]=d[i][j]+1;
                        for(int j=0; j<=C; j++)
                        {
                                //if(d[i][j]!=-1)
                                //       printf("d[%d][%d]=%d\n",i,j,d[i][j]);
                                if(d[i][j]>num[i])
                                        d[i][j]=-1;
                        }
                }
                while(ans>0&&d[n][ans]==-1)
                        ans--;
                printf("%d\n",ans);
        }
}
