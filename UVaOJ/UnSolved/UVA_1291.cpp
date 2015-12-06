#include <stdio.h>
#include <iostream>
using namespace std;
#define INF 100000000
long long d[2][5][5];
long long strength[5][5];
void Init()
{
	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
			strength[i][j]=3;
	for(int i=1; i<5; i++)
		strength[0][i]=2;
	for(int i=0; i<5; i++)
		strength[i][i]=1;
	strength[2][4]=strength[4][2]=strength[1][3]=strength[3][1]=4;
}
inline long long  min(long long a,long long b)
{
	return a<b?a:b;
}
int main()
{
	Init();
	while(true)
	{
		int i=0,step;
		scanf("%d",&step);
		if(!step)break;
		for(int j=0; j<5; j++)
			for(int k=0; k<5; k++)
				d[i][j][k]=0;
		for(int j=0; j<5; j++)
			if(j!=step)
				d[i][step][j]=d[i][j][step]=2;
		for(i=1; scanf("%d",&step)&&step; i=(i+1)%2)
		{
			for(int j=0; j<5; j++)
				for(int k=0; k<5; k++)
					d[i][j][k]=0;
			for(int r=0; r<5; r++)
				if(r!=step)
				{
					for(int l1=0; l1<5; l1++)
						if(l1!=r && d[(i+1)%2][l1][r])
							d[i][step][r]=d[i][step][r]==0? d[(i+1)%2][l1][r]+strength[l1][step] : min(d[i][step][r],d[(i+1)%2][l1][r]+strength[l1][step]);
					for(int r1=0; r1<5; r1++)
						if(r1!=step && d[(i+1)%2][step][r1])
							d[i][step][r]=d[i][step][r]==0? d[(i+1)%2][step][r1]+strength[r1][r] : min(d[i][step][r],d[(i+1)%2][step][r1]+strength[r][r1]);
				}
			for(int l=0; l<5; l++)
				if(l!=step)
				{
					for(int l2=0; l2<5; l2++)
						if(l2!=step && d[(i+1)%2][l2][step])
							d[i][l][step]=d[i][l][step]==0? d[(i+1)%2][l2][step] + strength[l2][l] : min(d[i][l][step],d[(i+1)%2][l2][step] + strength[l2][l]);
					for(int r2=0; r2<5; r2++)
						if(r2!=l && d[(i+1)%2][l][r2])
							d[i][l][step]=d[i][l][step]==0? d[(i+1)%2][l][r2] + strength[r2][step] : min(d[i][l][step],d[(i+1)%2][l][r2] + strength[r2][step]);
				}
		}
			i=(i+1)%2;
			long long ans=0;
			for(int j=0; j<5; j++)
			{
				if(d[i][step][j]!=0)
					ans=ans==0?d[i][step][j]:min(ans,d[i][step][j]);
				if(d[i][j][step]!=0)
					ans=ans==0?d[i][j][step]:min(ans,d[i][j][step]);
			}
			cout<<ans<<endl;
	}
	return 0;
}
