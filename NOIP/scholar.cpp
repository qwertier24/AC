#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB "scholar"
using namespace std;
char ans[100];
int max_scholar=-1,sum=0;
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		int f_sco,c_sco,paper;
		char t1[10],t2[10],name[30];
		scanf("%s%d%d%s%s%d",name,&f_sco,&c_sco,t1,t2,&paper);
		int cur=0;
		if(f_sco>80&&paper)cur+=8000;
		if(f_sco>85&&c_sco>80)cur+=4000;
		if(f_sco>90)cur+=2000;
		if(f_sco>85&&t2[0]=='Y')cur+=1000;
		if(c_sco>80&&t1[0]=='Y')cur+=850;
		if(cur>max_scholar){
			max_scholar=cur;
			strcpy(ans,name);
		}
		sum+=cur;
	}
	printf("%s\n%d\n%d",ans,max_scholar,sum);
	return 0;
}

