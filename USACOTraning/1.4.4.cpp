/*
ID: mayukun3
PROG: ariprog
LANG: C++
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <vector>
using namespace std;
int next[250*500+1],maxn;
bool num[250*500+500]={0};
struct P
{
	int start,length;
	P(int a,int b):start(a),length(b){}
};
vector<P> v;
bool check(int start,int d,int n)
{
	int loop=start+d*(n-1);
	for(int i=start; i<=loop; i+=d)
		if(!num[i])
			return false;
	return true;
}
int main()
{
	int m,maxl;
	freopen("ariprog.in","r",stdin);
	freopen("ariprog.out","w",stdout);
	scanf("%d %d",&maxl,&m);
	maxn=m*m*2;
	for(int i=0; i<=m; i++)
		for(int j=0; j<=i; j++)
		{
			num[i*i+j*j]=true;
		}
	int t=maxn+1;
	for(int i=maxn; i>=0; i--)
		if(num[i])
		{
			next[i]=t;
			t=i;
		}
	int loop1=(maxn)/(maxl-1);
	for(int i=1; i<=loop1; i++)
	{
		int loop2=maxn-(maxl-1)*i;
		//j+(maxl-1)*i<=maxn
		for(int j=0; j<=loop2; j++)
			if(check(j,i,maxl))
			{
				v.push_back(P(j,i));
			}
	}
	/*
	for(int i=0; i<=maxn; i=next[i])
	{
		int loop=(maxn-i+1)/maxl;
		for(int j=1; j<=loop; j++)
			if(check(i,j,maxl))
			{
				P point;
				point.start=i;
				point.length=j;
				v.push_back(point);
			}
	}
	*/
	if(v.size()==0)
		printf("NONE\n");
	else
	for(int i=0; i<v.size(); i++)
		printf("%d %d\n",v[i].start,v[i].length);
	return 0;
}
