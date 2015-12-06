#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB "fpot"
using namespace std;
int n,d,qmin[1000010],qmax[1000010],fmin=0,fmax=0,rmin=-1,rmax=-1,max_h[1000010],min_h[1000010],x[1000010],y[1000010];
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	memset(max_h,-1,sizeof(max_h));
	memset(min_h,-1,sizeof(min_h));
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; i++){
		scanf("%d%d",&x[i],&y[i]);
		if(max_h[x[i]]==-1){
			max_h[x[i]]=y[i];
			min_h[x[i]]=y[i];
		}else{
			max_h[x[i]]=max(max_h[x[i]],y[i]);
			min_h[x[i]]=min(min_h[x[i]],y[i]);
		}
	}
	int ans=1<<30,l=1;
	bool found=false;
	for(int i=1; i<=1000000; i++){
		if(max_h[i]==-1)continue;
		while(fmin<=rmin&&min_h[qmin[rmin]]>=min_h[i])
			rmin--;
		qmin[++rmin]=i;
		while(fmax<=rmax&&max_h[qmax[rmax]]<=max_h[i])
			rmax--;
		qmax[++rmax]=i;
		//printf("%d %d %d\n",i,qmax[fmax],qmin[fmin]);
		if(max_h[qmax[fmax]]-min_h[qmin[fmin]]>=d)found=true;
		if(found){
			while(fmax<=rmax&&fmin<=rmin&&max_h[qmax[fmax]]-min_h[qmin[fmin]]>=d&&l<=i){
				l++;
				if(qmax[fmax]<l)fmax++;
				if(qmin[fmin]<l)fmin++;
			}
			l--;
			//printf("%d %d\n",i,l);
			if(qmax[fmax-1]==l)fmax--;
			if(qmin[fmin-1]==l)fmin--;
			ans=min(ans,i-l);
		}
	}
	if(found)printf("%d",ans);
	else printf("-1");
	return 0;
}

