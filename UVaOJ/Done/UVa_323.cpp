#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int d[201][21][801],l[201],r[201],ans[30];
int main()
{
	int n,m,kase=1;
	while(scanf("%d%d",&n,&m)&&n)
	{
		int min_minus=1000000,max_sum,last_i;
		memset(d,0,sizeof(d));
		d[0][0][400]=1;
		for(int i=1; i<=n; i++)
		{
			d[i][0][400]=1;
			scanf("%d%d",&l[i],&r[i]);
			for(int j=m; j>=1; j--)
				for(int k=max(0,l[i]-r[i]); k<=min(800,800+l[i]-r[i]); k++)
				{
					d[i][j][k]=d[i-1][j][k];
					if(d[i-1][j-1][k-l[i]+r[i]])
						d[i][j][k]=max(d[i][j][k],d[i-1][j-1][k-l[i]+r[i]]+l[i]+r[i]);
					if(d[i][j][k]&&j==m)
					{
						if(abs(min_minus)>abs(400-k)||(abs(min_minus)==abs(400-k)&&max_sum<d[i][m][k]-1))
							min_minus=k-400,max_sum=d[i][m][k]-1,last_i=i;
					}
					//if(d[i][j][k])
					//printf("d[%d][%d][%d]=%d\n",i,j,k,d[i][j][k]);
				}
		}
		printf("Jury #%d\n",kase++);
		printf("Best jury has value %d for prosecution and value %d for defence:\n",(max_sum+min_minus)/2,(max_sum-min_minus)/2);
		ans[m]=last_i;
		max_sum++;
		min_minus+=400;
		int p;
		for(int j=m-1; j>=1; j--)
		{
			for(p=1; d[p][j][min_minus-l[last_i]+r[last_i]]!=max_sum-l[last_i]-r[last_i]; p++){}
			//printf("%d %d\n",j,p);
			ans[j]=p;
			min_minus-=l[last_i]-r[last_i];
			max_sum-=l[last_i]+r[last_i];
			last_i=p;
		}
		for(int i=1; i<=m; i++)
			printf(" %d",ans[i]);
		printf("\n\n");
	}
	return 0;
}
