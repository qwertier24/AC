#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
struct Port{
	int next[2];
}port[1010];
int loop_size=0,loop_start=0,loop_before=0;
int steps_m[1010];
int n,mark[1010],m,k,dir[510];
int main(){
	//printf("OK");
	freopen("cruise.in","r",stdin);
	freopen("cruise.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=n; i++)
		scanf("%d%d",&port[i].next[0],&port[i].next[1]);
	for(int i=1; i<=m; i++){
		char t[5];
		scanf("%s",t);
		dir[i]=(t[0]=='R');
	}
	for(int i=1; i<=n; ++i){
		int cur=i;
		for(int j=0; j<m; j++){
			cur=port[cur].next[dir[j+1]];
		}
		steps_m[i]=cur;
		//printf("%d %d\n",i,steps_m[i]);
	}
	int cur=1;
	memset(mark,-1,sizeof(mark));
	for(int i=0; ; ++i){
		if(mark[cur]!=-1){
			loop_size=i-mark[cur];
			loop_start=cur;
			loop_before=mark[cur]-1;
			break;
		}
		mark[cur]=i;
		cur=steps_m[cur];
	}
	//printf("%d %d %d\n",loop_start,loop_size,loop_before);
	if(k<=loop_before)
		for(int i=1; i<=n; i++){
			if(mark[i]==k){
				printf(" %d\n",i);
				break;
			}
		}
	else{
		//printf("!");
		int rem=(k-loop_before+loop_size-1)%loop_size;
		int cur=loop_start;
		for(int i=1; i<=rem; ++i)
			cur=steps_m[cur];
		printf("%d\n",cur);
	}
	return 0;
}
