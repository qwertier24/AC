/*
ID: mayukun3
PROG: packrec
LANG: C++
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
#define INF 2000000
#define REP(i) for(int i=-4; i<=4; i=((i==-1)?1:i+1))
using namespace std;
int m0[5],n0[5];
int m(int a)
{
	return a<0? n0[-a]:m0[a];
}
int n(int a)
{
	return a<0? m0[-a]:n0[a];
}
struct RECTANGLE
{
	int p,q;
};
struct ANS
{
	int min_s,n;
	RECTANGLE rec[200];
}ans;
bool cmp(const RECTANGLE& a,const RECTANGLE& b)
{
	return a.p<b.p;
}
void calc(int p,int a,int b,int c,int d)
{
	int chang,kuan;
	if(p==1)
	{
		kuan=min(max(max(m(a),m(b)),max(m(c),m(d))) ,n(a)+n(b)+n(c)+n(d));
		chang=max(n(a)+n(b)+n(c)+n(d),max(max(m(a),m(b)),max(m(c),m(d))));
	}
	else if(p==2)
	{
		
		
		kuan=min(max(n(a)+n(b)+n(c),n(d)),max(max(m(a),m(b)),m(c))+m(d));
		chang=max(max(n(a)+n(b)+n(c),n(d)),max(max(m(a),m(b)),m(c))+m(d));
	}
	else if(p==3)
	{
		kuan=min(( max(n(a)+n(b),n(d))+n(c)) ,max(max(m(a)+m(d),m(b)+m(d)),m(c)));
		chang=max(( max(n(a)+n(b),n(d))+n(c)) , max(max(m(a)+m(d),m(b)+m(d)),m(c)));
	}
	else if(p==4)
	{
		chang=max(n(a)+n(c)+max( n(b),n(d) ),max(m(a),max(m(b)+m(d),m(c))));
		kuan=min(n(a)+n(c)+max( n(b),n(d) ),max(m(a),max(m(b)+m(d),m(c))));
	}
	else if(p==5)
	{
		chang =max(max(m(a)+m(b),max(m(c),m(d))),max(n(a),n(b))+n(c)+n(d));
		kuan=min(max(m(a)+m(b),max(m(c),m(d))),max(n(a),n(b))+n(c)+n(d));
	}
	else if(p==6)
	{
		int w;
		if(m(c)>=m(d) && (n(a)>n(c) || n(b)<n(d)))
			w=max(n(a)+n(b),n(c)+n(d));
		else
			w=max(n(a),n(c))+max(n(b),n(d));
		//max(n(c),n(a))+max(n(b),n(d))
		chang=max(max(m(a)+m(c),m(b)+m(d)),w);
		kuan=min(max(m(a)+m(c),m(b)+m(d)),w);
	}
	if(ans.min_s>chang*kuan)
	{
		//printf("P:%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",p,a,m(a),n(a),b,m(b),n(b),c,m(c),n(c),d,m(d),n(d),chang,kuan);
		ans.min_s=chang*kuan;
		ans.n=1;
		ans.rec[1].q=chang;
		ans.rec[1].p=kuan;
	}
	if(ans.min_s==chang*kuan)
	{
		for(int i=1; i<=ans.n; i++)
			if(ans.rec[i].q==chang && ans.rec[i].p==kuan)
				return;
		ans.rec[++ans.n].q=chang;
		ans.rec[ans.n].p=kuan;
	}
}
int main()
{
	freopen("packrec.in","r",stdin);
	freopen("packrec.out","w",stdout);
	ans.n=0,ans.min_s=INF;
	bool vis[5]={0};
	for(int i=1; i<=4; i++)
		scanf("%d %d",&m0[i],&n0[i]);
	for(int a=1; a<=6; a++)
		REP(i)
		{
			vis[abs(i)]=true;
			REP(j)
				if(!vis[abs(j)])
				{
					vis[abs(j)]=true;
					REP(k)
						if(!vis[abs(k)])
						{
							vis[abs(k)]=true;
							REP(l)
								if(!vis[abs(l)])
								{
									calc(a,i,j,k,l);
								}
							vis[abs(k)]=false;
						}
					vis[abs(j)]=false;
				}
			vis[abs(i)]=false;
		}
	printf("%d\n",ans.min_s);
	sort(ans.rec+1,ans.rec+ans.n+1,cmp);
	for(int i=1; i<=ans.n; i++)
		printf("%d %d\n",ans.rec[i].p,ans.rec[i].q);
	return 0;
}
