#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#include <cmath>
#define PROB "freefaller"
#define dbg if(0)
#define eps 1e-5
using namespace std;
double H,p,v,w,h,l,r,t1,t2;
int n,ans=0;
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%lf%lf%lf%lf%lf%d",&H,&p,&v,&w,&h,&n);
	t1=sqrt((H)*2/10),t2=sqrt((H-h)*2/10);
dbg	printf("%f\n",t1);
	l=p-v*t1,r=p-v*t2+w;
dbg	printf("%f %f\n",l,r);
	for(int i=0; i<n; i++){
		double p_ball=i;
dbg		printf("%d %f\n",i,p_ball);
		if(p_ball>=l-eps&&p_ball<=r+eps)
			ans++;
	}
	printf("%d",ans);
	return 0;
}

