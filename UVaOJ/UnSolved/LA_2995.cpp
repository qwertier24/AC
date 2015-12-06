#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define REP(i,n) for (int i=1; i<=n; i++)
int n;
void get(int v,int a,int b,int l,int& x,int& y,int &z)
{
	switch(v)
	{
		case 1:
			x=a;y=b;z=l;
			break;
		case 2:
			x=l;y=b;z=n-a+1;
			break;
		case 3:
			x=n-a+1;y=b;z=n-l+1;
			break;
		case 4:
			x=n-l+1;y=b;z=a;
			break;
		case 5:
			x=a;y=n-l+1;z=b;
			break;
		case 6:
			x=a;y=l;z=n-b+1;
			break;
	}
}
int main()
{
	int i,j;
	int view[11][11][11],cube[11][11][11];
	freopen("a.out","w",stdout);
	while(true)
	{
		scanf("%d",&n);
		int ans=n*n*n;
		if(!n)break;
		for (j=n;j>=1 ; j--)REP(i,6)REP(k,n)
		{
			char t=getchar();
			while(!(isupper(t)||t=='.'))
				t=getchar();
			view[i][j][k]=t;
		}//input
		REP(i,n)REP(j,n)REP(k,n)
		{
			cube[i][j][k]='#';
		}
		REP(i,6)REP(j,n)REP(k,n)
		{
			if(view[i][j][k]=='.')
				REP(l,n)
				{
					int x,y,z;
					get(i,j,k,l,x,y,z);
					if(x==1 && y==2 && z==1)
						printf("i=%d j=%d k=%d l=%d\n",i,j,k,l);
					cube[x][y][z]='.';
				}
		}
		REP(i,n)REP(j,n)REP(k,n)
		{
			if(cube[i][j][k]=='.')
				printf("x=%d y=%d z=%d\n",i-1,j-1,k-1);
		}
		while(true)
		{
			bool done=true;
			REP(i,6)REP(j,n)REP(k,n)
			{
				if(view[i][j][k]=='.')continue;
				REP(l,n)
				{
					int x,y,z;
					get(i,j,k,l,x,y,z);
					if(cube[x][y][z]=='.')continue;
					else if(cube[x][y][z]=='#')
					{
						cube[x][y][z]=view[i][j][k];
						break;
					}
					else if(cube[x][y][z]!=view[i][j][k])
					{
						cube[x][y][z]='.';
						done=false;
						continue;
					}
					break;
				}
			}
			if(done)break;
		}
		REP(i,n)REP(j,n)REP(k,n)
			if(cube[i][j][k]=='.')
				ans--;
		printf("%d\n",ans);
	}
	return 0;
}
/*
3
.R. YYR .Y. RYY .Y. .R.
GRB YGR BYG RBY GYB GRB
.R. YRR .Y. RRY .R. .Y.
2
ZZ ZZ ZZ ZZ ZZ ZZ
ZZ ZZ ZZ ZZ ZZ ZZ
0
*/