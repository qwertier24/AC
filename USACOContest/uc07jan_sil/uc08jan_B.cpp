#include<stdio.h>
#include<algorithm>
#include<cstring>
#define For(i,b,e) for(int i=b; i<=e; i++)
#define resting 0
using namespace std;
int d[2][510][2]={0},m,n;
int main(){
	//freopen("prob.in","r",stdin);
    scanf("%d%d",&n,&m);
    For(i,1,n)
    {
		int D;
		scanf("%d",&D);
		int (*last)[2]=d[(i+1)%2],(*cur)[2]=d[i%2];
		memset(cur,0,sizeof(cur));
		For(j,0,m){
			if(j){
				cur[j][!resting]=last[j-1][!resting]+D;
				if(j==1)
					cur[j][!resting]=max(cur[j][!resting],last[j-1][resting]+D);
			}
			else
				cur[j][resting]=last[j][resting];
			cur[j][resting]=max(cur[j][resting],last[j+1][resting]);
			cur[j][resting]=max(cur[j][resting],last[j+1][!resting]);
		}
    }
    printf("%d\n",max(d[n%2][0][0],d[n%2][0][1]));
    return 0;
}
