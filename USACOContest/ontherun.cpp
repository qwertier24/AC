/*
ID: mayukun3
PROG: ontherun
LANG: C++
*/
#include <stdio.h>
#include <algorithm>
#define L 0
#define R 1
#define INF 1<<30
using namespace std;
int d[1010][1010][2];
int lp[1010]={0},lpn=0,rp[1010]={0},rpn=0,p0,n,pt;
bool cmp(const int& a,const int& b)
{
	return a>b;
}
int main()
{
	freopen("ontherun.in","r",stdin);freopen("ontherun.out","w",stdout);
	scanf("%d%d",&n,&p0);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&pt);
		if(pt<p0)
			lp[++lpn]=pt;
		else if(pt>p0)
			rp[++rpn]=pt;
	}
	sort(lp+1,lp+lpn+1,cmp);
	sort(rp+1,rp+rpn+1);
	for(int i=0; i<=lpn; i++)
		for(int j=0; j<=rpn; j++)
			d[i][j][0]=d[i][j][1]=INF;
	d[lpn+1][rpn][L]=d[lpn+1][rpn][R]=d[lpn][rpn+1][L]=d[lpn][rpn+1][R]=0;
	lp[0]=p0;
	rp[0]=p0;
	//printf("%d\n",rp[2]);
	for(int i=lpn; i>=0; i--)
		for(int j=rpn; j>=0; j--)
		{
			//printf("%d %d:\n",i,j);
			if(i<lpn)
			{
				d[i][j][L]=min(d[i][j][L],d[i+1][j][L]+(lp[i]-lp[i+1])*(lpn-i+rpn-j+1));
				d[i][j][L]=min(d[i][j][L],d[i+1][j][R]+(rp[j]-lp[i])*(lpn-i+rpn-j+1));
				//printf("  %d %d %d\n",d[i][j][L],(rp[j]-lp[i]),(lpn-i+rpn-j+1));
			}
			else
			{
				d[i][j][L]=d[i][j+1][L]+rp[j]-lp[i];
			}
			if(j<rpn)
			{
				d[i][j][R]=min(d[i][j][R],d[i][j+1][R]+(rp[j+1]-rp[j])*(rpn-j+lpn-i+1));
				d[i][j][R]=min(d[i][j][R],d[i][j+1][L]+(rp[j]-lp[i])*(rpn-j+lpn-i+1));
			}
			else
			{
				d[i][j][R]=d[i+1][j][R]+rp[j]-lp[i];
			}
			//printf("  %d %d\n",d[i][j][L],d[i][j][R]);
		}
	printf("%d\n",d[0][0][L]);
	return 0;
}