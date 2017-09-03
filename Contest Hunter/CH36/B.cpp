#include<stdio.h>
#include<cstring>
#include<set>
#include<math.h>
#include<unordered_set>
#define FOR(i,n) for(int i=1; i<=n; i++)
#define REP(i,n) for(int i=0; i<n; i++)
#define CLR(t) memset(t,0,sizeof(t));
#define N 1002000

using namespace std;

int s[N],n;
int cnt[N],*x=new int[N],*y=new int[N],sa[N],m=26;
#define check(a,b) ((a>=n&&b>=n) || (a<n&&b<n&&y[a]==y[b]))
void calc_sa(){
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
int hi[N];
void calc_hi(){
	int j,k=0;
	for(int i=0; i<n; i++){
		if(x[i]==0){k=0;hi[x[i]]=0;continue;}
		if(k)k--;
		j=sa[x[i]-1];
		while(s[j+k]==s[i+k])k++;
		hi[x[i]]=k;
	}
}

int pos[N];
int mark[1010],L,R,tot;
void Mark(int len){
	while(L>0 && hi[L]>=len){
		int p=pos[sa[--L]];
		if(!mark[p])tot++;
		mark[p]=1;
	}
	while(R<n-1 && hi[R+1]>=len){
		int p=pos[sa[++R]];
		if(!mark[p])tot++;
		mark[p]=1;
	}
}

typedef unsigned long long ULL;
const ULL seed=233;

int val[N][21];
int rmq(int l,int r){
	int p=(int)log2(r-l+1);
	return min(val[l][p],val[r-(1<<p)+1][p]);
}

int ans;
int lft[N];
ULL h[1010][1010];
int a[1010],na;
int sn;
char str[1010];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d",&sn);
	REP(i,sn){
		scanf("%s",str);
		int l=strlen(str);
		REP(j,l){
			pos[n]=i;
			s[n++]=str[j]-'a';
		}
		if(i==0){
    		REP(j,l)
    			a[na++]=str[j]-'a';
    		REP(j,l)
    			REP(k,l)
    				h[j][k]=(k==j?s[k]:(h[j][k-1]*seed+str[k]));
		}
		s[n++]=m++;
	}
	n--;
	m--;
	calc_sa();
	calc_hi();
	memset(mark,0,sizeof(mark));
	memset(lft,-1,sizeof(lft));
	int l=tot=0;
	REP(i,n){
		if(!mark[pos[sa[i]]])tot++;
		mark[pos[sa[i]]]++;
		if(tot==sn)while(mark[pos[sa[l]]]>1)--mark[pos[sa[l++]]];
		if(tot==sn)lft[i]=l;
	}
	unordered_set<ULL> st;
	REP(i,n)val[i][0]=hi[i];
	FOR(i,20)
		for(int j=0; j+(1<<i)<=n; j++)
			val[j][i]=min(val[j][i-1],val[j+(1<<i-1)][i-1]);
	REP(i,na){
	  	for(int j=na-i; j; j--){
	  		int l,r;
	  		if(x[i]+1>=n || hi[x[i]+1]<j)l=x[i];
			else{
				l=x[i]+1,r=n-1;
		  		while(l<r){
		  			int mi=(l+r+1)>>1;
		  			if(rmq(x[i]+1,mi)>=j)l=mi;
		  			else r=mi-1;
		  		}
		  	}
	  		if(lft[l]!=-1 && rmq(lft[l]+1,l)>=j){
	  			if(!st.insert(h[i][i+j-1]).second)
	  				break;
	  			else
	  				ans++;
	  		}
	  			
	  	}
	}
	printf("%d",ans);
	return 0;
}
