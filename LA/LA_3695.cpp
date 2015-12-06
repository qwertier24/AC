#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
#include <cstring>
using namespace std;
struct Point
{
	int x,y;
}p[101];
int nx,ny,x[101],y[101],n;
int on[101],on2[101],left[101];
inline int max(const int a,const int b)
{
	return a>b?a:b;
}
void calc(int t,int b)
{
    memset(on,0,sizeof(on));
    memset(on2,0,sizeof(on2));
    memset(left,0,sizeof(left));
	//printf("ny=%d",ny);
	for (int i=1; i<=ny;i++ )
	{
		left[i]=left[i-1] - on2[i-1] + on[i-1];
	    /*for(int j=1; j<=n; j++)
	    {
	        if(p[j].y==y[i-1]&&(p[j].x==t || p[j].x==b))
			{
                left[i]++;
				//printf("%d\n",j);
			}
	    }*/
		for(int j=1; j<=n; j++)
			if(p[j].y==y[i] && p[j].x>=t && p[j].x<=b)
			{
				on[i]++;
				if(p[j].x>t && p[j].x<b)
					on2[i]++;
			}
		//printf("T=%d B=%d ON[%d]=%d\n",t,b,i,on2[i]);
	}
}
void add(int x1,int y1)
{
	int p=lower_bound(x+1,x+nx+1,x1)-x;
	//printf("%d  %d\n",x1,p);
	if(x[p]!=x1)
	{
		for (int i=nx;i>=p; i-- )
			x[i+1]=x[i];
		x[p]=x1;
		nx++;
	}
	p=lower_bound(y+1,y+ny+1,y1)-y;
	if(y[p]!=y1)
	{
		for (int i=ny;i>=p; i--)
			y[i+1]=y[i];
		y[p]=y1;
		ny++;
	}
}
int main()
{
	int kase=0;
	while(scanf("%d",&n))
	{
	    int ans=0;
		if(!n)break;
		nx=0;ny=0;
		for (int i=1;i<=n ;i++ )
		{
			scanf("%d %d",&p[i].y,&p[i].x);
			add(p[i].x,p[i].y);
		}
		//printf("%d %d\n",nx,ny);
		if(nx<=2 || ny<=2)
        {
            printf("Case %d: %d\n",++kase,n);
            continue;
        }
		for(int i=1; i<=nx;i++)
			for(int j=i+1; j<=nx;j++ )
			{
				calc(x[i],x[j]);
				int max_sum=0;
				for(int k=1; k<=ny;k++)
				{
				    ans=max(ans,left[k]+on[k]+max_sum);
				    max_sum=max(max_sum,on2[k]-left[k]);
					//printf("t=%d b=%d max_sum=%d\n",x[i],x[j],left[k]+on[k]+max_sum);
                }
			}
        printf("Case %d: %d\n",++kase,ans);
	}
	return 0;
}
