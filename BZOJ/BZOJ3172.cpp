#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

#define N 1002000

char s[N];
int cnt[N],*x=new int[N],*y=new int[N],n,sa[N];
#define check(a,b) ((a>=n&&b>=n) || (a<n&&b<n&&y[a]==y[b]))
void calc_sa(){
	int m=256;
	for(int i=0; i<n; i++)cnt[x[i]=s[i]]++;
	for(int i=1; i<m; i++)cnt[i]+=cnt[i-1];
	for(int i=n-1; i>=0; i--)sa[--cnt[x[i]]]=i;
	for(int k=1; k<=n; k<<=1){
		int p=0;
		for(int i=n-k; i<n; i++)y[p++]=i;
		for(int i=0; i<n; i++)if(sa[i]>=k)y[p++]=sa[i]-k;
		
		for(int i=0; i<m; i++)cnt[i]=0;
		for(int i=0; i<n; i++)cnt[x[y[i]]]++;
		for(int i=1; i<m; i++)cnt[i]+=cnt[i-1];
		for(int i=n-1; i>=0; i--)sa[--cnt[x[y[i]]]]=y[i];
		
		swap(x,y);
		p=1;
		x[sa[0]]=0;
		for(int i=1; i<n; i++)
			x[sa[i]]=(check(sa[i],sa[i-1]) && check(sa[i]+k,sa[i-1]+k))?p-1:p++;
		m=p;
		if(m>=n)break;
	}
}

int h[N];
void calc_hi(){
	int j,k=0;
	for(int i=0; i<n; i++){
		if(x[i]==0){k=0;h[x[i]]=0;continue;}
		if(k)k--;
		j=sa[x[i]-1];
		while(s[j+k]==s[i+k])k++;
		h[x[i]]=k;
	}
}

int rmq[N][20];
int query(int l,int r){
	int p=(int)log2(r-l+1);
	return min(rmq[l][p],rmq[r-(1<<p)+1][p]);
}

int m,st[210],len[210];
int main(){
	freopen("in.txt","r",stdin);
	scanf("%d",&m);
	for(int i=0; i<m; i++){
		s[n++]=' ';
		st[i]=n;
		scanf("%s",s+n);
		len[i]=strlen(s+n);
		n+=len[i];
	}
	calc_sa();
	calc_hi();
	for(int i=0; i<n; i++)rmq[i][0]=h[i];
	for(int j=1; (1<<j)<=n; j++)
		for(int i=0; i+(1<<j)<=n; i++)
			rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<j-1)][j-1]);
	for(int i=0; i<m; i++){
		int lo=0,hi=x[st[i]],l,r;
		if(h[hi]<len[i]){
			l=hi;
		}else{
			while(lo<hi){
				int mi=(lo+hi)>>1;
				if(query(mi,x[st[i]])>=len[i])hi=mi;
				else lo=mi+1;
			}
			l=lo-1;
		}
		lo=x[st[i]]+1,hi=n-1;
		if(lo>=n || h[lo]<len[i]){
			r=lo-1;
		}else{
			while(lo<hi){
				int mi=(lo+hi-1)/2+1;
				if(query(x[st[i]]+1,mi)>=len[i])lo=mi;
				else hi=mi-1;
			}
			r=lo;
		}
		printf("%d\n",r-l+1);
	}
	return 0;
}

