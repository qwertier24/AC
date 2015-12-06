#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
int n,m,kase=1;
int match_num[10]={6,2,5,5,4,5,6,3,7,6},d[110][3000],pow10[100]={1},num[101];
vector<int> v;
void print()
{
	for(int i=0; i<v.size(); i++)
		printf("%d ",v[i]);
	printf("\n");
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		int max_bit=0;
		v.clear();
		scanf("%d",&m);
		pow10[0]=1%m;
		for(int i=1; i<=99; i++)
			pow10[i]=(pow10[i-1]*10)%m;
		memset(d,-1,sizeof(d));
		d[0][0]=0;
		for(int i=1; i<10; i++)
			d[match_num[i]][i%m]=1;
		for(int i=0; i<=n; i++)
			for(int j=0; j<m; j++)
				for(int k=0; k<10; k++)
					if(d[i][j]>0&&d[i+match_num[k]][(j*10+k)%m]<=d[i][j])
						d[i+match_num[k]][(j*10+k)%m]=d[i][j]+1;
		//printf("%d"
		if(d[6][0]==-1)d[6][0]=1;
		for(int i=n; i>=1; i--)
			if(d[i][0]>max_bit)
				max_bit=d[i][0];
		for(int i=1; i<=n; i++)
			if(d[i][0]==max_bit)
				v.push_back(i*10000);
		//print();
		printf("Case %d: ",kase++);
		for(int i=max_bit; i>=1; i--)
		{
			int max_num=0;
			memset(num,0,sizeof(num));
			for(int j=0; j<v.size(); j++)
				if(v[j])
				{
					bool found=false;
					for(int k=9; k>=0&&!found; k--)
						if(match_num[k]<=v[j]/10000)
						{
							int rem_num=((v[j]%10000-k*pow10[i-1])%m+m)%m,rem_mat=v[j]/10000-match_num[k];
							for(int zero=0; zero<i&&rem_mat-6*zero>=0; zero++)
								if(d[rem_mat-6*zero][rem_num]==i-zero-1)
								{
									num[j]=k;
									found=true;
									break;
								}
						}
					v[j]=(v[j]/10000-match_num[num[j]])*10000 + ((v[j]%10000-num[j]*pow10[i-1])%m+m)%m;
					max_num=max(max_num,num[j]);
				}
			printf("%d",max_num);
			for(int i=0; i<v.size(); i++)
				if(num[i]<max_num)
					v[i]=0;
			//print();
		}
		if(!max_bit)
			printf("-1");
		printf("\n");
	}
	return 0;
}
